add_executable(dot_iso main.cpp)

target_include_directories(dot_iso
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include      # your dot_compiler.h, etc
	${CMAKE_SOURCE_DIR}/lang       # DOTLexer.h, DOTParser.h, etc.
	${CMAKE_SOURCE_DIR}/src		#for read_Network, waiting time
)

target_link_libraries(dot_iso PRIVATE dot_dsl fmt::fmt antlr4_static Boost::graph)
