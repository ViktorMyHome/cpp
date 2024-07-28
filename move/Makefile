all: main.o source.o
	g++ main.o source.o -o source

main.o:
	g++ -std=c++11 -g -c main.cpp

source.o:
	g++ -std=c++11 -g -c source.cpp

clean:
	rm -rf *.o source
