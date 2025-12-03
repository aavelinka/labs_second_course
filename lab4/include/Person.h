#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string.h>
#include <sstream>
#include<iomanip>
using namespace std;

template<typename T> class Deque;

struct Date 
{
    int day, month, year;

    Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1999;
    }
    Date(int d, int m, int y) 
    {
        this->day = d;
        this->month = m;
        this->year = y;
    }
    Date(const Date& other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    string toString() const;
    static Date fromString(const string& dateStr);

    friend ostream& operator<<(ostream& os, const Date& date);
    friend istream& operator>>(istream& is, Date& date);
    Date& operator=(const Date& other)
    {
        if (this != &other)
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }
        return *this; 
    }
    bool operator>(const Date& a) const
    {
        return tie(this->year, this->month, this->day) > tie(a.year, a.month, a.day);
        //return (m->date.year > latestDate.year || 
        //(m->date.year == latestDate.year && m->date.month > latestDate.month) ||
        //(m->date.year == latestDate.year && m->date.month == latestDate.month && m->date.day > latestDate.day))

    }
    bool operator<(const Date& a) const
    {
        return tie(this->year, this->month, this->day) < tie(a.year, a.month, a.day);
        //return (m->date.year > latestDate.year || 
        //(m->date.year == latestDate.year && m->date.month > latestDate.month) ||
        //(m->date.year == latestDate.year && m->date.month == latestDate.month && m->date.day > latestDate.day))

    }
    bool operator==(const Date& a) const
    {
        return tie(this->year, this->month, this->day) == tie(a.year, a.month, a.day);
    }
    bool operator!=(const Date& other) const
    {
        return !(*this == other);
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
    Date birthday;
    static SearchMode currentSearchMode;

public:
    Person()
    {
        this->name = "NoName";
        this->birthday = Date();
    }
    Person(string n, Date data)
    {
        this->name = n;
        this->birthday = data;
    }
    virtual ~Person() {}

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
    void setBirthday(Date);
    Date getBirthday() const;
    virtual void updateFields(int);

    virtual void printHeader() const = 0;
    virtual void printTable() const = 0;
};

#endif