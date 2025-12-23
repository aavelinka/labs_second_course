#include "Tourist.h"
#include "../Algorithm.h"
#include "../exceptions/include/FileException.h"
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
    cout << "Введите данные для страны(имя и дата): " << endl;
    cout << "Имя страны - "; 
    tourist.country.countryName;
    cout << "Дата (YYYY-MM-DD) - ";
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
    // strcpy(this->country.countryName, c.countryName);
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

// char Tourist::editPunkt()
// {
//     cout << "-------------------------" << endl;
//     cout << "| 1. Edit name          |" << endl;
//     cout << "| 2. Edit birthday      |" << endl;
//     cout << "| 3. Edit passport      |" << endl;
//     cout << "| 4. Edit country       |" << endl;
//     cout << "| 5. Edit all           |" << endl;
//     cout << "-------------------------" << endl;
//     char option;
//     cin >> option;
//     return option;
// }

// Tourist& Tourist::editPerson()
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
//         char newPassport[8];
//         cout << "Enter new data to passport: ";
//         cin >> newPassport;
//         this->setPassport(newPassport);
//         break;
//     }
//     case '4':
//     {
//         Countries newCountry;
//         cout << "Enter new country(name and time): " << endl;
//         cout << "Name of country - ";
//         cin >> newCountry.countryName;
//         cout << "Time(XX.YY.ZZZZ) - ";
//         cin >> newCountry.time.day >> newCountry.time.month >> newCountry.time.year;
//         this->setCountry(newCountry);
//         break;
//     }
//     case '5':
//     {
//         Tourist newTourist;
//         cin >> newTourist;
//         *this = newTourist;
//         break;
//     }
//     }
//     return *this;
// }

// void Tourist::printHeader() {
//     cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(11) << "" << "+" << setw(18) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
//     cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(8) << left << "Passport" << " | " << setw(15) << left << "Country" << " | " << setw(10) << left << "Visit Date" << " |" << endl;
//     cout << "+" << setw(31) << setfill('-') << "" << "+" << setw(13) << "" << "+" << setw(11) << "" << "+" << setw(18) << "" << "+" << setw(13) << "" << "+" << setfill(' ') << endl;
// }

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
            cout << "Новое имя страны: ";
            country.countryName = isUpp(cin, true);
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
    cout << "| " << setw(12) << "Name" << " | " << setw(12) << "Birthday" << " | " << setw(7) << "License" << " | " << setw(7) << "Tax Sum" << " | " << setw(12) << "Tax Date" << " | " << setw(8) << "Passport" << " | " << setw(7) << "Country" << " | " << setw(12) << "Visit Date" << " | " << setw(7) << "Address" << " |" << endl;
}

void Tourist::printTable() const {
    char birthdayStr[11], visitDateStr[11];
    sprintf(birthdayStr, "%02d.%02d.%04d", birthday.day, birthday.month, birthday.year);
    sprintf(visitDateStr, "%02d.%02d.%04d", country.time.day, country.time.month, country.time.year);
    
    cout << left;
    cout << "| " << setw(12) << name << " | " << setw(12) << birthdayStr << " | " << setw(7) << " - " << " | " << setw(7) << " - " << " | " << setw(12) << " - " << " | " << setw(8) << passport << " | " << setw(7) << country.countryName << " | " << setw(12) << visitDateStr << " | " << setw(7) << " - " << " |" << endl;
}

void Tourist::fieldBy(){
    static const string touristOptions[5] = {
        "1. Имя",
        "2. День рождения",
        "3. Паспорт",
        "4. Имя страны",
        "5. Дата посещения"
    };
    drawMenu("Поля", touristOptions, 5);
}

void Tourist::saveTextRecord(ostream& os) const
{
    Person::saveTextRecord(os);
    os << ' ' << passport << ' ' << country.countryName << ' ' << country.time.day << ' '
       << country.time.month << ' ' << country.time.year << '\n';
}

void Tourist::loadFromText(istream& is)
{
    Person::loadFromText(is);
    string pass;
    Countries c{};
    is >> pass >> c.countryName >> c.time.day >> c.time.month >> c.time.year;
    if (!is)
    {
        throw FileException("Corrupted tourist text record");
    }
    setPassport(pass);
    setCountry(c);
}

void Tourist::saveBinaryRecord(ostream& os) const
{
    Person::saveBinaryRecord(os);
    int len = static_cast<int>(passport.size());
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    if (len > 0)
    {
        os.write(passport.data(), len);
    }

    len = static_cast<int>(country.countryName.size());
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    if (len > 0)
    {
        os.write(country.countryName.data(), len);
    }

    os.write(reinterpret_cast<const char*>(&country.time.day), sizeof(country.time.day));
    os.write(reinterpret_cast<const char*>(&country.time.month), sizeof(country.time.month));
    os.write(reinterpret_cast<const char*>(&country.time.year), sizeof(country.time.year));
}

void Tourist::loadFromBinary(istream& is)
{
    Person::loadFromBinary(is);

    int len = 0;
    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is)
    {
        throw FileException("Corrupted tourist binary record");
    }

    string pass;
    if (len > 0)
    {
        pass.resize(static_cast<size_t>(len));
        is.read(&pass[0], len);
    }

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is)
    {
        throw FileException("Corrupted tourist binary record");
    }

    string countryName;
    if (len > 0)
    {
        countryName.resize(static_cast<size_t>(len));
        is.read(&countryName[0], len);
    }

    Countries c{};
    c.countryName = countryName;
    is.read(reinterpret_cast<char*>(&c.time.day), sizeof(c.time.day));
    is.read(reinterpret_cast<char*>(&c.time.month), sizeof(c.time.month));
    is.read(reinterpret_cast<char*>(&c.time.year), sizeof(c.time.year));
    if (!is)
    {
        throw FileException("Corrupted tourist binary record");
    }

    setPassport(pass);
    setCountry(c);
}
