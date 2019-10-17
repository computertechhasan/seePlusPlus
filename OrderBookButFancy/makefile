gxx=g++ -O3
cxx=clang++ -O3

all: g++main clang++main clean

g++main: g++main.o g++bidorask.o g++boa_factory.o
	$(gxx) g++main.o g++bidorask.o g++boa_factory.o -o g++main
g++main.o: main.cpp g++bidorask.o g++boa_factory.o
	$(gxx) -c main.cpp -o g++main.o
g++boa_factory.o: boa_factory.cpp g++bidorask.o
	$(gxx) -c boa_factory.cpp -o g++boa_factory.o
g++bidorask.o: bidorask.cpp
	$(gxx) -c bidorask.cpp -o g++bidorask.o
clang++main: clang++main.o clang++bidorask.o clang++boa_factory.o
	$(cxx) clang++main.o clang++bidorask.o clang++boa_factory.o -o clang++main
clang++main.o: main.cpp clang++bidorask.o clang++boa_factory.o
	$(cxx) -c main.cpp -o clang++main.o
clang++boa_factory.o: boa_factory.cpp clang++bidorask.o
	$(cxx) -c boa_factory.cpp -o clang++boa_factory.o
clang++bidorask.o: bidorask.cpp
	$(cxx) -c bidorask.cpp -o clang++bidorask.o
clean:
	rm *.o