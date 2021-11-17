
# generate the config file
configure_file(config.h.in "config.h" )

# list all cpp files
set(SRCS
    "foo.cpp"
    #"otherFiles.cpp"
    )
    
# define the main library.
add_library(projTemp STATIC ${SRCS})

# define the includes for this project. This is the binary dir (for config.h)
# and then our parent dir for all others. We dont want these to be part of the 
# install interface since these files are local to our build tree. Install is 
# handled differently. 
target_include_directories(projTemp PUBLIC 
                    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/..>
                    $<INSTALL_INTERFACE:>) 
target_include_directories(projTemp PUBLIC 
                    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
                    $<INSTALL_INTERFACE:>) 


# link dependancies
target_link_libraries(projTemp oc::libOTe sparsehash)

# set any other operties like cpp version
if(APPLE)
    target_compile_options(projTemp PUBLIC
        "-std=c++17"
    )
else()
    set_target_properties(projTemp
        PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
    )
endif()

if(MSVC)
    target_compile_definitions(projTemp PUBLIC "_ENABLE_EXTENDED_ALIGNED_STORAGE")
else()
    target_compile_options(projTemp PUBLIC -mavx)
endif()
