clang++ -std=c++23 --precompile afxm.cppm -o build/afxm.pcm
clang++ -std=c++23 main.cpp -fmodule-file=testmodule=build/afxm.pcm build/afxm.pcm -o build/main.exe
