#ifndef CLASS_STRING_H
#define CLASS_STRING_H

#include <iostream>
#include <string.h>
using namespace std;

class String
{
    char* info;
    int lenth;

    public:
    String()
    {
        info = nullptr;
        lenth = 0;
    }
    String(int size)
    {
        lenth = size;
        info = new char[lenth + 1];
        info[lenth + 1] = '\0';
    }
    String(char* str)
    {
        lenth = strlen(str);
        info = new char[lenth + 1];
        strcpy(info, str);
    }
    String(const String& str)
    {
        lenth = str.lenth;
        info = new char[str.lenth + 1];
        strcpy(info, str.info);
    }
    ~String()
    {
        lenth = 0;
        delete[] info;
    }
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
    String operator+(const String&);                 // объект + объект
    String operator+(const char*);                   // объект + строка
    friend String operator+(char*, const String&);   // строка + объект
    String operator-(const String&);                // объект - объект
    String operator-(const char*);                  // объект - строка
    friend String operator-(char*, const String&);  // строка - объект
    String& operator+=(const String&); 
    String& operator+=(const char*);
    String& operator-=(const String&);
    String& operator-=(const char*);
    String& operator=(const String&);
    char operator[](int);
    String operator()(int, int);
    int operator>(const String&);
    int operator>(const char*);
    int operator<(const String&);
    int operator<(const char*);
    String& operator++();
    String& operator--();
    String operator*(int);                          //умножение строки на число
    String operator&(const String&);
};

#endif