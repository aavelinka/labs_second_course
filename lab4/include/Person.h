#pragma once

#include "../exceptions/include/InputValidator.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include<iomanip>
using namespace std;

template<typename T> class Deque;

struct Data 
{
    int day, month, year;

    string toString() const;
    static Data fromString(const string& dateStr);

    friend ostream& operator<<(ostream& os, const Data& date);
    friend istream& operator>>(istream& is, Data& date);
    bool operator>(const Data& a) 
    {
        return tie(this->year, this->month, this->day) > tie(a.year, a.month, a.day);
    }
} ;

enum SearchMode {
    FULL_MATCH,
    NAME,
    BIRTHDAY,
    BIRTH_YEAR
};

class Person
{
protected:
    string name;
    Data birthday;
    static SearchMode currentSearchMode;

public:
    Person()
    {
        this->name = "NoName";
        this->birthday = {0, 0, 0};
    }
    Person(string n, Data data)
    {
        this->name = n;
        this->birthday = data;
    }
    virtual ~Person()
    {
    }

    static void setSearchMode(SearchMode mode)
    {
        currentSearchMode = mode;
    }
    static SearchMode getSearchMode()
    {
        return currentSearchMode;
    }

    friend ostream& operator<<(ostream&, Person&);
    friend istream& operator>>(istream&, Person&);
    Person& operator=(Person&);
    bool operator==(const Person& other) const;
    bool operator<(const Person& other) const;
    void setName(string);
    string getName() const;
    void setBirthday(Data);
    Data getBirthday() const;
    virtual void fieldBy();
    virtual void updateFields(int);

    virtual void printHeader() const = 0;
    virtual void printTable() const = 0;
};