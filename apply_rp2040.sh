#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

copy_firmware() {
    cp crkbd_rev1_customrp2040.uf2 /media/RPI-RP2
}
make crkbd:customrp2040
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
