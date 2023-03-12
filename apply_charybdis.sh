#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

copy_firmware() {
    cp bastardkb_charybdis_4x6_v2_splinky_custom.uf2 /media/RPI-RP2
}
#make crkbd:customrp2040
qmk compile -kb bastardkb/charybdis/4x6/v2/splinky -km custom
until copy_firmware; do
    if [ $? -eq 5 ]; then
        echo "Error was 5"
    else
        echo "Error was not 5"
    fi
    sleep 1
    # potentially, other code follows...
done
echo "second side"
sleep 10
until copy_firmware; do
    if [ $? -eq 5 ]; then
        echo "Error was 5"
    else
        echo "Error was not 5"
    fi
    sleep 1
    # potentially, other code follows...
done
