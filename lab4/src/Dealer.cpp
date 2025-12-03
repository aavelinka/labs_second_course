#include "Dealer.h"
#include "../exceptions/include/InputValidator.h"
#include <cstdio>

ostream& operator<<(ostream& out, Dealer& dealer)
{
    out << static_cast<Employer&>(dealer) << " " << dealer.passport << " "
    << dealer.country.countryName << " " << dealer.country.time << " "
    << dealer.address << endl;

    return out;
}

istream& operator>>(istream& in, Dealer& dealer)
{
    in >> static_cast<Employer&>(dealer);
    cout << "Введиет номер паспорта: ";
    dealer.passport = getValidPassword(in);
    cout << "Введие страну(название и дата): " << endl;
    cout << "Имя страны - ";
    dealer.country.countryName = safeGetline(in, true);
    cout << "Дата (YYYY-MM-DD) - ";
    dealer.country.time = readDate(in);
    cout << "Введите адресс: ";
    dealer.address = safeGetline(in, true);

    return in;
}

Dealer& Dealer::operator=(Dealer& dealer)
{
    if(this != &dealer)
    {
        static_cast<Employer&>(*this) = static_cast<Employer&>(dealer);
        static_cast<Tourist&>(*this) =  static_cast<Tourist&>(dealer);
        this->address = dealer.address;
    }

    return *this;
}

bool Dealer::operator==(const Dealer& other) const
{
    return this->Person::operator==(other);
}

bool Dealer::operator<(const Dealer& other) const
{
    return this->Person::operator<(other);
}

void Dealer::setAddress(string add)
{
    this->address = add;
}

string Dealer::getAddress() const
{
    return this->address;
}

Dealer& Dealer::addDealer(int& i)
{
    Dealer dealer;
    cout << (i + 1) << ". Добавить дилера: " << endl;
    cin >> dealer;
    this[i++] = dealer;

    return *this;
}

void Dealer::updateFields(int choiceField)
{
    string address;
    
    if(choiceField <= 5)
    {
        if(choiceField <= 2)
        {
            this->Person::updateFields(choiceField);
        } else if(3 <= choiceField <= 5)
        {
            this->Employer::updateFields(choiceField); 
        }
        return;
    }

    switch(choiceField)
    {
        case 6:
        {
            cout << "Новый номер паспорта: ";
            passport = getValidPassword(cin);
            this->setPassport(passport);
            break;
        }
        case 7:
        {
            cout << "Новое название страны: ";
            country.countryName = safeGetline(cin, true);
            country.time = this->getCountry().time;
            this->setCountry(country);
            break;   
        }
        case 8:
        {
            cout << "Новая дата визита(YYYY-MM-DD): ";
            country.time = readDate(cin);
            country.countryName = this->getCountry().countryName;
            this->setCountry(country);
            break;   
        }
        case 9:
        {
            cout << "Новый адресс: ";
            address = safeGetline(cin, true);
            this->setAddress(address);
            break;   
        }
    }
}

void Dealer::printHeader() const {
    cout << left;
    cout << "| " << setw(4) << "Имя" << " | " << setw(12) << "Дата рождения" << " | " << setw(7) << "Лицензия" << " | " << setw(7) << "Сумма налога" << " | " << setw(12) << "Дата налога" << " | " << setw(8) << "Паспорт" << " | " << setw(7) << "Страна" << " | " << setw(12) << "Дата визита" << " | " << setw(7) << "Адресс" << " |" << endl;
}

void Dealer::printTable() const {
    char birthdayStr[11], taxDateStr[11], visitDateStr[11];
    sprintf(birthdayStr, "%02d.%02d.%04d", birthday.day, birthday.month, birthday.year);
    sprintf(taxDateStr, "%02d.%02d.%04d", taxe.time.day, taxe.time.month, taxe.time.year);
    sprintf(visitDateStr, "%02d.%02d.%04d", country.time.day, country.time.month, country.time.year);
    char taxSumStr[20];
    sprintf(taxSumStr, "%.2f", taxe.sum);
    
    cout << left;
    cout << "| " << setw(4) << name << " | " << setw(12) << birthdayStr << " | " << setw(7) << license << " | " << setw(7) << taxSumStr << " | " << setw(12) << taxDateStr << " | " << setw(8) << passport << " | " << setw(7) << country.countryName << " | " << setw(12) << visitDateStr << " | " << setw(7) << address << " |" << endl;
}