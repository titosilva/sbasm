#!/bin/env bash

mkdir -p build
cd build
cmake ..
make

echo "COMPILED!! Executing..."
./sbasm "$@"