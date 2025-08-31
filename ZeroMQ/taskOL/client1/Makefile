CXXFLAGS = -std=c++17
CXXFLAGS += -g
CXXFLAGS += -c

all: main.o
	g++ main.o -lzmq -o main 

main.o:
	g++ $(CXXFLAGS) main.cpp

clean:
	rm -rf *.o main
