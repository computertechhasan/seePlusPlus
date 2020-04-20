cxx=g++

All: main
Node.o: Node.cpp Node.h
	$(cxx) -c -o Node.o Node.cpp
main.o: main.cpp
	$(cxx) -o main.o main.cpp
main: main.o Node.o
	$(cxx) -o main main.o Node.o