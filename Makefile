CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o Pixel.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Pixel.o: Pixel.cpp Pixel.h Board.h
	$(CXX) $(CXXFLAGS) -c  Pixel.cpp -o Pixel.o

clean: 
	rm *.o b.o