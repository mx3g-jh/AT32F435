# at32f413_at-start-f413
## Introduction
CMake ARM gnu toolchain wrappers for AT32F413 SDK from [Artery Tek](https://www.arterychip.com/en/product/AT32F413.jsp) (in their words the Board Support Package (BSP))

## Usage
`git clone https://github.com/jools-uk/at32f413_at-start-f413.git`

`cd at32f413_at-start-f413`

This next command pulls the SDK zip file from Artery Tek website and unzips in the working folder:

`./fetch_bsp.sh`

This step also makes a correction to 2 of their example files which do not use an GNU embedded gcc wrapper for `__align(4)`

`cmake .`

`make`

Now in ./output you'll have all the binary files for all the examples.

## Comments
The CMakeList is one single file rather than a top level file and then sub projects for each example. This is to avoid having to create a mirrored directory structure of the BSP. Therefore the CMakeList has a foreach to setup the binary outputs for each.

To build only certain examples, comment out the entries in the `set(EXAMPLES ...) list`. eg:


The library objects are built once.

The middleware objects are built once.

For any projects using USB middleware it's a litte more complicated - because the middleware needs to be build with the specific configuration of the example. So for these the middleware is built as part of the example sources, not as a library

## Notes
* Base CMakeList.txt file for GNU embedded ARM Cortex builds
* https://gist.github.com/elmot/3b4f0e9f8b23864fdf8bb509c329d051
* 
