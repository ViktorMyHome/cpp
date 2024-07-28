CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -c
#CXXFLAGS += -fno-elide-constructors

all: main.o logger.o
	g++ main.o logger.o -o logger

main.o:
	g++ $(CXXFLAGS) main.cpp

logger.o:
	g++ $(CXXFLAGS) logger.cpp

clean:
	rm -rf *.o logger
