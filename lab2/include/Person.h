#pragma once

#include <iostream>
#include <string.h>
using namespace std;

typedef struct Data 
{
    int day;
    int month;
    int year;
} ;

class Person
{
protected:
    char name[30];
    Data birthday;
    // typedef struct Data                       //так почему-то неельзя объявить структуру и сразу переменную этого типа
    // {
    //     int day;
    //     int month; 
    //     int year;
    // } birthday;

public:
    Person(const const char* n, Data data)
    {
        strcpy(name, n);
        birthday.day = data.day;
        birthday.month = data.month;
        birthday.year = data.year;
    }
    virtual ~Person() = 0;

    void setName(char*);
    const char* getName() const;
    void setData(Data);
    Data getData() const;

    virtual void show();
};