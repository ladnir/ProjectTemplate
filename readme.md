# Project template

This is an example project for libOTe applications. There are the following cpp components

 - projTemp library: this is the main library where the core code should go
 - tests library: this is where all the tests should go
 - frontent: this is an executable. Unit tests and the main application can be launched from here.


## cmake 

There is a `cmake` folder that contains most of the cmake code. This includes the ability to automaticly fetch dependancies. The structure is:

 - `Config.cmake.in`:  This is what cmake will "install" so that others can find your project. It gets converted into a file call `<install-prefix>/lib/cmake/projTempConfig.cmake`. When someone types `find_package(projTemp)`, this file is what cmake looks for. It has a few tasks. First it must define the targets of this project, e.g. `libprojTemp.a` on linux which will be referenced as the target `pt::projTemp` in cmake. This file must also find all dependancies of the targets which it defines. We handle finding the dependancies in the next cmake file.
 
 - `findDependancies.cmake`: This file is where we place all the logic for finding dependancies. This sample project depends on `libOTe` and `sparsehash`. See the file for details. In addition, there is some logic here that will automaticly download the dependancies. The actual code that downloads and build the dependancies is located in `thirdparty/getXXX.cmake` where `XXX` is the dependancy name. 

 Since when we install this project, the downstream project (via `find_package(projTemp)`) also need to find our dependancies, this file will be installed next to `projTempConfig.cmake`. So this file can be called in two contexts, one where is lives in `<src-tree>/cmake` and one where it lives at `<install-prefix>/lib/cmake/`. 

 - `buildOptions.cmake`: here we define any compile time options. In this project we have one `PROJTEMP_ENABLE_X`. This gets define in cmake and then propegated to the cpp files via the `projTemp/config.g.in` file. Note that and build options which downstream users of your library should have access to as a cmake variable should be added to `Config.cmake.in`. See that file for an example.

 - `install.cmake`: here we define all the install steps for our library. Note that  `thirdparty/getXXX.cmake` handles install any dependancies that we fetched. 

 - `preamble.cmake`: here we define various project wide setting. 

 - `projTempConfig.cmake`: having this file allows users of the library find and use our source tree when they call `find_package(projTemp)`. This enables users of our library to not install our project and instead just use the source tree.


As mentioned, `thirdparty/getXXX.cmake` is used to automaticly download and build dependancies. There are a few things worth mentioning:
 - first is that dependancies are not fetched by default when using `cmake`. You can explicitly ask to fetch a dependancy `XXX` with `-DFETCH_XXX=ON`. Alternatively, you can have the cmake only fetch the dependancy if its not already installed with `-DFETCH_AUTO=ON`. The latter is convinent but in some situations might find the wrong version so use with care.

 - Dependancies are downloaded into the `thirdparty/` directory and then installed to `<src-tree>/out/install/<platform>/`. This is where cmake will look for the dependancies. When the user calls `cmake install`, we also install the dependancies to their specified locations. This "user install" case is handled at the end of `thirdparty/getXXX.cmake` file.


