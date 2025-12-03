#pragma once

#include "Person.h"
#include<iomanip>

struct Countries
{
    Date time;
    string countryName;
};

class Tourist : virtual public Person
{
protected:
    string passport;
    Countries country;

public:
    Tourist() : Person()
    {
        this->passport = " - ";
        this->country.countryName = " - ";
        this->country.time = Date(1, 1, 1999);
    }
    Tourist(string n, Date data, string p, Countries c) : Person(n, data)
    {
        this->passport = p;
        this->country.time = c.time;
        this->country.countryName = c.countryName;
    }
    ~Tourist(){ }

    friend ostream& operator<<(ostream&, Tourist&);
    friend istream& operator>>(istream&, Tourist&);
    Tourist& operator=(Tourist&);
    bool operator==(const Tourist& other) const;
    bool operator<(const Tourist& other) const;
    void setPassport(string);
    string getPassport() const;
    void setCountry(Countries);
    Countries getCountry() const;

    Tourist& addTourist(int&);
    virtual void updateFields(int) override;
    // virtual char editPunkt() override;
    // virtual Tourist& editPerson() override;

    virtual void printHeader() const override;
    virtual void printTable() const override;
};