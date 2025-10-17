#include "Tourist.h"

ostream& operator<<(ostream& out, Tourist& tourist)
{
    out << static_cast<Person&>(tourist) << " " << tourist.passport << " "
    << tourist.country.countryName << " " << tourist.country.time.day << "."
    << tourist.country.time.month << "." << tourist.country.time.year << endl;

    return out;
}

istream& operator>>(istream& in, Tourist& tourist)
{
    in >> static_cast<Person&>(tourist);
    cout << "Enter passport number: ";
    in >> tourist.passport;
    cout << "Enter country(name and time): " << endl;
    cout << "Name of country - "; 
    in >> tourist.country.countryName;
    cout << "Time(XX.YY.ZZZZ) - ";
    in >> tourist.country.time.day >> tourist.country.time.month >> tourist.country.time.month;

    return in;
}

Tourist& Tourist::operator=(Tourist& tourist)
{
    if(this != &tourist)
    {
        static_cast<Person&>(*this) = static_cast<Person&>(tourist);
        strcpy(this->passport, tourist.passport);
        strcpy(this->country.countryName, tourist.country.countryName);
        this->country.time.day = tourist.country.time.day;
        this->country.time.month = tourist.country.time.month;
        this->country.time.year = tourist.country.time.year;
    }

    return *this;
}

void Tourist::setPassport(char* p)
{
    strcpy(this->passport, p);
}

const char* Tourist::getPassport() const
{
    return this->passport;
}

void Tourist::setCountry(Countries c)
{
    this->country.time = c.time;
    strcpy(this->country.countryName, c.countryName);
}

Countries Tourist::getCountry() const
{
    return country;
}


void Tourist::printHeader() {
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(11) << "" << "+" << setw(18) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
    cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(8) << left << "Passport" << " | " << setw(15) << left << "Country" << " | " << setw(10) << left << "Visit Date" << " |" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(11) << "" << "+" << setw(18) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
}

void Tourist::printTable() {
    cout << "| " << setw(28) << left << name << " | "
         << setw(2) << right << setfill('0') << birthday.day << "." 
         << setw(2) << right << birthday.month << "." 
         << setw(4) << right << birthday.year << setfill(' ') << " | "
         << setw(8) << left << passport << " | "
         << setw(15) << left << country.countryName << " | "
         << setw(2) << right << setfill('0') << country.time.day << "."
         << setw(2) << right << country.time.month << "."
         << setw(4) << right << country.time.year << setfill(' ') << " |" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(11) << "" << "+" << setw(18) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
}
