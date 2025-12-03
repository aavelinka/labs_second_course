#include "Tourist.h"
#include "../exceptions/include/InputValidator.h"
#include <cstdio>

ostream& operator<<(ostream& out, Tourist& tourist)
{
    out << static_cast<Person&>(tourist) << " " << tourist.passport << " "
    << tourist.country.countryName << " " << tourist.country.time << endl;

    return out;
}

istream& operator>>(istream& in, Tourist& tourist)
{
    in >> static_cast<Person&>(tourist);
    cout << "Введите номер паспорта: ";
    tourist.passport = getValidPassword(in);
    cout << "Введите страну(название и дату): " << endl;
    cout << "Название страны(на русском): "; 
    tourist.country.countryName = safeGetline(in, true);
    cout << "Дата (YYYY-MM-DD): ";
    tourist.country.time = readDate(in);

    return in;
}

Tourist& Tourist::operator=(Tourist& tourist)
{
    if(this != &tourist)
    {
        static_cast<Person&>(*this) = static_cast<Person&>(tourist);
        this->passport = tourist.passport;
        this->country = tourist.country;
    }

    return *this;
}

bool Tourist::operator==(const Tourist& other) const
{
    return this->Person::operator==(other);
}

bool Tourist::operator<(const Tourist& other) const
{
    return this->Person::operator<(other);
}

void Tourist::setPassport(string p)
{
    this->passport = p;
}

string Tourist::getPassport() const
{
    return this->passport;
}

void Tourist::setCountry(Countries c)
{
    this->country = c;
}

Countries Tourist::getCountry() const
{
    return country;
}

Tourist& Tourist::addTourist(int& i)
{
    Tourist tourist;
    cout << (i + 1) << ". Добавить туриста: " << endl;
    cin >> tourist;
    this[i++] = tourist;

    return *this;
}

void Tourist::updateFields(int choiceField)
{
    string passport;
    Countries country;
    
    if(choiceField <= 2)
    {
        this->Person::updateFields(choiceField);
        return;
    }

    switch(choiceField)
    {
        case 3:
        {
            cout << "Новый паспорт: ";
            passport = getValidPassword(cin);
            this->setPassport(passport);
            break;
        }
        case 4:
        {
            cout << "Новое название страны: ";
            country.countryName = safeGetline(cin, true);
            country.time = this->getCountry().time;
            this->setCountry(country);
            break;   
        }
        case 5:
        {
            cout << "Новая дата посещения(YYYY-MM-DD): ";
            country.time = readDate(cin);
            country.countryName = this->getCountry().countryName;
            this->setCountry(country);
            break;   
        }
    }
}

void Tourist::printHeader() const {
    cout << left;
    cout << "| " << setw(4) << "Имя" << " | " << setw(12) << "Дата рождения" << " | " << setw(7) << "Лицензия" << " | " << setw(7) << "Налог" << " | " << setw(12) << "Дата налога" << " | " << setw(8) << "Пароль" << " | " << setw(7) << "Страна" << " | " << setw(12) << "Дата визита" << " | " << setw(7) << "Адресс" << " |" << endl;
}

void Tourist::printTable() const {
    char birthdayStr[11], visitDateStr[11];
    sprintf(birthdayStr, "%02d.%02d.%04d", birthday.day, birthday.month, birthday.year);
    sprintf(visitDateStr, "%02d.%02d.%04d", country.time.day, country.time.month, country.time.year);
    
    cout << left;
    cout << "| " << setw(4) << name << " | " << setw(12) << birthdayStr << " | " << setw(7) << " - " << " | " << setw(7) << " - " << " | " << setw(12) << " - " << " | " << setw(8) << passport << " | " << setw(7) << country.countryName << " | " << setw(12) << visitDateStr << " | " << setw(7) << " - " << " |" << endl;
}
