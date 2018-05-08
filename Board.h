#pragma once
#include <iostream>
#include <list>
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
#include "Pixel.h"

using namespace std;

class Board{
	private:
        
        Pixel** board;
       
    public:
        int n;

        //Constructor
        Board();
        Board(int);
        ~Board();

        Pixel& operator[](list<int>);
        Board& operator=(char const &);

        //Stream
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

};