CCX=gcc -std=c++11
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Clean:
		rm *.o a.out