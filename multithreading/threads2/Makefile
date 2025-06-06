CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -c
CXXFLAGS += -fno-elide-constructors

all: main.o
	g++ main.o -lpthread -o main

main.o:
	g++ $(CXXFLAGS) main.cpp

clean:
	rm -rf *.o main
