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
    T value;
    string line;
    while(true)
    {
        try
        {
            stream >> value;
            if (!getline(stream, line))
            {
                if (stream.eof())
                {
                    throw runtime_error("Конец потока ввода."); 
                }
                stream.clear();
                throw InputException(100, "Ошибка чтения строки.");
            }
            
            stringstream ss(line);
            if (ss >> value && ss.eof())
            {
                if (value >= min && value <= max)
                {
                    return value;
                }
                else
                {
                    throw InputException(200, "Число вне допустимого диапазона");
                }
            }
            else
            {
                throw InputException(201, "Некорректный ввод. Ожидалось число.");
            }
        }
        catch (const InputException& e)
        {
            cout << "Error: " << e.what() << "\n";
        }
    }
}

string safeGetline(istream& is, bool isRussianOnly);
string getValidPassword(istream& stream);
Data readDate(istream& stream);
bool isRussianOnly(const string& str);
bool isEnglishOnly(const string& str);
string isUpp(istream& is, bool isRussian);

#endif