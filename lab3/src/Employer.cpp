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
        this->taxe = employer.taxe;
        // this->taxe.sum = employer.taxe.sum;
        // this->taxe.time.day = employer.taxe.time.day;
        // this->taxe.time.month = employer.taxe.time.month;
        // this->taxe.time.year = employer.taxe.time.year;
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

Employer& Employer::addEmployer(int& i)
{
    Employer employer;
    cout << (i + 1) << ". Add employer: " << endl;
    cin >> employer;
    this[i++] = employer;

    return *this;
}

char Employer::editPunkt()
{
    cout << "-------------------------" << endl;
    cout << "| 1. Edit name          |" << endl;
    cout << "| 2. Edit birthday      |" << endl;
    cout << "| 3. Edit license       |" << endl;
    cout << "| 4. Edit taxe          |" << endl;
    cout << "| 5. Edit all           |" << endl;
    cout << "-------------------------" << endl;


    char option;
    cin >> option;

    return option;
}

Employer& Employer::editPerson()
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
        char newLicense[30];
        cout << "Enter new license: ";
        cin >> newLicense;
        this->setLicense(newLicense);
        break;
    }
    case '4':
    {
        Taxes newTaxe;
        cout << "Enter new taxe:\nSumm - ";
        cin >> newTaxe.sum;
        cout << "Time(XX.YY.ZZZZ) - ";
        cin >> newTaxe.time.day >> newTaxe.time.month >> newTaxe.time.year;
        this->setTaxes(newTaxe);
        break;
    } 
    case '5':
    {
        Employer newEmployer;
        cin >> newEmployer;
        *this = newEmployer;
        break;
    }
    }

    return *this;
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