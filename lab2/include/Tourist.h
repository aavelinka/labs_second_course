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
        strcpy(this->passport, " - ");
        strcpy(this->country.countryName, " - ");
        this->country.time.day = 0;
        this->country.time.month = 0;
        this->country.time.year = 0;
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

    Tourist& addTourist(int&);
    virtual char editPunkt() override;
    virtual Tourist& editPerson() override;

    virtual void printHeader() override;
    virtual void printTable() override;
};