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
    cout << "Name of country - ";
    in >> dealer.country.countryName;
    cout << "Time(XX.YY.ZZZZ) - ";
    in >> dealer.country.time.day >> dealer.country.time.month >> dealer.country.time.year;
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

Dealer& Dealer::addDealer(int& i)
{
    Dealer dealer;
    cout << (i + 1) << ". Add dealer: " << endl;
    cin >> dealer;
    this[i++] = dealer;

    return *this;
}

char Dealer::editPunkt()
{
    cout << "-------------------------" << endl;
    cout << "| 1. Edit name          |" << endl;
    cout << "| 2. Edit birthday      |" << endl;
    cout << "| 3. Edit license       |" << endl;
    cout << "| 4. Edit taxe          |" << endl;
    cout << "| 5. Edit passport      |" << endl;
    cout << "| 6. Edit country       |" << endl;
    cout << "| 7. Edit address       |" << endl;
    cout << "| 8. Edit all           |" << endl;
    cout << "-------------------------" << endl;


    char option;
    cin >> option;

    return option;
}

Dealer& Dealer::editPerson()
{
    cout << "What the dealer do you want to edit?\nChoice: ";
    int numberDealer;
    cin >> numberDealer;

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
        char newPassport[8];
        cout << "Enter new data to passport: ";
        cin >> newPassport;
        this->setPassport(newPassport);
        break;
    }
    case '6':
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
    case '7':
    {
        char newAddress[30];
        cout << "Enter new address: ";
        int i = 0;
        while(newAddress[i] != '\n')
        {
            cin >> newAddress;
            ++i;
        }
        this->setAddress(newAddress);
        break;
    }
    case '8':
    {
        Dealer newDealer;
        cin >> newDealer;
        *this = newDealer;
        break;
    }
    }

    return *this;
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
         << setw(31) << left << address << " |" << endl;
    cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
}