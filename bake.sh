#!/bin/bash

PROJECT_NAME="sfml-craft"
COMPILER="g++"
SRC_DIR="src"
BUILD_DIR="build"

$COMPILER -c $SRC_DIR/Main.cpp
mkdir -p $BUILD_DIR
$COMPILER *.o -o $BUILD_DIR/$PROJECT_NAME
rm -rf *.o
