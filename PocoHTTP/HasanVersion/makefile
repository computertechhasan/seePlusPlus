gxx=g++ -O3

all: HTTPGETRequest clean

main: main.cpp HTTPGETRequest.o
	$(gxx) -c main.cpp -o main
HTTPGetRequest.o: HTTPETRequest.cpp
	$(gxx) -c HTTPGETRequest.cpp -o HTTPGETRequest.o -lPocoNet -lPocoFederation
clean:
	rm *.0