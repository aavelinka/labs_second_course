#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include "InputException.h"
#include "../../include/Person.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <locale>
#include <stdexcept>
#include <tuple>
struct Data;

using namespace std;

template <typename T>
T getValidNumericValue(istream& stream, T min, T max)
{
    T value{};
    int flags = 0;

    do
    {
        try
        {
            flags = 0;
            stream >> value;
            flags = static_cast<int>(stream.rdstate()); //состояние потока для проверки битов ошибок

            if (flags & ios::eofbit)
            {
                throw runtime_error("Конец потока ввода.");
            }

            if (flags & ios::failbit)
            {
                throw InputException(201, "Некорректный ввод. Ожидалось число.");
            }

            if (value < min || value > max)
            {
                throw InputException(200, "Число вне допустимого диапазона");
            }

            stream.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const InputException& e)
        {
            cout << "Error: " << e.what() << "\n";
            stream.clear();
            stream.ignore(numeric_limits<streamsize>::max(), '\n');
            flags = 1;
        }
    }
    while (flags);

    return value;
}

string safeGetline(istream& is, bool isRussianOnly);
string getValidPassword(istream& stream);
Data readDate(istream& stream);
bool isRussianOnly(const string& str);
bool isEnglishOnly(const string& str);
string isUpp(istream& is, bool isRussian);

#endif
