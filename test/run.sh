#!/bin/bash

# Clean Up
rm *.o *.so *.lib test *.out

# Build Files
gcc -fPIC -c trans.c 
gcc -shared -o libtrans.so trans.o

# Create directory
mkdir -p thirdparty/linux/include
mkdir -p thirdparty/linux/lib/x64

mkdir -p trans.h thirdparty/Mac/include/
mkdir -p thirdparty/Mac/lib/x64/

# Transfer files
cp  trans.h thirdparty/linux/include/
cp  libtrans.so thirdparty/linux/lib/x64/

cp  trans.h thirdparty/Mac/include/
cp  libtrans.so thirdparty/Mac/lib/x64/