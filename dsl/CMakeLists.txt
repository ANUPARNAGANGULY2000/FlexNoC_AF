cmake_minimum_required(VERSION 3.13)
project(dot_dsl)
#provide cmake option to build unit tests
option(BUILD_TESTING "build unit tests" ON)
message(STATUS "BUILD UNIT TESTS: ${BUILD_TESTING}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
include(GNUInstallDirs)

option(COVERAGE "enable coverage with gcov" OFF)
if(COVERAGE)
    include(Coverage) #added to enable coverage with gcov
endif()

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

if(NOT EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    #bootstrap installation to use conan profile (supply from cmdline with -DCONAN_PROFILE)
    if(NOT DEFINED CONAN_PROFILE)
        set(CONAN_PROFILE "") # use default profile
    endif()

    message(STATUS "Configuring conan...")
    if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                        "${CMAKE_BINARY_DIR}/conan.cmake"
                        TLS_VERIFY ON)
    endif()

    include(${CMAKE_BINARY_DIR}/conan.cmake)

    conan_cmake_run(
        CONANFILE conanfile.py
        PROFILE_AUTO ALL #if not defined in profile, infer from cmake settings
        BUILD missing
        BUILD outdated)
    
endif()

set(CONAN_CMAKE_SILENT_OUTPUT TRUE)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS TARGETS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT DEFINED CMAKE_CXX_STANDARD)
    if(NOT DEFINED CONAN_SETTINGS_COMPILER_CPPSTD)
        set(CMAKE_CXX_STANDARD 20)
    else()
        set(CMAKE_CXX_STANDARD ${CONAN_SETTINGS_COMPILER_CPPSTD})
    endif()
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()
    
    
message(STATUS "CMAKE STANDARD: ${CMAKE_CXX_STANDARD}")
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

find_package(fmt REQUIRED)
find_package(antlr4-runtime REQUIRED)
find_package(Boost REQUIRED COMPONENTS graph) # only req'd if using boost graph

set(LANG_SOURCE_DIR ${CMAKE_SOURCE_DIR}/lang)
set(ANTLR_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/lang/.antlr_generated)
set(ANTLR_JAR ${LANG_SOURCE_DIR}/antlr-4.13.2-complete.jar)

file(MAKE_DIRECTORY ${ANTLR_OUTPUT_DIR})

add_custom_command(
    OUTPUT ${ANTLR_OUTPUT_DIR}/DOTLexer.cpp ${ANTLR_OUTPUT_DIR}/DOTParser.cpp ${ANTLR_OUTPUT_DIR}/DOTBaseListener.cpp ${ANTLR_OUTPUT_DIR}/DOTListener.cpp ${ANTLR_OUTPUT_DIR}/DOTVisitor.cpp ${ANTLR_OUTPUT_DIR}/DOTLexer.tokens ${ANTLR_OUTPUT_DIR}/DOTLexer.interp
    COMMAND java -jar ${ANTLR_JAR} -Dlanguage=Cpp -visitor -o ${ANTLR_OUTPUT_DIR} ${LANG_SOURCE_DIR}/DOT.g4
    DEPENDS ${CMAKE_SOURCE_DIR}/lang/DOT.g4
    COMMENT "Running ANTLR on DOT.g4"
)

set(sources
    src/Node.cpp
    src/Injector.cpp
    src/dot_compiler.cpp
    src/node_factory.cpp
    ${ANTLR_OUTPUT_DIR}/DOTLexer.cpp
    ${ANTLR_OUTPUT_DIR}/DOTParser.cpp
    ${ANTLR_OUTPUT_DIR}/DOTBaseListener.cpp
    )

add_library(dot_dsl ${sources})

target_include_directories(dot_dsl PUBLIC include ${ANTLR_OUTPUT_DIR})
set_target_properties(dot_dsl PROPERTIES
    VERSION ${CONAN_PACKAGE_VERSION})

target_link_libraries(dot_dsl PRIVATE fmt::fmt antlr4_static Boost::graph)

install(TARGETS dot_dsl TYPE LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# use CCACHE (caches compiler info to speedup build)
option(USE_CCACHE "Use a fast C/C++ compiler cache" ON)
if(USE_CCACHE)
    if(NOT DEFINED CCACHE_EXECUTABLE)
        find_program(CCACHE_EXECUTABLE ccache
                PATHS /usr/intel/pkgs/ccache/3.7.9/bin /usr/intel/pkgs/ccache/3.7.4/bin /usr/bin
                NO_DEFAULT_PATH)
    endif()
    if(CCACHE_EXECUTABLE)
        add_definitions(-DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_EXECUTABLE}")
    endif()
endif()

# link and compile flags to be passed to the compiler

if (MSVC)
add_compile_options(/GS- /MP)
else()
add_link_options(-Wl,--fatal-warnings)
add_compile_options(-Werror -Wall -Wextra -Wvla -Wno-unused-parameter)
endif()

if(BUILD_TESTING)
    enable_testing()
    find_package(GTest REQUIRED)
    include(GoogleTest)
    add_subdirectory(test)
endif()

add_subdirectory(iso)