CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o Coordinate.o IllegalCoordinateException.o IllegalCharException.o 

Board.o: Board.cpp Board.h Coordinate.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Coordinate.o: Coordinate.cpp Coordinate.h
	$(CXX) $(CXXFLAGS) --compile Coordinate.cpp -o Coordinate.o

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h Board.h
	$(CXX) $(CXXFLAGS) -c  IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c  IllegalCharException.cpp -o IllegalCharException.o

clean: 
	rm *.o a.out