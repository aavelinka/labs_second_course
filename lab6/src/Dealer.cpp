#include "Dealer.h"
#include "../Algorithm.h"
#include "../exceptions/include/FileException.h"
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
    cout << "Введите пасспорт: ";
    dealer.passport = getValidPassword(in);
    cout << "Введите страну(имя и даты): " << endl;
    cout << "Имя страны - ";
    dealer.country.countryName = isUpp(in, true);
    cout << "Дата(YYYY-MM-DD) - ";
    dealer.country.time = readDate(in);
    cout << "Введите адресс: ";
    dealer.address = isUpp(in, true);

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
    cout << (i + 1) << ". Add dealer: " << endl;
    cin >> dealer;
    this[i++] = dealer;

    return *this;
}

// char Dealer::editPunkt()
// {
//     cout << "-------------------------" << endl;
//     cout << "| 1. Edit name          |" << endl;
//     cout << "| 2. Edit birthday      |" << endl;
//     cout << "| 3. Edit license       |" << endl;
//     cout << "| 4. Edit taxe          |" << endl;
//     cout << "| 5. Edit passport      |" << endl;
//     cout << "| 6. Edit country       |" << endl;
//     cout << "| 7. Edit address       |" << endl;
//     cout << "| 8. Edit all           |" << endl;
//     cout << "-------------------------" << endl;
//     char option;
//     cin >> option;
//     return option;
// }

// Dealer& Dealer::editPerson()
// {
//     cout << "What the dealer do you want to edit?\nChoice: ";
//     int numberDealer;
//     cin >> numberDealer;
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
//         char newPassport[8];
//         cout << "Enter new data to passport: ";
//         cin >> newPassport;
//         this->setPassport(newPassport);
//         break;
//     }
//     case '6':
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
//     case '7':
//     {
//         char newAddress[30];
//         cout << "Enter new address: ";
//         int i = 0;
//         while(newAddress[i] != '\n')
//         {
//             cin >> newAddress;
//             ++i;
//         }
//         this->setAddress(newAddress);
//         break;
//     }
//     case '8':
//     {
//         Dealer newDealer;
//         cin >> newDealer;
//         *this = newDealer;
//         break;
//     }
//     }
//     return *this;
// }

// void Dealer::printHeader() {
//     cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
//     cout << "|" << "Delaler inforamtion" << setw(164) << "|"<< endl;
//     cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
//     cout << "| " << setw(28) << left << "Name" << " | " << setw(10) << left << "Birthday" << " | " << setw(28) << left << "License" << " | " << setw(10) << left << "Tax Sum" << " | " << setw(10) << left << "Tax Date" << " | " << setw(8) << left << "Passport" << " | " << setw(15) << left << "Country" << " | " << setw(10) << left << "Visit Date" << " | " << setw(37) << left << "Address" << " |" << endl;
//     cout << "-" << setw(31) << setfill('-') << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setw(13) << "" << "-" << setw(13) << "" << "-" << setw(11) << "" << "-" << setw(18) << "" << "-" << setw(13) << "" << "-" << setw(31) << "" << "-" << setfill(' ') << endl;
// }

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
            cout << "Новый паспорт: ";
            passport = getValidPassword(cin);
            this->setPassport(passport);
            break;
        }
        case 7:
        {
            cout << "Новое имя страны: ";
            country.countryName = isUpp(cin, true);
            country.time = this->getCountry().time;
            this->setCountry(country);
            break;   
        }
        case 8:
        {
            cout << "Новая дата посещения(YYYY-MM-DD): ";
            country.time = readDate(cin);
            country.countryName = this->getCountry().countryName;
            this->setCountry(country);
            break;   
        }
        case 9:
        {
            cout << "Новый адресс: ";
            address = isUpp(cin, true);
            this->setAddress(address);
            break;   
        }
    }
}

void Dealer::printHeader() const {
    cout << left;
    cout << "| " << setw(12) << "Name" << " | " << setw(12) << "Birthday" << " | " << setw(7) << "License" << " | " << setw(7) << "Tax Sum" << " | " << setw(12) << "Tax Date" << " | " << setw(8) << "Passport" << " | " << setw(7) << "Country" << " | " << setw(12) << "Visit Date" << " | " << setw(7) << "Address" << " |" << endl;
}

