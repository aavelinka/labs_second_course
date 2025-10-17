#pragma once

#include "Person.h"
#include<iomanip>

typedef struct Countries
{
    Data time;
    char countryName[15];
};

class Tourist : virtual public Person
{
protected:
    char passport[8];
    Countries country;

public:
    Tourist() : Person()
    {
        strcpy(this->passport, "00000001");
        strcpy(this->country.countryName, "Belarus");
        this->country.time.day = 1;
        this->country.time.month = 1;
        this->country.time.year = 2000;
    }
    Tourist(char* n, Data data, char* p, Countries c) : Person(n, data)
    {
        strcpy(this->passport, p);
        this->country.time = c.time;
        strcpy(this->country.countryName, c.countryName);
    }
    ~Tourist(){};

    friend ostream& operator<<(ostream&, Tourist&);
    friend istream& operator>>(istream&, Tourist&);
    Tourist& operator=(Tourist&);
    void setPassport(char*);
    const char* getPassport() const;
    void setCountry(Countries);
    Countries getCountry() const;

    virtual void printHeader() override;
    virtual void printTable() override;
};