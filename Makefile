CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

clean: 
	rm *.o a.out