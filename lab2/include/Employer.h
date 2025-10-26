#pragma once

#include "Person.h"
#include<iomanip>

typedef struct Taxes
{
    Data time;
    double sum;
};

class Employer : virtual public Person
{
protected:
    char license[30];
    Taxes taxe;

public:
    Employer() : Person()
    {
        strcpy(this->license, " - ");
        this->taxe.sum = 0.0;
        this->taxe.time.day = 0;
        this->taxe.time.month = 0;
        this->taxe.time.year = 0;
    }
    Employer(char* n, Data data, char* l, Taxes t) : Person(n, data)
    {
        strcpy(this->license, l);
        this->taxe.sum = t.sum;
        this->taxe.time = t.time;
    }
    Employer(const Employer& employer) : Person(employer.name, employer.birthday)
    {
        strcpy(this->license, employer.license);
        this->taxe.sum = employer.taxe.sum;
        this->taxe.time = employer.taxe.time;
    }
    ~Employer(){};

    friend ostream& operator<<(ostream&, Employer&);
    friend istream& operator>>(istream&, Employer&);
    Employer& operator=(Employer&);
    void setLicense(char*);
    const char* getLicense() const;
    void setTaxes(Taxes);
    Taxes getTaxes() const;

    Employer& addEmployer(int&);
    virtual char editPunkt() override;
    virtual Employer& editPerson() override;

    virtual void printHeader() override;
    virtual void printTable() override;

};