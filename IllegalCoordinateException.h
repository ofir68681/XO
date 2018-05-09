#pragma once
#include<iostream>
#include<string>
#include <list>
using namespace std;

class  IllegalCoordinateException{
	list<int> lst;

	public:
		IllegalCoordinateException(list<int>);
		string theCoordinate() const;
};