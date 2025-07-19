# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-src"
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build"
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps"
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/tmp"
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp"
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src"
  "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
