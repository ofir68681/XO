#include<iostream>
#include <list>
#include "IllegalCoordinateException.h"
using namespace std;


IllegalCoordinateException::IllegalCoordinateException(list<int> lst){
	this->lst=lst;    
}   

string IllegalCoordinateException::theCoordinate() const{
	return string(to_string(lst.front())+","+to_string(lst.back()));
}
