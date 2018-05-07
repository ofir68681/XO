#include <iostream>
#include <string>
#include "Board.h"
using namespace std;
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"



Board::Board(int n){
    this->n = n;
    board = new char*[n];
    for(int i = 0; i < n; i++){
        board[i] = new char[n];
        for(int j = 0 ; j < n ; j++)
            board[i][j] = '.';
    }
}

char& Board::operator[](list<int> lst){
    if(lst.size() != 2)
        throw "wrong input";
	int x = lst.front();
	int y = lst.back();
		return this->board[x][y];
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