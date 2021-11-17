cmake_minimum_required (VERSION 3.15)

project(projTemp VERSION 0.0.1)


# sets some variables
include(cmake/preamble.cmake)

# sets build option
include(cmake/buildOptions.cmake)

# find all the dependancies.
include(cmake/findDependancies.cmake)

# build projTemp
add_subdirectory(projTemp)

# build the tests.
add_subdirectory(tests)

# link the executable.
add_subdirectory(frontend)

# setup the install
include(cmake/install.cmake)