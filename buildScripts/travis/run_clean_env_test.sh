#!/bin/bash
set -euxo pipefail

curl --output test_qrs.7z "https://dl.trikset.com/edu/.solutions20200701/test.7z"
7z x test_qrs.7z

INSTALLER_POSTFIX=""
case $TRAVIS_OS_NAME in
  osx)
    INSTALLER_POSTFIX="mac"
    ;;
  linux)
    INSTALLER_POSTFIX="linux"
    ;;
  *) exit 1 ;;
esac

curl --output installer.run "https://dl.trikset.com/ts/fresh/installer/trik-studio-installer-${INSTALLER_POSTFIX}-master.run"
chmod +x installer.run
./installer.run --platform minimal --script ./installer/trik_studio_installscript.qs
env QT_QPA_PLATFORM=minimal python3.7 ./buildScripts/tests/fieldstest.py "$HOME/TRIKStudio/bin/2D-model" testing
