#!/usr/bin/env bash
set -euo pipefail

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target cinevault_server --parallel
./build/cinevault_server "${CINEVAULT_CONFIG:-config/config.example.json}"
