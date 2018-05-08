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

Pixel& Board::operator[](list<int> lst){
	if(lst.size() != 2)
		throw "wrong input";
	if(lst.front()>=0 && lst.front()<this->n && lst.back()>=0 && lst.back()<this->n){
		int x = lst.front();
		int y = lst.back();
		return this->board[x][y];    
	}
	throw IllegalCoordinateException (lst);
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

ostream& operator << (ostream& os, Board const & board){
	for(int i = 0 ; i < board.n ; i++)
		for(int j = 0 ; j < board.n ; j++){
			os << board.board[i][j];
			if(j == board.n - 1 and i != board.n-1)
				os << endl;
		} 
	return os;
}

//Destructor

Board::~Board(){
	for(int i = 0 ; i < n ; i++){
		delete board[i];
	}
	delete board;
}