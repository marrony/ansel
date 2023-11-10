#!/bin/bash

# Exit in case of error
set -e -o pipefail -x
trap 'echo "${BASH_SOURCE[0]}{${FUNCNAME[0]}}:${LINENO}: Error: command \`${BASH_COMMAND}\` failed with exit code $?"' ERR

# Define application name
PROGN=ansel

# Go to directory of script
scriptDir=$(dirname "$0")

buildDir="${scriptDir}/../../build/macosx"

cd "$buildDir/"

DMG="$PROGN-${VERSION:-nightly-$(uname -m)}"

test -f "$DMG.dmg" && rm "$DMG.dmg"

create-dmg --volname "$PROGN" \
  --icon-size 100 \
  --window-pos 400 100 \
  --window-size 885 330 \
  --icon "$PROGN.app" 100 100 \
  --hide-extension "$PROGN.app" \
  --app-drop-link 375 100 \
  --codesign ${CODECERT:-"-null-"} \
  "$DMG.dmg" package/

