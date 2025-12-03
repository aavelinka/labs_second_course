#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include "InputException.h"
#include "../../include/Person.h"
#include <limits>
#include <locale>
#include <stdexcept>
#include <tuple>

using namespace std;

template <typename T>
T getValidNumericValue(istream& stream, T min, T max)
{
    T value;
    string line;
    bool success = false;
    do
    {
        try
        {
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
                    success = true;
                    return value;
                }
                else
                {
                    stringstream err_ss;
                    err_ss << "Число вне допустимого диапазона (от " << fixed << setprecision(1) << min << " до " << max << ").";
                    throw InputException(200, err_ss.str());
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
            success = false;
        }
    } while (!success);
    return value;
}

string safeGetline(istream& is, bool isRussianOnly);
string getValidPassword(istream& stream);
Date readDate(istream& stream);
bool isRussianOnly(const string& str);
bool isEnglishOnly(const string& str);

#endif