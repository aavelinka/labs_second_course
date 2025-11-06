#include "Person.h"

ostream& operator<<(ostream& out, Person& person)
{
    out << person.name << ' ' << person.birthday.day << '.' << person.birthday.month << '.' 
    << person.birthday.year << endl;

    return out;
}

istream& operator>>(istream& in, Person& person)
{
    cout << "Enter name: " ;
    in >> person.name;
    cout << "Enter birthday(XX.YY.ZZZZ): ";
    in >> person.birthday.day >> person.birthday.month >> person.birthday.year;

    return in;
}

Person& Person::operator=(Person& person)
{
    if(this != &person)
    {
        strcpy(this->name, person.name);
        this->birthday.day = person.birthday.day;
        this->birthday.month = person.birthday.month;
        this->birthday.year = person.birthday.year;
    }

    return *this;
}

void Person::setName(char* n)
{
    strcpy(this->name, n);
}

const char* Person::getName() const
{
    return this->name;
}

void Person::setBirthday(Data countineus)
{
    this->birthday.day = countineus.day;
    this->birthday.month = countineus.month;
    this->birthday.year = countineus.year;
}

Data Person::getBirthday() const
{
    return this->birthday;
}

void Person::printHeader() {
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
    cout << "|" << "Person inforamtion" << setw(164) << "|"<< endl;
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
    cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(28) << left << "License" << " | " << setw(10) << left << "Tax Sum" << " | " << setw(10) << left << "Tax Date" << " | " << setw(8) << left << "Passport" << " | " << setw(15) << left << "Country" << " | " << setw(10) << left << "Visit Date" << " | " << setw(37) << left << "Address" << " |" << endl;
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
}

void Person::printTable() {
    cout << "| " << setw(28) << left << name << " | "
         << setw(2) << right << setfill('0') << birthday.day << "." 
         << setw(2) << right << birthday.month << "." 
         << setw(4) << right << birthday.year << setfill(' ') << " |" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
}