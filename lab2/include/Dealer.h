#pragma once

#include "Employer.h"
#include "Tourist.h"
#include<iomanip>

class Dealer : public Employer, public Tourist
{
private:
    char address[30];

public:
    Dealer() : Employer(), Tourist()
    {
        strcpy(this->address, " - ");
    }
    Dealer(char* n, Data data, char* l, Taxes t, char* p, Countries c, const char* ad) :  Employer(n, data, l, t), Tourist(n, data, p, c)
    {
        strcpy(this->address, ad);
    }
    ~Dealer(){};

    friend ostream& operator<<(ostream&, Dealer&);
    friend istream& operator>>(istream&, Dealer&);
    Dealer& operator=(Dealer&);
    void setAddress(char*);
    const char* getAddress() const;

    Dealer& addDealer(int&);
    virtual char editPunkt() override;
    virtual Dealer& editPerson() override;

    virtual void printHeader() override;
    virtual void printTable() override;
};