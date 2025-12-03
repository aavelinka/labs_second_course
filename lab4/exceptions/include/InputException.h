#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H

#include "Exception.h"
#include <string>

using namespace std;

class InputException : public Exception 
{
public:
    InputException(int code, const string& message) : Exception(code, "Input Error: " + message) {}
    ~InputException() {}
};

#endif
