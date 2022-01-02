cmake_minimum_required(VERSION 3.0)
project(dvpt C)

set(CMAKE_C_STANDARD 99)

add_executable(dvpt main.c ARBRE.h ARBRE.c)
