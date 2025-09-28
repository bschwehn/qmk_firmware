#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

make cantor:custom25
make cantor:custom25:flash

cp cantor_custom.bin "../firmware_backups/cantor.custom.bin.$(date -Iseconds)"
ls ../firmware_backups
