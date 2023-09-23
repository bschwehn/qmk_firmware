#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

make cantor:custom
make cantor:custom:flash

cp cantor_custom.bin "../firmware_backups/cantor.custom.bin.$(date -Iseconds)"
ls ../firmware_backups
