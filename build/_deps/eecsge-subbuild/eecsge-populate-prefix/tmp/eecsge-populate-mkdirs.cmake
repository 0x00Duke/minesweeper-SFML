# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-src"
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-build"
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix"
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix/tmp"
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix/src/eecsge-populate-stamp"
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix/src"
  "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix/src/eecsge-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix/src/eecsge-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/leon/epitech/tek3/CPP/minesweeper-SFML/build/_deps/eecsge-subbuild/eecsge-populate-prefix/src/eecsge-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
