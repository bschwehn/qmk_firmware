#!/usr/bin/env bash
set -e
root=/home/ben/dev/qmk/qmk_upstream/qmk_firmware/keyboards/moonlander
maproot=$root/keymaps/
make moonlander:reduced
wally-cli ./moonlander_reduced.bin
cd $maproot
git commit -am "automatic checkin: updating ml keymap"
git push
