#!/bin/sh

set -xe

C_FLAGS="-Wall -Wextra `pkg-config --cflags raylib`"
LIBS="`pkg-config --libs raylib` -ldl"


g++ $C_FLAGS -o build/pong src/*.cpp  $LIBS

