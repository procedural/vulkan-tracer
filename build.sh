#!/bin/bash
cd "$(dirname -- "$(readlink -fn -- "${0}")")"

# sudo apt install clang cmake ninja-build libvulkan-dev libxcb-keysyms1-dev qt5-default libqt5svg5-dev
# ./update_external_sources.sh
# mkdir build
# cd build
# CC=clang CXX=clang++ cmake -G Ninja -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=Debug -DBUILD_VKTRACE=ON -DBUILD_LOADER=OFF -DBUILD_TESTS=OFF -DBUILD_LAYERS=OFF -DBUILD_LAYERSVT=OFF -DBUILD_VKTRACEVIEWER=ON -DBUILD_DEMOS=OFF -DBUILD_VKJSON=OFF -DBUILD_VIA=OFF -DBUILD_VKTRACE_LAYER=ON -DBUILD_VKTRACE_REPLAY=ON ..
# mkdir layersvt
# ninja -v
