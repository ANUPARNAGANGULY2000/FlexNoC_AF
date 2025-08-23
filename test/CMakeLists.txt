FILE(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
add_executable(dot_dsl_unit_tests ${sources} ${headers})

target_link_libraries(dot_dsl_unit_tests PRIVATE GTest::GTest dot_dsl fmt::fmt antlr4_static)

enable_testing()
include(GoogleTest)
gtest_discover_tests(dot_dsl_unit_tests TEST_PREFIX new:)
