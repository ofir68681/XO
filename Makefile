CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o Pixel.o

Board.o: Board.cpp Board.h Pixel.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Pixel.o: Pixel.cpp Pixel.h
	$(CXX) $(CXXFLAGS) --compile Pixel.cpp -o Pixel.o

clean: 
	rm *.o a.out