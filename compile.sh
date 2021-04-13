#!/bin/bash

rm -rf build
mkdir build
cd build

# Build Project
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DTEST=true ..
cmake --build .
