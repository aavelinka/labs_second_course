#pragma once

#include "Person.h"
#include<iomanip>

struct Taxes
{
    Data time;
    double sum;
};

class Employer : virtual public Person
{
protected:
    string license;
    Taxes taxe;

public:
    Employer() : Person()
    {
        this->license = " - ";
        this->taxe.sum = 0.0;
        this->taxe.time = {0, 0, 0};
    }
    Employer(string n, Data data, string l, Taxes t) : Person(n, data)
    {
        this->license = l;
        this->taxe.sum = t.sum;
        this->taxe.time = t.time;
    }
    Employer(const Employer& employer) : Person(employer.name, employer.birthday)
    {
        this->license = employer.license;
        this->taxe.sum = employer.taxe.sum;
        this->taxe.time = employer.taxe.time;
    }
    ~Employer() { }

    friend ostream& operator<<(ostream&, Employer&);
    friend istream& operator>>(istream&, Employer&);
    Employer& operator=(Employer&);
    bool operator==(const Employer& other) const;
    bool operator<(const Employer& other) const;
    void setLicense(string);
    string getLicense() const;
    void setTaxes(Taxes);
    Taxes getTaxes() const;

    Employer& addEmployer(int&);
    virtual void fieldBy() override;
    virtual void updateFields(int) override;
    // virtual char editPunkt() override;
    // virtual Employer& editPerson() override;

    virtual void printHeader() const override;
    virtual void printTable() const override;

    virtual void saveTextRecord(ostream& os) const override;
    virtual void loadFromText(istream& is) override;
    virtual void saveBinaryRecord(ostream& os) const override;
    virtual void loadFromBinary(istream& is) override;

};
