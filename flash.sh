# !/bin/bash

JlinkScript="./flash.jlink"
rm $JlinkScript
# if [ -f $JlinkScript ]; then
#     rm $JlinkScript
# fi
touch $JlinkScript
echo erase  > $JlinkScript
echo h >> $JlinkScript
echo loadfile $1 >> $JlinkScript
echo r >> $JlinkScript
echo g >> $JlinkScript
echo exit >> $JlinkScript

JLinkExe -device $2 -autoconnect 1 -if SWD -speed 4000 -CommanderScript $JlinkScript
