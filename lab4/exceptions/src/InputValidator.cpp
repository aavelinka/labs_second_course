#include "../include/InputValidator.h"
#include "../include/InputException.h"
#include <cctype>
#include <ctime>
#include <regex>

bool containsOnly(const string& str, const regex& pattern)
{
    return regex_match(str, pattern);
}

bool isEmptyOrWhitespace(const string& str) 
{
    if (str.empty()) 
    {
        return true;
    }
    for (char c : str) 
    {
        if (!isspace(static_cast<unsigned char>(c))) 
        {
            return false;
        }
    }
    return true;
}

string safeGetline(istream& is, bool isRussian) {
    string input;
    bool valid = false;

    do {

        if (!getline(is, input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Попробуйте снова.\n";
            continue;
        }

        try {
            if (input.empty()) {
                throw InputException(5, "Пустой ввод. Пожалуйста, введите не пустую строку.");
            }

            bool isValid = false;
            if (!isRussian) {
                isValid = isEnglishOnly(input);
                if (!isValid) {
                    throw InputException(6, "Недопустимый ввод. Строка должна состоять только из латиницы, пробелов, дефисов. Got: " + input);
                }
            } else if (isRussian) {
                isValid = isRussianOnly(input);
                if (!isValid) {
                    throw InputException(7, "Недопустимый ввод. Строка должна состоять только из русских букв, пробелов, дефисов. Got: " + input);
                }
            }

            valid = true;

        } catch (const InputException& e) {
            cout << "Ошибка: " << e.what() << "\n";
            valid = false;
        }

    } while (!valid);

    return input;
}

bool isEnglishOnly(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isalpha(c) && c != ' ' && c != '-') {
            return false;
        }
        if (isalpha(c) && !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}

bool isRussianOnly(const string& str) {
    if (str.empty()) return false;
    for (unsigned char c : str) {
        if (c < 128) {
            if (isalpha(c) && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                return false;
            }
            if (!isspace(c) && c != '-') {
            }
        } else {
        }
    }
    return true;
}

string getValidPassword(istream& stream)
{
    string password;
    bool valid = false;

    do
    {
        try
        {
            if (!getline(stream, password))
            {
                stream.clear();
                throw InputException(400, "Ошибка чтения потока для пароля. Попробуйте снова.");
            }

            if (isEmptyOrWhitespace(password))
            {
                throw InputException(401, "Строка не может быть пустой. Повторите.");
            }
            
            if (password.length() >= 6)
            {
                valid = true;
                return password;
            }

            throw InputException(402, "Строка должна содержать не менее 6 символов. Повторите ввод.");
        }
        catch (const InputException& e)
        {
            cout << "Ошибка: " << e.what() << "\n";
            valid = false;
        }
    } while (!valid);

    return password;
}

Date readDate(istream& stream)
{
    string dateStr;
    Date date;
    
    time_t now = time(0);
    tm* ltm = localtime(&now);
    Date currentDate;  
    currentDate.day = ltm->tm_mday;
    currentDate.month = 1 + ltm->tm_mon;
    currentDate.year = 1900 + ltm->tm_year;
    
    while(true)
    {
        try
        {
            if (!getline(stream, dateStr))
            {
                throw std::runtime_error("Конец потока ввода."); 
            }
            
            if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
            {
                throw InputException(500, "Некорректный формат даты. Ожидался YYYY-MM-DD.");
            }
            
            date = Date::fromString(dateStr); 
            
            if (date.year < 1999 || date > currentDate || 
                date.month < 1 || date.month > 12 || 
                date.day < 1 || date.day > 31)
            {
                throw InputException(501, "Некорректные значения даты (год, месяц или день).");
            }

            if (date > currentDate)
            {
                throw InputException(502, "Дата не может быть в будущем.");
            }
            
            return date;

        }
        catch (const InputException& e)
        {
            cout << "Ошибка: " << e.what() << "\n";
        }
        catch (const std::exception& e)
        {
            cout << "Ошибка: " << e.what() << "\n";
        }
    }
}