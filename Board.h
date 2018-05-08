#pragma once
#include <iostream>
#include <list>
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

using namespace std;

class Board{
    private:
        
        char** board;
       
    public:
        int n;
        //const
        Board(int);
        ~Board();

        char& operator[](list<int>);
        Board& operator=(const char&);

        //Stream
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

};