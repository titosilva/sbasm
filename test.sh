#!/bin/env bash

mkdir -p build
cd build
cmake ..

make clean
make test