cmake_minimum_required(VERSION 3.8)
project(KSHInterpreter)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ls.h cd.h ifconfig.h date.h)
add_executable(KSHInterpreter ${SOURCE_FILES})