#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

Board::Board(){
	this->n = 0;
	this->board = nullptr;
}


Board::Board(int n){
	if(n < 0)
		throw "wrong input";
	this->n = n;
	board = new Pixel*[n];
	for(int i = 0; i < n; i++){
		board[i] = new Pixel[n];
	}
}

Board::Board(const Board & b){
    n = b.n;
    board = new Pixel*[b.n];
    for(int i = 0; i < b.n; i++){
        board[i] = new Pixel[n];
        for(int j = 0 ; j < b.n ; j++)
            (*this)[{i,j}] = b[{i,j}];
    }
}

//Destructor
Board::~Board(){
	for(int i = 0 ; i < n ; i++){
		delete [] board[i];
	}
	delete [] board;
}

Pixel& Board::operator[](list<int> lst){
	if(lst.size() != 2 || lst.front() > n-1 || lst.back() > n-1 || lst.front() < 0 || lst.back() < 0)
        throw IllegalCoordinateException(lst);
		int x = lst.front();
		int y = lst.back();
		return this->board[x][y];    
}

const Pixel& Board::operator[](list<int> lst) const{
    if(lst.size() != 2 || lst.front() > n-1 || lst.back() > n-1 || lst.front() < 0 || lst.back() < 0)
        throw IllegalCoordinateException(lst);
	int x = lst.front();
	int y = lst.back();
	return this->board[x][y];
}

Board& Board:: operator=(char const& c){
	if (c!='.' && c!='X' && c!='O')
		throw IllegalCharException(c);
	for(int i=0;i<this->n;++i){
		for(int j=0;j<this->n;++j){
			(*this)[{i,j}] = c;
		}
	}
	return *this;
}

Board Board::operator=(Board const & b){
	this->~Board();
    n = b.n;
    board = new Pixel*[b.n];
    for(int i = 0; i < b.n; i++){
        board[i] = new Pixel[n];
        for(int j = 0 ; j < b.n ; j++)
            (*this)[{i,j}] = b[{i,j}];
    }
    return *this;
}

bool operator==(Board const & x,Board const & y){

	if (x.n != y.n)
		return false;

	bool f= true;
    for(int i = 0; i < x.n; i++){
        for(int j = 0 ; j < x.n ; j++)
            if(x[{i,j}] != y[{i,j}])
				f=false;
    }
    return f;
}

ostream& operator << (ostream & os, Board const & b){
    for(int i = 0 ; i < b.n ; i++){
        for(int j = 0 ; j < b.n ; j++){
            os << b.board[i][j];
        }
        os << endl;
    }
    return os;
}