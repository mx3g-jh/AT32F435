# at32f413_at-start-f413
## Introduction
CMake ARM gnu toolchain wrappers for AT32F SDK from Artery Tek (their BSP)

## Usage
`git clone`
`cd at32f413`
This next pulls the SDK zip file from Artery Tek website and unzip in the working folder:
`./fetch_bsp.sh`
This pulls the SDK zip file from Artery Tek website and unzip in the working folder
This step also makes a correction to 2 of their example files which do not use an GNU embedded gcc wrapper for __align(4)
`cmake .`
`make`

Now in ./output you'll have all the binary files


## Notes
* Base CMakeList.txt file for GNU embedded ARM Cortex builds
* https://gist.github.com/elmot/3b4f0e9f8b23864fdf8bb509c329d051
* 
