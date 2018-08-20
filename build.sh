#!/bin/bash
cd "$(dirname -- "$(readlink -fn -- "${0}")")"

sudo apt install clang cmake ninja-build libvulkan-dev libxcb-keysyms1-dev qt5-default libqt5svg5-dev libxcb-ewmh-dev

# Used commits:
# https://github.com/LunarG/VulkanTools/commit/d878e6a
# https://github.com/KhronosGroup/Vulkan-Headers/commit/c4e056d
# https://github.com/KhronosGroup/Vulkan-Loader/commit/1f9a545
# https://github.com/KhronosGroup/Vulkan-ValidationLayers/commit/a055501

rm -rf Vulkan-Tools
rm -rf Vulkan-Headers
rm -rf Vulkan-Loader
rm -rf Vulkan-ValidationLayers

git clone --depth 1 https://github.com/LunarG/VulkanTools Vulkan-Tools --recursive
git clone --depth 1 https://github.com/KhronosGroup/Vulkan-Headers
git clone --depth 1 https://github.com/KhronosGroup/Vulkan-Loader
git clone --depth 1 https://github.com/KhronosGroup/Vulkan-ValidationLayers

rm -rf Vulkan-Tools/.git
rm -rf Vulkan-Headers/.git
rm -rf Vulkan-Loader/.git
rm -rf Vulkan-ValidationLayers/.git

# Dafuq?
# https://github.com/LunarG/VulkanTools/blob/d878e6a/cmake/FindVulkanHeaders.cmake#L55
mkdir -p ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan
cp -r ~/Desktop/vulkan_tracer/Vulkan-Headers/registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/

cd Vulkan-Tools
mkdir build
cd build
CC=clang CXX=clang++ cmake -G Ninja -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=Debug \
  -DVULKAN_HEADERS_INSTALL_DIR=~/Desktop/vulkan_tracer/Vulkan-Headers                    \
  -DVULKAN_LOADER_INSTALL_DIR=~/Desktop/vulkan_tracer/Vulkan-Loader                      \
  -DVULKAN_VALIDATIONLAYERS_INSTALL_DIR=~/Desktop/vulkan_tracer/Vulkan-ValidationLayers  \
  -DBUILD_VKTRACE=ON        \
  -DBUILD_LOADER=OFF        \
  -DBUILD_TESTS=OFF         \
  -DBUILD_LAYERS=OFF        \
  -DBUILD_LAYERSVT=OFF      \
  -DBUILD_VLF=OFF           \
  -DBUILD_VKTRACEVIEWER=ON  \
  -DBUILD_DEMOS=OFF         \
  -DBUILD_VKJSON=OFF        \
  -DBUILD_VIA=OFF           \
  -DBUILD_VKTRACE_LAYER=ON  \
  -DBUILD_VKTRACE_REPLAY=ON \
  ..

mkdir layersvt

python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_enum_string_helper.h
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_safe_struct.h
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_safe_struct.cpp
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_object_types.h
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_layer_dispatch_table.h
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_dispatch_table_helper.h
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_extension_helper.h
python3 ~/Desktop/vulkan_tracer/Vulkan-ValidationLayers/scripts/lvl_genvk.py -registry ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry/vk.xml -scripts ~/Desktop/vulkan_tracer/Vulkan-Headers/share/vulkan/registry vk_typemap_helper.h

ninja -v
