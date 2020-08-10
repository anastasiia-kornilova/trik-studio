#!/bin/bash
set -euxo pipefail

curl --output test_qrs.7z "https://dl.trikset.com/edu/.solutions20200701/test.7z"
7z x test_qrs.7z

INSTALLER_URL=""
case $TRAVIS_OS_NAME in
  osx)
    INSTALLER_URL="https://dl.trikset.com/ts/fresh/installer/trik-studio-installer-mac-master.dmg"
    ;;
  linux)
    INSTALLER_URL="https://dl.trikset.com/ts/fresh/installer/trik-studio-installer-linux-master.run"
    ;;
  *) exit 1 ;;
esac

curl --output installer.dmg "${INSTALLER_URL}"
sudo hdiutil attach installer.dmg
ls -la /Volumes/
sudo /Volumes/trik-studio-offline-mac-installer-7a6802 --platform minimal --script ./installer/trik_studio_installscript.qs
sudo installer -package /Volumes/installer/installer.pkg -target /
./installer.dmg --platform minimal --script ./installer/trik_studio_installscript.qs
env QT_QPA_PLATFORM=minimal python3.7 ./buildScripts/tests/fieldstest.py "$HOME/TRIKStudio/bin/2D-model" testing
