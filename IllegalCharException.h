#pragma once
#include <iostream>
using namespace std;


class IllegalCharException{
    char c;
    
    public:

    IllegalCharException(const char& c);
    char theChar() const;
};