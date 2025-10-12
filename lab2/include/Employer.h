#pragma once

#include "Person.h"

typedef struct Taxes
{
    Data time;
    double sum;
};

class Employer : public Person
{
protected:
    char license[30];
    Taxes taxe;

public:
    Employer(char* n, Data data, char* l, Taxes t) : Person(n, data)
    {
        strcpy(license, l);
        taxe.sum = t.sum;
        taxe.time = t.time;
    }
    Employer(const Employer& employer) : Person(employer.name, employer.birthday)
    {
        strcpy(this->license, employer.license);
        this->taxe.sum = employer.taxe.sum;
        this->taxe.time = employer.taxe.time;
    }
    ~Employer(){};

    void setLicense(char*);
    const char* getLicense() const;
    void setTaxes(Taxes);
    Taxes getTaxes() const;

    void show() override;
};