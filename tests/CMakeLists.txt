

#############################################
#               Build PROJTEMP_Tests            #
#############################################

# define all cpp files
set(SRCS
	"foo_Tests.cpp"
	"UnitTests.cpp"
	)

#define the test library.
add_library(projTemp_Tests ${SRCS})

# link the tests with the main library.
target_link_libraries(projTemp_Tests projTemp)
