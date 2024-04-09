# htop

[![License: GPL v2+](https://img.shields.io/badge/License-GPL%20v2+-blue.svg)](COPYING?raw=true)

## This fork

* Removes support for platforms other than Linux, in order to simplify the source code and the build process.
* Uses CMake instead of GNU autotools.
* Adds `vi` style movement commands.

## Introduction

`htop` is a cross-platform interactive process viewer.

`htop` allows scrolling the list of processes vertically and horizontally to see their full command lines and related information like memory and CPU consumption.
Also system wide information, like load average or swap usage, is shown.

The information displayed is configurable through a graphical setup and can be sorted and filtered interactively.

Tasks related to processes (e.g. killing and renicing) can be done without entering their PIDs.

Running `htop` requires `ncurses` libraries, typically named libncurses(w).

`htop` is written in C.

For more information and details visit [htop.dev](https://htop.dev).

## Build instructions

### Prerequisite
List of build-time dependencies:

* CMake
* C99 compiler toolchain
* ncurses

List of additional build-time dependencies (based on feature flags):

* `sensors`
* `hwloc`
* `libcap` (v2.21 or later)
* `libnl-3` and `libnl-genl-3`

Install these and other required packages for C development from your package manager.

### Compile from source:
To compile from source, clone the Git repository (`git clone`), then run:
```sh
cmake -S . -B build && make -C build
```

## Runtime dependencies:
`htop` has a set of fixed minimum runtime dependencies, which is kept as minimal as possible:

* `ncurses` libraries for terminal handling (wide character support).

## Usage
See the help menu (**F1** or **?** inside `htop`) for a list of supported key commands.

## History

`htop` was invented, developed and maintained by [Hisham Muhammad](https://hisham.hm/) from 2004 to 2019. His [legacy repository](https://github.com/hishamhm/htop/) has been archived to preserve the history.

In 2020 a [team](https://github.com/orgs/htop-dev/people) took over the development amicably and continues to maintain `htop` collaboratively.

## License

GNU General Public License, version 2 (GPL-2.0) or, at your option, any later version.
