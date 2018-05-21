#pragma once
#include <iostream>
#include "IllegalCharException.h"
using namespace std;

class Coordinate{
	private:
		char sign;

	public:
		//Constructor
		Coordinate();
		Coordinate(const char &);
		~Coordinate();

		//Assignment
		Coordinate& operator = (const char &);
		Coordinate operator = (const Coordinate & input);

		operator char();

		//Comparison
		friend bool operator == (Coordinate const &, char const &);
		friend bool operator == (Coordinate const &, Coordinate const &);
		friend bool operator != (Coordinate const &, Coordinate const &);

		//Stream
		friend ostream& operator << (ostream &, Coordinate const &);

};