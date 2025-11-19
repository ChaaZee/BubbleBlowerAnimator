# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-src")
  file(MAKE_DIRECTORY "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-build"
  "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix"
  "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/tmp"
  "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
  "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src"
  "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/chaze/CSE 335/Project-2-main/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
