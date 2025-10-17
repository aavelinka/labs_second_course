#include "Dealer.h"

ostream& operator<<(ostream& out, Dealer& dealer)
{
    out << static_cast<Employer&>(dealer) << " " << dealer.passport << " "
    << dealer.country.countryName << " " << dealer.country.time.day << "."
    << dealer.country.time.month << "." << dealer.country.time.year << " "
    << dealer.address << endl;

    return out;
}

istream& operator>>(istream& in, Dealer& dealer)
{
    in >> static_cast<Employer&>(dealer);
    cout << "Enter passport number: ";
    in >> dealer.passport;
    cout << "Enter country(name and time): " << endl;
    cout << "Name of country - "; //????????????????????
    in >> dealer.country.countryName;
    cout << "Time(XX.YY.ZZZZ) - ";
    in >> dealer.country.time.day >> dealer.country.time.month >> dealer.country.time.month;
    cout << "Enter address: ";
    in >> dealer.address;

    return in;
}

Dealer& Dealer::operator=(Dealer& dealer)
{
    if(this != &dealer)
    {
        static_cast<Employer&>(*this) = static_cast<Employer&>(dealer);
        static_cast<Tourist&>(*this) =  static_cast<Tourist&>(dealer);
        strcpy(this->address, dealer.address);
    }

    return *this;
}

void Dealer::setAddress(char* add)
{
    strcpy(this->address, add);
}

const char* Dealer::getAddress() const
{
    return this->address;
}


void Dealer::printHeader() {
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
    cout << "|" << "Delaler inforamtion" << setw(164) << "|"<< endl;
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
    cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(28) << left << "License" << " | " << setw(10) << left << "Tax Sum" << " | " << setw(10) << left << "Tax Date" << " | " << setw(8) << left << "Passport" << " | " << setw(15) << left << "Country" << " | " << setw(10) << left << "Visit Date" << " | " << setw(37) << left << "Address" << " |" << endl;
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
}

void Dealer::printTable() {
    cout << "| " << setw(28) << left << name << " | "
         << setw(2) << right << setfill('0') << birthday.day << "." 
         << setw(2) << right << birthday.month << "." 
         << setw(4) << right << birthday.year << setfill(' ') << " | "
         << setw(28) << left << license << " | "
         << setw(10) << left << taxe.sum << " | "
         << setw(2) << right << setfill('0') << taxe.time.day << "."
         << setw(2) << right << taxe.time.month << "."
         << setw(4) << right << taxe.time.year << setfill(' ') << " | "
         << setw(8) << left << passport << " | "
         << setw(15) << left << country.countryName << " | "
         << setw(2) << right << setfill('0') << country.time.day << "."
         << setw(2) << right << country.time.month << "."
         << setw(4) << right << country.time.year << setfill(' ') << " | "
         << setw(37) << left << address << " |" << endl;
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
}