#pragma once
#include <iostream>
#include <list>
using namespace std;
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"


class Board{
    private:
        
        char** board;
       
    public:
        int n;
        //const
        Board(int);
        ~Board();

       char& operator[](list<int>);
        //Stream
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

};