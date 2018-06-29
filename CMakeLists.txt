cmake_minimum_required (VERSION 2.6)

#Si se va a compilar en Windows, descomenta las siguientes dos líneas:
SET(CMAKE_C_COMPILER C:/MinGW/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER C:/MinGW/bin/g++.exe)

project (CUVC17)

#Headers
include_directories(include)

#Sources
file(GLOB SOURCES "src/*.cpp")

#Ejecutable
add_executable(CUVC17 ${SOURCES})