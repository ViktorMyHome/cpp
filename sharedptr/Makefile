CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -c
#CXXFLAGS += -fno-elide-constructors

all: main.o integer.o
	g++ main.o integer.o -o integer

main.o:
	g++ $(CXXFLAGS) main.cpp

integer.o:
	g++ $(CXXFLAGS) integer.cpp

clean:
	rm -rf *.o integer
