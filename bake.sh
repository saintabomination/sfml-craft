#!/bin/bash

PROJECT_NAME="sfml-craft"
COMPILER="g++"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"
SRC_DIR="src"
BUILD_DIR="build"

$COMPILER -c $SRC_DIR/Main.cpp
mkdir -p $BUILD_DIR
$COMPILER *.o -o $BUILD_DIR/$PROJECT_NAME $LIBRARIES
rm -rf *.o
