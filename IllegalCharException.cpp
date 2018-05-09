#include <iostream>
#include "IllegalCharException.h"

using namespace std;

IllegalCharException::IllegalCharException(const char& c){
    this->c=c;
}

char IllegalCharException::theChar() const{
    return c;
}