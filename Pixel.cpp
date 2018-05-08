#include "Pixel.h"
#include <iostream>

using namespace std;

Pixel::Pixel(){
	sign = '.';
}

Pixel::Pixel(const char & c){
	if(c != 'X' && c != 'O' && c != '.')
		throw IllegalCharException(c);
	sign = c;
}

Pixel::~Pixel(){
}

Pixel& Pixel::operator = (const char & c){
	if(c != 'X' && c != 'O' && c != '.')
		throw IllegalCharException(c);
	this->sign = c;
	return *this;
}

Pixel Pixel::operator = (const Pixel & p){
	this->sign = p.sign;
	return *this;
}

bool operator == (Pixel const & p, char const & c){
	return p.sign == c;
}

Pixel::operator char(){
	return sign;
}

ostream& operator << (ostream & os, Pixel const & p){
	return os << p.sign;
}