void Dealer::printTable() const {
    char birthdayStr[11], taxDateStr[11], visitDateStr[11];
    sprintf(birthdayStr, "%02d.%02d.%04d", birthday.day, birthday.month, birthday.year);
    sprintf(taxDateStr, "%02d.%02d.%04d", taxe.time.day, taxe.time.month, taxe.time.year);
    sprintf(visitDateStr, "%02d.%02d.%04d", country.time.day, country.time.month, country.time.year);
    char taxSumStr[20];
    sprintf(taxSumStr, "%.2f", taxe.sum);
    
    cout << left;
    cout << "| " << setw(12) << name << " | " << setw(12) << birthdayStr << " | " << setw(7) << license << " | " << setw(7) << taxSumStr << " | " << setw(12) << taxDateStr << " | " << setw(8) << passport << " | " << setw(7) << country.countryName << " | " << setw(12) << visitDateStr << " | " << setw(7) << address << " |" << endl;
}

void Dealer::fieldBy(){
    static const string dealerOptions[9] = {
        "1. Имя",
        "2. День рождения",
        "3. Лицензия",
        "4. Сумма налога",
        "5. Дата налога",
        "6. Паспорт",
        "7. Имя страны",
        "8. Дата посещения",
        "9. Адресс"
    };
    drawMenu("Поля", dealerOptions, 9);
}

void Dealer::saveTextRecord(ostream& os) const
{
    Person::saveTextRecord(os);
    os << ' ' << license << ' ' << taxe.sum << ' ' << taxe.time.day << ' '
       << taxe.time.month << ' ' << taxe.time.year << ' '
       << passport << ' ' << country.countryName << ' ' << country.time.day << ' '
       << country.time.month << ' ' << country.time.year << ' ' << address << '\n';
}

void Dealer::loadFromText(istream& is)
{
    Person::loadFromText(is);
    string lic;
    Taxes t{};
    string pass;
    Countries c{};
    string addr;
    is >> lic >> t.sum >> t.time.day >> t.time.month >> t.time.year
       >> pass >> c.countryName >> c.time.day >> c.time.month >> c.time.year >> addr;
    if (!is)
    {
        throw FileException("Corrupted dealer text record");
    }
    setLicense(lic);
    setTaxes(t);
    setPassport(pass);
    setCountry(c);
    setAddress(addr);
}

void Dealer::saveBinaryRecord(ostream& os) const
{
    Person::saveBinaryRecord(os);

    int len = static_cast<int>(license.size());
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    if (len > 0)
    {
        os.write(license.data(), len);
    }

    os.write(reinterpret_cast<const char*>(&taxe.sum), sizeof(taxe.sum));
    os.write(reinterpret_cast<const char*>(&taxe.time.day), sizeof(taxe.time.day));
    os.write(reinterpret_cast<const char*>(&taxe.time.month), sizeof(taxe.time.month));
    os.write(reinterpret_cast<const char*>(&taxe.time.year), sizeof(taxe.time.year));

    len = static_cast<int>(passport.size());
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

    len = static_cast<int>(address.size());
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    if (len > 0)
    {
        os.write(address.data(), len);
    }
}

void Dealer::loadFromBinary(istream& is)
{
    Person::loadFromBinary(is);

    int len = 0;
    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is)
    {
        throw FileException("Corrupted dealer binary record");
    }

    string lic;
    if (len > 0)
    {
        lic.resize(static_cast<size_t>(len));
        is.read(&lic[0], len);
    }

    Taxes t{};
    is.read(reinterpret_cast<char*>(&t.sum), sizeof(t.sum));
    is.read(reinterpret_cast<char*>(&t.time.day), sizeof(t.time.day));
    is.read(reinterpret_cast<char*>(&t.time.month), sizeof(t.time.month));
    is.read(reinterpret_cast<char*>(&t.time.year), sizeof(t.time.year));

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is)
    {
        throw FileException("Corrupted dealer binary record");
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
        throw FileException("Corrupted dealer binary record");
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

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is)
    {
        throw FileException("Corrupted dealer binary record");
    }
    string addr;
    if (len > 0)
    {
        addr.resize(static_cast<size_t>(len));
        is.read(&addr[0], len);
    }

    if (!is)
    {
        throw FileException("Corrupted dealer binary record");
    }

    setLicense(lic);
    setTaxes(t);
    setPassport(pass);
    setCountry(c);
    setAddress(addr);
}
