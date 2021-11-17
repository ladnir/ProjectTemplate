
# glob all the cpp files
file(GLOB_RECURSE SRCS *.cpp)

# define the main executable.
add_executable(frontend  ${SRCS})

# link the tests. This will also link all the other dependancies.
target_link_libraries(frontend projTemp_Tests)

# set any properties/
if(APPLE)
    target_compile_options(frontend PUBLIC
        "-std=c++17"
    )
else()
    set_target_properties(frontend
        PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
    )
endif()
