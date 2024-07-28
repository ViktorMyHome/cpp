CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -c
#CXXFLAGS += -fno-elide-constructors

all: main.o Observer.o Observable.o
	g++ main.o Observer.o Observable.o -o observer

main.o:
	g++ $(CXXFLAGS) main.cpp

Observable.o:
	g++ $(CXXFLAGS) Observable.cpp

Observer.o:
	g++ $(CXXFLAGS) Observer.cpp

clean:
	rm -rf *.o observer
