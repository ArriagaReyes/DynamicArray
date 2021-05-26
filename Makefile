output: main.o Array.o
	g++ main.o Array.o -o build

main.o: main.cpp
	g++ -c main.cpp

Array.o: src/Array.cpp include/Array.hpp
	g++ -c src/Array.cpp

clear:
	rm *.o build