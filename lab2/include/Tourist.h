#pragma once

#include "Person.h"

typedef struct Countries
{
    Data time;
    char country[15];
};

class Tourist : public Person
{
protected:
    char passport[15];
    Countries country;

public:
    Tourist(char* n, Data data, char* p, Countries c) : Person(n, data)
    {
        strcpy(this->passport, p);
        this->country.time = c.time;
        strcpy(this->country.country, c.country);
    }
    ~Tourist(){};

    void setPassport(char*);
    const char* getPassport() const;
    void setCountry(Countries);
    Countries getCountry() const;

    void show() override;
};