#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Exception : public exception 
{
private:
    int code;
    string message;

public:
    Exception(int code, const string& message) : code(code), message(message) {}
    ~Exception() {}

    const char* what() const noexcept override 
    {
        return message.c_str();
    }
    
    int getCode() const 
    {
        return code;
    }
};

#endif