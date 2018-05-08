#pragma once
#include <iostream>
using namespace std;


class IllegalCharException{
    char c;
    
    public:

    IllegalCharException(const char& c){
        this->c=c;
    }
    char theChar() const{
        return c;
    }
};