#pragma once

#include <iostream>
#include <string.h>
#include<iomanip>
using namespace std;

template<typename T> class Deque;

typedef struct Data 
{
    int day;
    int month;
    int year;
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
    char name[30];
    Data birthday;
    static SearchMode currentSearchMode;

public:
    Person()
    {
        strcpy(this->name, "NoName");
        this->birthday.day = 0;
        this->birthday.month = 0;
        this->birthday.year = 0;
    }
    Person(const char* n, Data data)
    {
        strcpy(this->name, n);
        this->birthday.day = data.day;
        this->birthday.month = data.month;
        this->birthday.year = data.year;
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
    void setName(char*);
    const char* getName() const;
    void setBirthday(Data);
    Data getBirthday() const;
    virtual void updateFields(char);

    virtual void printHeader() const = 0;
    virtual void printTable() const = 0;
};