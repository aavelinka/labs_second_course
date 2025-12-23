#include "Person.h"
#include "../Algorithm.h"
#include "../exceptions/include/FileException.h"

string Data::toString() const
{
    stringstream ss;
    ss << setfill('0') << setw(4) << year << "-" 
       << setfill('0') << setw(2) << month << "-" 
       << setfill('0') << setw(2) << day;

    return ss.str();
}

Data Data::fromString(const string& dateStr)
{
    Data date = {0, 0, 0};

    date.year = stoi(dateStr.substr(0, 4));
    date.month = stoi(dateStr.substr(5, 2));
    date.day = stoi(dateStr.substr(8, 2));

    return date;
}

ostream& operator<<(ostream& os, const Data& date)
{
    os << date.toString();

    return os;
}

istream& operator>>(istream& is, Data& date)
{
    string dateStr;
    if (getline(is, dateStr, '|'))
    {
        date = Data::fromString(dateStr);
    }
    return is;
}

SearchMode Person::currentSearchMode = FULL_MATCH;

ostream& operator<<(ostream& out, Person& person)
{
    out << person.name << person.birthday;

    return out;
}

istream& operator>>(istream& in, Person& person)
{
    cout << "Введите имя: " ;
    person.name = isUpp(in, true);
    cout << "введите дату рождения(YYYY-MM-DD): ";
    person.birthday = readDate(in);

    return in;
}

Person& Person::operator=(Person& person)
{
    if(this != &person)
    {
        this->name = person.name;
        this->birthday = person.birthday;
    }

    return *this;
}

void Person::setName(string n)
{
    this->name = n;
}

string Person::getName() const
{
    return this->name;
}

void Person::setBirthday(Data countineus)
{
    this->birthday = countineus;
}

Data Person::getBirthday() const
{
    return this->birthday;
}

void Person::updateFields(int choiceField) 
{
    string name;
    Data bd;
    
    switch(choiceField)
    {
        case 1:
        {
            cout << "Новое имя: ";
            name = isUpp(cin, true);
            this->setName(name);
            break;
        }
        case 2:
        {
            cout << "Новый день рождения(YYYY-MM-DD): ";
            bd = readDate(cin);
            this->setBirthday(bd);
            break;   
        }
    }
}

bool Person::operator==(const Person& other) const
{
    if (currentSearchMode == FULL_MATCH) 
    {
        return (name == other.name) &&
               birthday.day == other.birthday.day &&
               birthday.month == other.birthday.month &&
               birthday.year == other.birthday.year;
    } else if (currentSearchMode == NAME) 
    {
        return (name == other.name);
    } else if (currentSearchMode == BIRTHDAY)
    {
        return birthday.day == other.birthday.day &&
               birthday.month == other.birthday.month &&
               birthday.year == other.birthday.year;
    } else if (currentSearchMode == BIRTH_YEAR) 
    {
        return birthday.year == other.birthday.year;
    }
    return false;
}

bool Person::operator<(const Person& other) const
{
    if (currentSearchMode == NAME)
    {
        return (name < other.name);
    } else if (currentSearchMode == BIRTHDAY)
    {
        if (birthday.year != other.birthday.year) 
        {
            return birthday.year < other.birthday.year;
        } else if (birthday.month != other.birthday.month)
        {
            return birthday.month < other.birthday.month;
        } else
        {
            return birthday.day < other.birthday.day;
        }
    } else if (currentSearchMode == BIRTH_YEAR)
    {
        return birthday.year < other.birthday.year;
    }
    return false;
}

void Person::fieldBy()
{
    static const string personOptions[2] = {
        "1. Имя",
        "2. День рождения",
    };
    drawMenu("Поля", personOptions, 2);
}

void Person::saveTextRecord(ostream& os) const
{
    os << name << ' ' << birthday.day << ' ' << birthday.month << ' ' << birthday.year;
}

void Person::loadFromText(istream& is)
{
    Data b{};
    string n;
    is >> n >> b.day >> b.month >> b.year;
    if (!is)
    {
        throw FileException("Corrupted person text record");
    }
    setName(n);
    setBirthday(b);
}

void Person::saveBinaryRecord(ostream& os) const
{
    int len = static_cast<int>(name.size());
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    if (len > 0)
    {
        os.write(name.data(), len);
    }
    os.write(reinterpret_cast<const char*>(&birthday.day), sizeof(birthday.day));
    os.write(reinterpret_cast<const char*>(&birthday.month), sizeof(birthday.month));
    os.write(reinterpret_cast<const char*>(&birthday.year), sizeof(birthday.year));
}

void Person::loadFromBinary(istream& is)
{
    int len = 0;
    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is)
    {
        throw FileException("Corrupted person binary record");
    }

    string n;
    if (len > 0)
    {
        n.resize(static_cast<size_t>(len));
        is.read(&n[0], len);
    }

    Data b{};
    is.read(reinterpret_cast<char*>(&b.day), sizeof(b.day));
    is.read(reinterpret_cast<char*>(&b.month), sizeof(b.month));
    is.read(reinterpret_cast<char*>(&b.year), sizeof(b.year));
    if (!is)
    {
        throw FileException("Corrupted person binary record");
    }

    setName(n);
    setBirthday(b);
}
