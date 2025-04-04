add_executable(dot_iso main.cpp)
target_link_libraries(dot_iso PRIVATE dot_dsl fmt::fmt antlr4_static Boost::graph)