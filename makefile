olcExampleProgram.exe	:	olcExampleProgram.cpp
	g++ -o olcExampleProgram.exe olcExampleProgram.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
