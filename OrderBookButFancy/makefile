gxx=g++ -O3
cxx=clang++ -O3

all: g++main clang++main clean

g++main: g++main.o g++bidorask.o g++boa_factory.o g++OrderBook.o
	$(gxx) g++main.o g++bidorask.o g++boa_factory.o g++OrderBook.o -o g++main
g++main.o: main.cpp g++bidorask.o g++boa_factory.o g++OrderBook.o
	$(gxx) -c main.cpp -o g++main.o
g++OrderBook.o: OrderBook.cpp g++bidorask.o
	$(gxx) -c OrderBook.cpp -o g++OrderBook.o
g++boa_factory.o: boa_factory.cpp g++bidorask.o
	$(gxx) -c boa_factory.cpp -o g++boa_factory.o
g++bidorask.o: BOA.cpp
	$(gxx) -c BOA.cpp -o g++bidorask.o
clang++main: clang++main.o clang++bidorask.o clang++boa_factory.o clang++OrderBook.o
	$(gxx) clang++main.o clang++bidorask.o clang++boa_factory.o clang++OrderBook.o -o clang++main
clang++main.o: main.cpp clang++bidorask.o clang++boa_factory.o clang++OrderBook.o
	$(gxx) -c main.cpp -o clang++main.o
clang++OrderBook.o: OrderBook.cpp clang++bidorask.o
	$(gxx) -c OrderBook.cpp -o clang++OrderBook.o
clang++boa_factory.o: boa_factory.cpp clang++bidorask.o
	$(gxx) -c boa_factory.cpp -o clang++boa_factory.o
clang++bidorask.o: BOA.cpp
	$(gxx) -c BOA.cpp -o clang++bidorask.o
clean:
	rm *.o