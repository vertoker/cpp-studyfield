clang++ -x c++-header -c stdafx.h -o build/stdafx.h.pch
clang++ -S -include-pch build/stdafx.h.pch main.cpp -o build/main.s
clang++ -include-pch build/stdafx.h.pch main.cpp -o build/main.exe
