#!/bin/bash
g++ -c ./src/renderer.cpp -lSDL2 -std=c++17
ar rvs idkpixel.a ./renderer.o
rm ./renderer.o

mkdir idkPixelRenderer
mv ./idkpixel.a ./idkPixelRenderer/idkpixel.a
cp ./src/idk_vecn.hpp ./idkPixelRenderer/idk_vecn.hpp
cp ./src/renderer.hpp ./idkPixelRenderer/renderer.hpp
cp ./src/idkpixel.hpp ./idkPixelRenderer/idkpixel.hpp