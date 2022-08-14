#!/bin/bash

wget https://www.arterychip.com/download/BSP/AT32F413_Firmware_Library_EN.zip
unzip AT32F413_Firmware_Library_EN.zip -d AT32F413_Firmware_Library
rm AT32F413_Firmware_Library_EN.zip
find AT32F413_Firmware_Library/project/at_start_f413/examples -name *.c -exec sed -i 's/__align(4)/ALIGNED_HEAD/g' {} \;
