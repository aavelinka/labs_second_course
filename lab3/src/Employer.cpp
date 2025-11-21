#include "Employer.h"
#include <cstdio>

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
    }

    return *this;
}

bool Employer::operator==(const Employer& other) const
{
    return this->Person::operator==(other);
}

bool Employer::operator<(const Employer& other) const
{
    return this->Person::operator<(other);
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

// char Employer::editPunkt()
// {
//     cout << "-------------------------" << endl;
//     cout << "| 1. Edit name          |" << endl;
//     cout << "| 2. Edit birthday      |" << endl;
//     cout << "| 3. Edit license       |" << endl;
//     cout << "| 4. Edit taxe          |" << endl;
//     cout << "| 5. Edit all           |" << endl;
//     cout << "-------------------------" << endl;


//     char option;
//     cin >> option;

//     return option;
// }

// Employer& Employer::editPerson()
// {
//     switch (editPunkt())
//     {
//     case '1':
//     {
//         char newName[30];
//         cout << "Enter new name: ";
//         cin >> newName;
//         this->setName(newName);
//         break;
//     }
//     case '2':
//     {
//         Data newBirthday;
//         cout << "Enter new birthday(XX.YY.ZZZZ): ";
//         cin >> newBirthday.day >> newBirthday.month >> newBirthday.year;
//         this->setBirthday(newBirthday);
//         break;
//     }
//     case '3':
//     {
//         char newLicense[30];
//         cout << "Enter new license: ";
//         cin >> newLicense;
//         this->setLicense(newLicense);
//         break;
//     }
//     case '4':
//     {
//         Taxes newTaxe;
//         cout << "Enter new taxe:\nSumm - ";
//         cin >> newTaxe.sum;
//         cout << "Time(XX.YY.ZZZZ) - ";
//         cin >> newTaxe.time.day >> newTaxe.time.month >> newTaxe.time.year;
//         this->setTaxes(newTaxe);
//         break;
//     } 
//     case '5':
//     {
//         Employer newEmployer;
//         cin >> newEmployer;
//         *this = newEmployer;
//         break;
//     }
//     }

//     return *this;
// }

// void Employer::printHeader() {
//     cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(31) << "" << "+" << setw(13) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
//     cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(28) << left << "License" << " | " << setw(10) << left << "Tax Sum" << " | " << setw(10) << left << "Tax Date" << " |" << endl;
//     cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(31) << "" << "+" << setw(13) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
// }

void Employer::updateFields(char choiceField)
{
    char license[30];
    Taxes tax;
    if(choiceField <= 2)
    {
        this->Person::updateFields(choiceField);
        return;
    }

    switch(choiceField)
    {
        case 3:
        {
            cout << "New license: ";
            cin >> license;
            this->setLicense(license);
            break;
        }
        case 4:
        {
            cout << "New tax sum: ";
            cin >> tax.sum;
            tax.time = this->getTaxes().time;
            this->setTaxes(tax);
            break;   
        }
        case 5:
        {
            cout << "New tax date(DD MM YYYY): ";
            cin >> tax.time.day >> tax.time.month >> tax.time.year;
            tax.sum = this->getTaxes().sum;
            this->setTaxes(tax);
            break;   
        }
    }
}

void Employer::printHeader() const {
    cout << left;
    cout << "| " << setw(4) << "Name" << " | " << setw(12) << "Birthday" << " | " << setw(7) << "License" << " | " << setw(7) << "Tax Sum" << " | " << setw(12) << "Tax Date" << " | " << setw(8) << "Passport" << " | " << setw(7) << "Country" << " | " << setw(12) << "Visit Date" << " | " << setw(7) << "Address" << " |" << endl;
}

void Employer::printTable() const {
    char birthdayStr[11], taxDateStr[11];
    sprintf(birthdayStr, "%02d.%02d.%04d", birthday.day, birthday.month, birthday.year);
    sprintf(taxDateStr, "%02d.%02d.%04d", taxe.time.day, taxe.time.month, taxe.time.year);
    char taxSumStr[20];
    sprintf(taxSumStr, "%.2f", taxe.sum);
    
    cout << left;
    cout << "| " << setw(4) << name << " | " << setw(12) << birthdayStr << " | " << setw(7) << license << " | " << setw(7) << taxSumStr << " | " << setw(12) << taxDateStr << " | " << setw(8) << " - " << " | " << setw(7) << " - " << " | " << setw(12) << " - " << " | " << setw(7) << " - " << " |" << endl;
}