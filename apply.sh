#!/usr/bin/env bash
set -e
root=/home/ben/dev/qmk/qmk_upstream/qmk_firmware/keyboards/moonlander
maproot=$root/keymaps/
ziproot=/home/ben/dev/qmk/oryx/
cd $ziproot
unzip -oj moonlander.zip -d moonlander
rsync -a moonlander/ $root/keymaps/oryx
sed -i '/VERSION/d' $maproot/custom/config.h
sed -n '/VERSION/p' $maproot/oryx/config.h >> $maproot/custom/config.h

awk '/# custom/,EOF' $maproot/custom/rules.mk > $maproot/custom/custom.m
cp $maproot/oryx/rules.mk $maproot/custom/rules.mk
cat $maproot/custom/custom.m >> $maproot/custom/rules.mk

awk '/\/\/ custom/,EOF' $maproot/custom/config.h > $maproot/custom/custom.h
cp $maproot/oryx/config.h $maproot/custom/config.h
cat $maproot/custom/custom.h >> $maproot/custom/config.h

awk '/\/\/ custom/,EOF' $maproot/custom/keymap.c > $maproot/custom/custom.c
cp $maproot/oryx/keymap.c $maproot/custom/keymap.c
cat $maproot/custom/custom.c >> $maproot/custom/keymap.c
sed -zi 's/TT(6)/KC_LEAD/' $maproot/custom/keymap.c
sed -zi 's/OSL(3)/LLOCK/' $maproot/custom/keymap.c
sed -i '/process_record_user/a if (!custom_record_user(keycode, record))\ { return false; }' $maproot/custom/keymap.c
sed -i '/version.h/a #include "keymap_custom.h"' $maproot/custom/keymap.c
sed -i '/keymap_custom/p;/keymap_uk/p;/keymap_/d' $maproot/custom/keymap.c
sed -i '/g_suspend/d' $maproot/custom/keymap.c

qmk compile
wally-cli ../qmk_upstream/qmk_firmware/moonlander_custom.bin
cd $maproot
rsync -av ~/dev/qmk/qmk_cantor/keyboards/cantor/keymaps/ ~/dev/qmk/qmk_upstream/qmk_firmware/keyboards/cantor/keymaps
git commit -am "automatic merge from configurator"
git push
