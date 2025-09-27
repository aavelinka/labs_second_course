#ifndef CLASS_STRING_H
#define CLASS_STRING_H

#include<iostream>
using namespace std;

class String
{
    public:
    String();
    String(char*);
    ~String();
    const String& operator+(const String&);
    const String& operator+=(const String&);
    const String& operator=(const String&);
    const String& operatot[]();
    friend ostream& operator<<(std::ostream&, const String&);
    friend istream& operator>>(std::istream&, String&);
    const String& operator>(const String&);
    const String& operator<(const String&);
    const String& operator++(const String&);
    const String& operator--(const String&);
};

#endif