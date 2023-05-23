#!/bin/bash

wget https://www.arterychip.com/download/BSP/AT32F435_437_Firmware_Library_V2.1.2.zip
unzip AT32F435_437_Firmware_Library_V2.1.2.zip -d AT32F435_Firmware_Library
rm AT32F435_437_Firmware_Library_V2.1.2.zip
find AT32F435_Firmware_Library/project/at_start_f435/examples -name *.c -exec sed -i 's/__align(4)/ALIGNED_HEAD/g' {} \;
