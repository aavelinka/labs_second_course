#include "Tourist.h"

void Tourist::setPassport(char* p)
{
    strcpy(this->passport, p);
}

const char* Tourist::getPassport() const
{
    return passport;
}

void Tourist::setCountry(Countries c)
{
    this->country.time = c.time;
    strcpy(this->country.country, c.country);
}

Countries Tourist::getCountry() const
{
    return country;
}

void Tourist::show() 
{
    Person::show();
    cout << "Passport: " << this->passport << endl;
    cout << "Country name : " << this->country.country << endl;
    cout << "Country data: " << this->country.time.day << "." << this->country.time.month << "." << this->country.time.year << endl;
}
