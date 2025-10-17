#include "Employer.h"

ostream& operator<<(ostream& out, Employer& employer)
{
    out << static_cast<Person&>(employer) << " " << employer.license << " "
    << employer.taxe.sum << " " << employer.taxe.time.day << "." << employer.taxe.time.month << "." 
    << employer.taxe.time.year << endl;

    return out;
}

istream& operator>>(istream& in, Employer& employer)
{
    in >> static_cast<Person&>(employer);
    cout << "Enter license: ";
    in >> employer.license;
    cout << "Enter taxe(sum and time): " << endl;
    cout << "Sum - ";
    in >> employer.taxe.sum;
    cout << "Time(XX.YY.ZZZZ) - ";
    in >> employer.taxe.time.day >> employer.taxe.time.month >> employer.taxe.time.year;

    return in;
}

Employer& Employer::operator=(Employer& employer)
{
    if(this != &employer)
    {
        static_cast<Person&>(*this) = static_cast<Person&>(employer);
        strcpy(this->license, employer.license);
        this->taxe.sum = employer.taxe.sum;
        this->taxe.time.day = employer.taxe.time.day;
        this->taxe.time.month = employer.taxe.time.month;
        this->taxe.time.year = employer.taxe.time.year;
    }

    return *this;
}

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



void Employer::printHeader() {
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(31) << "" << "+" << setw(13) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
    cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(28) << left << "License" << " | " << setw(10) << left << "Tax Sum" << " | " << setw(10) << left << "Tax Date" << " |" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(31) << "" << "+" << setw(13) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
}

void Employer::printTable() {
    cout << "| " << setw(28) << left << name << " | "
         << setw(2) << right << setfill('0') << birthday.day << "." 
         << setw(2) << right << birthday.month << "." 
         << setw(4) << right << birthday.year << setfill(' ') << " | "
         << setw(28) << left << license << " | "
         << setw(10) << left << taxe.sum << " | "
         << setw(2) << right << setfill('0') << taxe.time.day << "."
         << setw(2) << right << taxe.time.month << "."
         << setw(4) << right << taxe.time.year << setfill(' ') << " |" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(31) << "" << "+" << setw(13) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
}