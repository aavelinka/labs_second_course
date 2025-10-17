#pragma once

#include <iostream>
#include <string.h>
#include<iomanip>
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

public:
    Person()
    {
        strcpy(this->name, "NoName");
        this->birthday.day = 1;
        this->birthday.month = 1;
        this->birthday.year = 2000;
    }
    Person(const char* n, Data data)
    {
        strcpy(this->name, n);
        this->birthday.day = data.day;
        this->birthday.month = data.month;
        this->birthday.year = data.year;
    }
    // Person(const Person&);
    virtual ~Person(){}

    friend ostream& operator<<(ostream&, Person&);
    friend istream& operator>>(istream&, Person&);
    Person& operator=(Person&);
    void setName(char*);
    const char* getName() const;
    void setBirthday(Data);
    Data getBirthday() const;

    virtual void printHeader();
    virtual void printTable();
};