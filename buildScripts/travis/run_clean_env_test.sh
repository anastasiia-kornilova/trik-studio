#!/bin/bash
set -euxo pipefail

curl --output installer.sh "https://dl.trikset.com/ts/fresh/installer/trik-studio-installer-linux-master.run"
curl --output test_qrs.7z "https://dl.trikset.com/edu/.solutions20200701/test.7z"
7z x test_qrs.7z

