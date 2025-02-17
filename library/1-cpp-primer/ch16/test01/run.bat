@echo off

set ROOT_PATH=%cd%\
set EXE_PATH=%ROOT_PATH%executable.exe

g++ main.cpp Foo.hpp Foo.tcc --output=%EXE_PATH% --std=c++11 -O3
executable.exe

@echo on