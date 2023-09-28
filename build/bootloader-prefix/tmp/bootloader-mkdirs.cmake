# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/molnarm/Downloads/esp-idf-v5.1/components/bootloader/subproject"
  "/home/molnarm/esp-workspace/project/build/bootloader"
  "/home/molnarm/esp-workspace/project/build/bootloader-prefix"
  "/home/molnarm/esp-workspace/project/build/bootloader-prefix/tmp"
  "/home/molnarm/esp-workspace/project/build/bootloader-prefix/src/bootloader-stamp"
  "/home/molnarm/esp-workspace/project/build/bootloader-prefix/src"
  "/home/molnarm/esp-workspace/project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/molnarm/esp-workspace/project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/molnarm/esp-workspace/project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
