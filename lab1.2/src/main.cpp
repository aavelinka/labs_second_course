#include "class_String.h"

void MenuOperation(int& option)
{
    cout << "\n=== МЕНЮ ОПЕРАЦИЙ СО СТРОКАМИ ===" << endl;
    cout << "1. Сложение строк" << endl;
    cout << "2. Вычитание строк" << endl;
    cout << "3. Пересечение строк" << endl;
    cout << "4. Умножение строки на число" << endl;
    cout << "5. Кодирование строки" << endl;
    cout << "6. Раскодирование строки" << endl;
    cout << "7. Возвращение подстроки" << endl;
    cout << "8. Возвращение символа по индексу" << endl;
    cout << "9. Выход" << endl;
    cout << "Выберите операцию (1-9): ";

    cin >> option;
}

void Operation(int option)
{
    int number;
    if(option >= 1 && option <= 3)
    {
        cout << "Введите кол-во строк: ";
        cin >> number;
    }
    rewind(stdin); 

    switch (option)
    {
    case 1:
        {
            String* str = new String[number];
            for(int i = 0; i < number; ++i)
            {
                cout << i + 1 << ". Строка: ";
                cin >> str[i];
            }

            String Result(str[0]);
            for(int i = 1; i < number; ++i)
            {
                if(i != number - 1)
                {
                    cout << str[i] << "+";
                }
                else 
                {
                    cout << str[i] << "=";
                }

                Result += str[i];
                //Result = Result + str[i];
            }

            cout << Result;
            break;
        }
    case 2:
        {
            String* str = new String[number];
            for(int i = 0; i < number; ++i)
            {
                cout << "Строка" << i + 1 << ":";
                cin >> str[i];
            }
            
            String Result(str[0]);
            for(int i = 1; i < number; ++i)
            {
                if(i != number - 1)
                {
                    cout << str[i] << "-";
                }
                else 
                {
                    cout << str[i] << "=";
                }

                Result -= str[i];
                //Result = Result - str[i];
            }

            cout << Result;
            break;
        }
    case 3:
        {
            String* str = new String[number];
            for(int i = 0; i < number; ++i)
            {
                cout << "Строка" << i + 1 << ":";
                cin >> str[i];
            }
            
            String Result(str[0]);
            for(int i = 1; i < number; ++i)
            {
                if(i != number - 1)
                {
                    cout << str[i] << "&";
                }
                else 
                {
                    cout << str[i] << "=";
                }

                Result = Result & str[i];
            }

            cout << Result;
            break;
        }
    case 4:
        {

            break;
        }
    case 5:
        {
            break;
        }
    case 6:
        {
            break;
        }
    case 7:
        {
            break;
        }
    case 8:
        {
            break;
        }
    }
}

int main()
{
    int choice;
    do
    {
        int option;
        MenuOperation(option);
        if(option == 9)
        {
            break;
        }
        Operation(option);

        cout << "Вы хотите продолжить?(ДА - 1, НЕТ - 0)\nВаш выбор:";
        cin >> choice;
        
    } while (choice == 1);
    
    cout << "Спасибо за работу!<3";
    return 0;
}