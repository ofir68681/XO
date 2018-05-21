#include "Coordinate.h"
#include <iostream>

using namespace std;

Coordinate::Coordinate(){
	sign = '.';
}

Coordinate::Coordinate(const char & c){
	if(c != 'X' && c != 'O' && c != '.')
		throw IllegalCharException(c);
	sign = c;
}

Coordinate::~Coordinate(){
}

Coordinate& Coordinate::operator = (const char & c){
	if(c != 'X' && c != 'O' && c != '.')
		throw IllegalCharException(c);
	this->sign = c;
	return *this;
}

Coordinate Coordinate::operator = (const Coordinate & p){
	this->sign = p.sign;
	return *this;
}

bool operator == (Coordinate const & p, char const & c){
	return p.sign == c;
}

bool operator == (Coordinate const & x, Coordinate const & y){
	return x.sign == y.sign;
}

bool operator != (Coordinate const & x, Coordinate const & y){
	return !(x==y);
}

Coordinate::operator char(){
	return sign;
}

ostream& operator << (ostream & os, Coordinate const & p){
	return os << p.sign;
}