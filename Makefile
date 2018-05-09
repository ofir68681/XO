CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o Pixel.o IllegalCoordinateException.o IllegalCharException.o 

Board.o: Board.cpp Board.h Pixel.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Pixel.o: Pixel.cpp Pixel.h
	$(CXX) $(CXXFLAGS) --compile Pixel.cpp -o Pixel.o

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h Board.h
	$(CXX) $(CXXFLAGS) -c  IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c  IllegalCharException.cpp -o IllegalCharException.o

clean: 
	rm *.o a.out