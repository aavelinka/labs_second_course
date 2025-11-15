#include "Person.h"

SearchMode Person::currentSearchMode = FULL_MATCH;

ostream& operator<<(ostream& out, Person& person)
{
    out << person.name << ' ' << person.birthday.day << '.' << person.birthday.month << '.' 
    << person.birthday.year << endl;

    return out;
}

istream& operator>>(istream& in, Person& person)
{
    cout << "Enter name: " ;
    in >> person.name;
    cout << "Enter birthday(XX.YY.ZZZZ): ";
    in >> person.birthday.day >> person.birthday.month >> person.birthday.year;

    return in;
}

Person& Person::operator=(Person& person)
{
    if(this != &person)
    {
        strcpy(this->name, person.name);
        this->birthday.day = person.birthday.day;
        this->birthday.month = person.birthday.month;
        this->birthday.year = person.birthday.year;
    }

    return *this;
}

void Person::setName(char* n)
{
    strcpy(this->name, n);
}

const char* Person::getName() const
{
    return this->name;
}

void Person::setBirthday(Data countineus)
{
    this->birthday.day = countineus.day;
    this->birthday.month = countineus.month;
    this->birthday.year = countineus.year;
}

Data Person::getBirthday() const
{
    return this->birthday;
}

bool Person::operator==(const Person& other) const
{
    if (currentSearchMode == FULL_MATCH) {
        return strcmp(name, other.name) == 0 &&
               birthday.day == other.birthday.day &&
               birthday.month == other.birthday.month &&
               birthday.year == other.birthday.year;
    } else if (currentSearchMode == NAME) {
        return strcmp(name, other.name) == 0;
    } else if (currentSearchMode == BIRTHDAY) {
        return birthday.day == other.birthday.day &&
               birthday.month == other.birthday.month &&
               birthday.year == other.birthday.year;
    } else if (currentSearchMode == BIRTH_YEAR) {
        return birthday.year == other.birthday.year;
    }
    return false;
}

bool Person::operator<(const Person& other) const
{
    if (currentSearchMode == NAME) {
        return strcmp(name, other.name) < 0;
    } else if (currentSearchMode == BIRTHDAY) {
        if (birthday.year != other.birthday.year) {
            return birthday.year < other.birthday.year;
        } else if (birthday.month != other.birthday.month) {
            return birthday.month < other.birthday.month;
        } else {
            return birthday.day < other.birthday.day;
        }
    } else if (currentSearchMode == BIRTH_YEAR) {
        return birthday.year < other.birthday.year;
    }
    return false;
}
