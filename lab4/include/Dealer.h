#pragma once

#include "Employer.h"
#include "Tourist.h"
#include<iomanip>

class Dealer : public Employer, public Tourist
{
private:
    string address;

public:
    Dealer() : Employer(), Tourist()
    {
        this->address = " - ";
    }
    Dealer(string n, Date data, string l, Taxes t, string p, Countries c, string ad) :  Employer(n, data, l, t), Tourist(n, data, p, c)
    {
        this->address = ad;
    }
    ~Dealer(){ }

    friend ostream& operator<<(ostream&, Dealer&);
    friend istream& operator>>(istream&, Dealer&);
    Dealer& operator=(Dealer&);
    bool operator==(const Dealer& other) const;
    bool operator<(const Dealer& other) const;
    void setAddress(string);
    string getAddress() const;

    Dealer& addDealer(int&);
    virtual void updateFields(int) override;
    // virtual char editPunkt() override;
    // virtual Dealer& editPerson() override;

    virtual void printHeader() const override;
    virtual void printTable() const override;
};