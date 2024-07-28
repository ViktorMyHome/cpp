all: main.o constr.o
	g++ main.o constr.o -o constr

main.o:
	g++ -std=c++11 -g -c main.cpp

constr.o:
	g++ -std=c++11 -g -c constr.cpp

clean:
	rm -rf *.o constr
