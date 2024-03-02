#!/usr/bin/env bash

##!/usr/bin/env bash
#
#set -e
#
#flags=$(llvm-config --cxxflags --ldflags --system-libs --libs core)
#clang++ main.cpp $flags -std=c++20 -o main

set -e

mkdir -p build
cd build
CXX=clang++ CC=clang cmake ..
make -j4