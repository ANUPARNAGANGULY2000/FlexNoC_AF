FILE(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
add_executable(flexnoc_unit_tests ${sources} ${headers})

target_link_libraries(flexnoc_unit_tests PRIVATE FlexNoC_core GTest::gtest GTest::gtest_main fmt::fmt antlr4_static)

enable_testing()
include(GoogleTest)
gtest_discover_tests(flexnoc_unit_tests TEST_PREFIX new:)
