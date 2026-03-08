cmake_minimum_required(VERSION 3.15)
project(FlexNoC LANGUAGES CXX)

# ─── Force C++17 for all targets ──────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# ─── Include the Conan‑generated toolchain ────────────────────────────────────
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)   # Injects include paths, libs, compile flags

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

find_package(fmt REQUIRED)
find_package(GTest REQUIRED)
find_package(antlr4-runtime REQUIRED)
find_package(Boost REQUIRED COMPONENTS graph)


enable_testing()


# ─── Define the dot_dsl library ──────────────────────────────────────────────
add_library(FlexNoC_core
    src/dot_compiler.cpp         # <-- Replace with actual .cpp files
    lang/DOTLexer.cpp
    lang/DOTParser.cpp
    src/node_factory.cpp
    src/Injector.cpp
    src/Queue.cpp
    src/Server.cpp
    src/Arbiter.cpp
    src/RoundRobin.cpp
    src/Priority.cpp
    src/Junction.cpp 
    src/Node.cpp
    src/Split.cpp
    src/defines.cpp
    src/Hybrid.cpp
    src/TypeCheckVisitor.cpp
    src/MakeConnection.cpp
    SrcModel/SingleQueue.cpp
    SrcModel/RoundRobinModel.cpp
    SrcModel/PriorityModel.cpp
    SrcModel/setNetwork.cpp
    SrcModel/setNetworkPrimitives.cpp
    SrcModel/UpdateNodeQueue.cpp
    SrcModel/updateProcess.cpp
    SrcModel/WaitingTime.cpp
    SrcModel/getUtils.cpp
    SrcModel/findQueue.cpp
    src/Sink.cpp
    auto_generate/SplitProbabilityGenerate.cpp

    # Add other source files if needed
)

target_include_directories(FlexNoC_core PUBLIC
    ${CMAKE_SOURCE_DIR}/include
     ${CMAKE_SOURCE_DIR}/lang
     ${CMAKE_SOURCE_DIR}/IncludeModel
     ${CMAKE_SOURCE_DIR}/auto_generate
     
)

target_link_libraries(FlexNoC_core PUBLIC
    antlr4_static
    fmt::fmt
    Boost::graph
)


# ─── Add subdirectories ──────────────────────────────────────
add_subdirectory(iso)
add_subdirectory(test)

# ─── Your existing test target setup ─────────────────────────────────────────
#FILE(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#FILE(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
#add_executable(dot_dsl_unit_tests ${sources} ${headers})

#target_link_libraries(dot_dsl_unit_tests
#   PRIVATE
#      GTest::GTest
#      dot_dsl
#      fmt::fmt
#      antlr4_static
#)

#enable_testing()
#include(GoogleTest)
#gtest_discover_tests(dot_dsl_unit_tests TEST_PREFIX new:)

