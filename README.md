# AT32f435
## Introduction
CMake ARM gnu toolchain wrappers for AT32F435 SDK from [Artery Tek](https://www.arterychip.com/download/BSP/AT32F435_437_Firmware_Library_V2.1.2.zip) (in their words the Board Support Package (BSP))

## Usage
`git clone git@github.com:mx3g-jh/AT32F435.git`

`cd AT32F435`

This next command pulls the SDK zip file from Artery Tek website and unzips in the working folder:


`mkdir build`

`cd build`

`cmake ..`

`make -j12`

`make jlink-flash`

Now in ./build/output you'll have all the binary files.

## Comments
The CMakeList is one single file rather than a top level file and then sub projects for each example. This is to avoid having to create a mirrored directory structure of the BSP. Therefore the CMakeList has a foreach to setup the binary outputs for each.

## Notes
* Base CMakeList.txt file for GNU embedded ARM Cortex builds
