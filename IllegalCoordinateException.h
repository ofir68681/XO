#pragma once
#include<iostream>
#include<string>
#include <list>
using namespace std;

class  IllegalCoordinateException{
	list<int> lst;

	public:
		IllegalCoordinateException(list<int> lst){
		this->lst=lst;    
	}   

	string theCoordinate() const{
		return string(to_string(lst.front())+","+to_string(lst.back()));
	}
};