#include "Person.h"

void Person::setName(char* n)
{
    strcpy(this->name, n);
}

const char* Person::getName() const
{
    return this->name;
}

void Person::setData(Data countineus)
{
    this->birthday.day = countineus.day;
    this->birthday.month = countineus.month;
    this->birthday.year = countineus.year;
}

Data Person::getData() const
{
    return this->birthday;
}

void Person::show()
{
    cout << "Name: " << this->name << endl;
    cout << "Birthday: " << this->birthday.day << "." << this->birthday.month << "." << this->birthday.year << endl;
}