#include "Employer.h"

void Employer::setLicense(char* l)
{
    strcpy(this->license, l);
}

const char* Employer::getLicense() const
{
    return this->license;
}

void Employer::setTaxes(Taxes t)
{
    this->taxe.time = t.time;
    this->taxe.sum = t.sum;
}

Taxes Employer::getTaxes() const
{
    return this->taxe;
}

void Employer::show()
{
    Person::show();
    cout << "License: " << license << endl;
    cout << "Tax date: " << taxe.time.day << "." << taxe.time.month << "." << taxe.time.year << endl;
    cout << "Tax sum: " << taxe.sum << endl;
}