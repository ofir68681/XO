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
        Board(const Board & b);
        ~Board();

        Pixel& operator[](list<int>);
        const Pixel& operator[](list<int>) const;
        Board& operator=(char const &);
        Board operator=(Board const &);
        friend bool operator==(Board const & , Board const &);


        //Stream
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

};