#include "../include/Person.h"
#include "../exceptions/include/InputValidator.h"

string Date::toString() const
{
    stringstream ss;
    ss << setfill('0') << setw(4) << year << "-" 
       << setfill('0') << setw(2) << month << "-" 
       << setfill('0') << setw(2) << day;
    return ss.str();
}

Date Date::fromString(const string& dateStr)
{
    Date date = {0, 0, 0};
    try
    {
        date.year = stoi(dateStr.substr(0, 4));
        date.month = stoi(dateStr.substr(5, 2));
        date.day = stoi(dateStr.substr(8, 2));
    }
    catch (...)
    {
    }
    return date;
}

ostream& operator<<(ostream& os, const Date& date)
{
    os << date.toString();
    return os;
}

istream& operator>>(istream& is, Date& date)
{
    date = readDate(is);
    return is;
}

SearchMode Person::currentSearchMode = FULL_MATCH;

ostream& operator<<(ostream& out, Person& person)
{
    out << person.name << ' ' << person.birthday.day << '.' << person.birthday.month << '.' 
    << person.birthday.year << endl;

    return out;
}

istream& operator>>(istream& in, Person& person)
{
    cout << "Введите имя(на русском): " ;
    person.name = safeGetline(in, true);
    cout << "Введите дату рождения(YYYY-MM-DD): ";
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

void Person::setBirthday(Date countineus)
{
    this->birthday = countineus;
}

Date Person::getBirthday() const
{
    return this->birthday;
}

void Person::updateFields(int choiceField) 
{
    string newName;
    Date bd;
    
    switch(choiceField)
    {
        case 1:
        {
            cout << "Введите новое имя: ";
            name = safeGetline(cin, true);
            this->setName(name);
            break;
        }
        case 2:
        {
            cout << "Введите новую дату рождения(YYYY-MM-DD): ";
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
        return (this->name == other.name) &&
               (this->birthday == other.birthday);
    } else if (currentSearchMode == NAME) 
    {
        return (name == other.name);
    } else if (currentSearchMode == BIRTHDAY)
    {
        return this->birthday == other.birthday;
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
        if (this->birthday.year != other.birthday.year) 
        {
            return this->birthday.year < other.birthday.year;
        } else if (birthday.month != other.birthday.month)
        {
            return birthday.month < other.birthday.month;
        } else
        {
            return birthday.day < other.birthday.day;
        }
    } 

    return false;
}
