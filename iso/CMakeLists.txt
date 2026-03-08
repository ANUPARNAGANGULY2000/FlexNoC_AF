add_executable(flexnoc main.cpp)

target_include_directories(flexnoc
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include      # your dot_compiler.h, etc
	${CMAKE_SOURCE_DIR}/lang       # DOTLexer.h, DOTParser.h, etc.
	${CMAKE_SOURCE_DIR}/IncludeModel #header files includes in model
	${CMAKE_SOURCE_DIR}/test
	${CMAKE_SOURCE_DIR}/auto_generate
)

target_link_libraries(flexnoc PRIVATE FlexNoC_core fmt::fmt antlr4_static Boost::graph)
