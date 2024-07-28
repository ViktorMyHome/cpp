CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -c
CXXFLAGS += -fno-elide-constructors

all: main.o constr.o
	g++ main.o constr.o -o constr

main.o:
	g++ $(CXXFLAGS) main.cpp

constr.o:
	g++ $(CXXFLAGS) constr.cpp

clean:
	rm -rf *.o constr
