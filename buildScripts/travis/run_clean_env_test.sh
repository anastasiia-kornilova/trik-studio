#!/bin/bash
set -euxo pipefail

curl --output test_qrs.7z "https://dl.trikset.com/edu/.solutions20200701/test.7z"
7z x test_qrs.7z

./installer/install_studio_mac.sh ./installer/
curl --output installer.run "https://dl.trikset.com/ts/fresh/installer/trik-studio-installer-mac-master.dmg"
env QT_QPA_PLATFORM=minimal python3.7 ./buildScripts/tests/fieldstest.py "$HOME/TRIKStudio/bin/2D-model" testing
