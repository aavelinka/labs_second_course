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
    in >> tourist.country.time.day >> tourist.country.time.month >> tourist.country.time.year;

    return in;
}

Tourist& Tourist::operator=(Tourist& tourist)
{
    if(this != &tourist)
    {
        static_cast<Person&>(*this) = static_cast<Person&>(tourist);
        strcpy(this->passport, tourist.passport);
        this->country = tourist.country;
        // strcpy(this->country.countryName, tourist.country.countryName);
        // this->country.time.day = tourist.country.time.day;
        // this->country.time.month = tourist.country.time.month;
        // this->country.time.year = tourist.country.time.year;
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
    this->country = c;
    // strcpy(this->country.countryName, c.countryName);
}

Countries Tourist::getCountry() const
{
    return country;
}

Tourist& Tourist::addTourist(int& i)
{
    Tourist tourist;
    cout << (i + 1) << ". Add tourist: " << endl;
    cin >> tourist;
    this[i++] = tourist;

    return *this;
}

char Tourist::editPunkt()
{
    cout << "-------------------------" << endl;
    cout << "| 1. Edit name          |" << endl;
    cout << "| 2. Edit birthday      |" << endl;
    cout << "| 3. Edit passport      |" << endl;
    cout << "| 4. Edit country       |" << endl;
    cout << "| 5. Edit all           |" << endl;
    cout << "-------------------------" << endl;


    char option;
    cin >> option;

    return option;
}

Tourist& Tourist::editPerson()
{
    switch (editPunkt())
    {
    case '1':
    {
        char newName[30];
        cout << "Enter new name: ";
        cin >> newName;
        this->setName(newName);
        break;
    }
    case '2':
    {
        Data newBirthday;
        cout << "Enter new birthday(XX.YY.ZZZZ): ";
        cin >> newBirthday.day >> newBirthday.month >> newBirthday.year;
        this->setBirthday(newBirthday);
        break;
    }
    case '3':
    {
        char newPassport[8];
        cout << "Enter new data to passport: ";
        cin >> newPassport;
        this->setPassport(newPassport);
        break;
    }
    case '4':
    {
        Countries newCountry;
        cout << "Enter new country(name and time): " << endl;
        cout << "Name of country - ";
        cin >> newCountry.countryName;
        cout << "Time(XX.YY.ZZZZ) - ";
        cin >> newCountry.time.day >> newCountry.time.month >> newCountry.time.year;
        this->setCountry(newCountry);
        break;
    }
    case '5':
    {
        Tourist newTourist;
        cin >> newTourist;
        *this = newTourist;
        break;
    }
    }

    return *this;
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
