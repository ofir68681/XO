#pragma once
#include <iostream>
#include "IllegalCharException.h"
using namespace std;

class Pixel{
	private:
		char sign;

	public:
		//Constructor
		Pixel();
		Pixel(const char &);
		~Pixel();

		//Assignment
		Pixel& operator = (const char &);
		Pixel operator = (const Pixel & input);

		operator char();

		//Comparison
		friend bool operator == (Pixel const &, char const &);
		friend bool operator == (Pixel const &, Pixel const &);
		friend bool operator != (Pixel const &, Pixel const &);

		//Stream
		friend ostream& operator << (ostream &, Pixel const &);

};