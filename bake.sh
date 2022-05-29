#!/bin/bash

PROJECT_NAME="sfml-craft"
COMPILER="g++"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"
SRC_DIR="src"
BUILD_DIR="build"
HEADER_DIR="src/Headers"
CLASS_DIR="src/Classes"

$COMPILER -c $SRC_DIR/Main.cpp $CLASS_DIR/*.cpp
mkdir -p $BUILD_DIR
$COMPILER *.o -o $BUILD_DIR/$PROJECT_NAME -I $HEADER_DIR $LIBRARIES
rm -rf *.o
