gxx=g++ -O3
cxx=clang++ -O3


all: g++main clang++main clean

g++main: g++main.o
	$(gxx) g++main.o -o g++main
g++main.o: main.cpp
	$(gxx) -c main.cpp -o g++main.o
clang++main: clang++main.o
	$(cxx) clang++main.o -o clang++main
clang++main.o: main.cpp
	$(cxx) -c main.cpp -o clang++main.o
clean:
	rm *.o