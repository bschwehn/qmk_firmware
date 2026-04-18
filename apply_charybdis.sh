#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

name=bastardkb_charybdis_4x6_elitec_custom26_elite_pi.uf2
copy_firmware() {
    cp $name /media/RPI-RP2
}
#make crkbd:customrp2040
qmk compile -kb bastardkb/charybdis/4x6/elitec -km custom26 -e CONVERT_TO=elite_pi
#exit
cp $name "../firmware_backups/$name.$(date -Iseconds)"
spacefm&
until copy_firmware; do
    if [ $? -eq 5 ]; then
        echo "Error was 5"
    else
        echo "Error was not 5"
    fi
    sleep 1
    sync
    # potentially, other code follows...
done
echo "second side"
sleep 10
spacefm&
until copy_firmware; do
    if [ $? -eq 5 ]; then
        echo "Error was 5"
    else
        echo "Error was not 5"
    fi
    sleep 1
    sync
    # potentially, other code follows...
done

sleep 2
ls ../firmware_backups | grep charybdis
