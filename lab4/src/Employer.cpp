#include "Employer.h"
#include "../exceptions/include/InputValidator.h"
#include <cstdio>

ostream& operator<<(ostream& out, Employer& employer)
{
    out << static_cast<Person&>(employer) << " " << employer.license << " "
    << employer.taxe.sum << " " << employer.taxe.time << endl;

    return out;
}

istream& operator>>(istream& in, Employer& employer)
{
    in >> static_cast<Person&>(employer);
    cout << "Введите лицензию: ";
    employer.license = getValidPassword(cin);
    cout << "Введите налог(сумма и дата): " << endl;
    cout << "Сумма - ";
    employer.taxe.sum = getValidNumericValue(cin, 0, 10000);
    cout << "Дата(YYYY-MM-DD) - ";
    employer.taxe.time = readDate(cin);

    return in;
}

Employer& Employer::operator=(Employer& employer)
{
    if(this != &employer)
    {
        static_cast<Person&>(*this) = static_cast<Person&>(employer);
        this->license = employer.license;
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

void Employer::setLicense(string l)
{
    this->license = l;
}

string Employer::getLicense() const
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
    cout << (i + 1) << ". Добавить работника: " << endl;
    cin >> employer;
    this[i++] = employer;

    return *this;
}

void Employer::updateFields(int choiceField)
{
    string license;
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
            cout << "Новая лицензия: ";
            license = getValidPassword(cin);
            this->setLicense(license);
            break;
        }
        case 4:
        {
            cout << "Новая сумма налога: ";
            tax.sum = getValidNumericValue(cin, 0, 10000);
            tax.time = this->getTaxes().time;
            this->setTaxes(tax);
            break;   
        }
        case 5:
        {
            cout << "Новая дата налога (YYYY-MM-DD): ";
            cin >> tax.time.day >> tax.time.month >> tax.time.year;
            tax.sum = this->getTaxes().sum;
            this->setTaxes(tax);
            break;   
        }
    }
}

void Employer::printHeader() const {
    cout << left;
    cout << "| " << setw(12) << "Имя" << " | " << setw(12) << "Дата рождения" << " | " << setw(7) << "Лицензия" << " | " << setw(7) << "Сумма налога" << " | " << setw(12) << "Дата налога" << " | " << setw(8) << "Паспорт" << " | " << setw(7) << "Страна" << " | " << setw(12) << "Дата визита" << " | " << setw(7) << "Адресс" << " |" << endl;
}

void Employer::printTable() const {
    char birthdayStr[11], taxDateStr[11];
    sprintf(birthdayStr, "%02d.%02d.%04d", birthday.day, birthday.month, birthday.year);
    sprintf(taxDateStr, "%02d.%02d.%04d", taxe.time.day, taxe.time.month, taxe.time.year);
    char taxSumStr[20];
    sprintf(taxSumStr, "%.2f", taxe.sum);
    
    cout << left;
    cout << "| " << setw(12) << name << " | " << setw(12) << birthdayStr << " | " << setw(7) << license << " | " << setw(7) << taxSumStr << " | " << setw(12) << taxDateStr << " | " << setw(8) << " - " << " | " << setw(7) << " - " << " | " << setw(12) << " - " << " | " << setw(7) << " - " << " |" << endl;
}