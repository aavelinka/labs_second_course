#pragma once

#include "include/Person.h"
#include "include/Deque.hpp"
#include "include/Dealer.h"
#include "exceptions/include/InputValidator.h"
#include <string.h>

Deque<Person*> myDeque;

class Algorithm
{
public:
    static void drawMenu(const string& title, const string options[], int numOptions) {
        int max_len = title.length();
        for (int i = 0; i < numOptions; i++) {
            if ((int)options[i].length() > max_len) 
            {
                max_len = options[i].length();
            }
        }
        max_len += 4;
        cout << "+" << string(max_len, '-') << "+" << endl;
        cout << "| " << title << string(max_len - title.length() - 1, ' ') << "|" << endl;
        cout << "+" << string(max_len, '-') << "+" << endl;
        for (int i = 0; i < numOptions; i++) {
            cout << "| " << options[i] << string(max_len - options[i].length() - 1, ' ') << "|" << endl;
        }
        cout << "+" << string(max_len, '-') << "+" << endl;
    }
    
    static void menu()
    {
        string options[7] = {"1. Добавить person", "2. Показать persons", "3. Редактирвоать person",
        "4. Удалить person", "5. Найти person", "6. Сортировать persons", "7. Выход"};
        drawMenu("MENU", options, 7);
    }
    
    static void addDeque(Person* person)
    {
        string options[3] = {"1. Добавить в начало", "2. Добавить в конец", "3. Выход"};
        drawMenu("MENU", options, 3);
        cout << "Выбор: ";
        int add;
        add = getValidNumericValue(cin, 1, 3);
    
        if(add == 1)
        {
            myDeque.pushFront(person);
        } else if(add == 2)
        {
            myDeque.pushBack(person);
        } else 
        {
            return;
        }
    }
    
    static void showDeque()
    {
        string options[3] = {"1. Показать начало", "2. Показать конец", "3. Выход"};
        drawMenu("MENU", options, 3);
        cout << "Выбор: ";
        int show;
        show = getValidNumericValue(cin, 1, 3);
    
        if(myDeque.isEmpty())
        {
            cout << "Пусто!" << endl;
            return;
        } else if (show == 3) 
        {
            return;
        } else
        {
            (myDeque.peekFirst())->printHeader();
            Deque<Person*> tmpDeque = myDeque;
            if(show == 1)
            {
                while(!tmpDeque.isEmpty())
                {
                    Person* p = tmpDeque.popFront();
                    if(p != nullptr)
                    {
                        p->printTable();
                    }
                }
            } else if(show == 2)
            {
                while(!tmpDeque.isEmpty())
                {
                    Person* p = tmpDeque.popBack();
                    if(p != nullptr)
                    {
                        p->printTable();
                    }
                }
            }
        }
    }
    
    static void modifyObject()
    {
        if(myDeque.isEmpty())
        {
            cout << "Пусто." << endl;
            return;
        } else 
        {
            string options[3] = {"1. Изменить начало", "2. Изменить конец", "3. Выход"};
            drawMenu("Выберите объект для изменения", options, 3);
            cout << "Выбор: ";
            int sideChoice;
            sideChoice = getValidNumericValue(cin, 1, 3);
            
            Person* person;
            if(sideChoice == 1)
            {
                person = myDeque.peekFirst();
            } else if(sideChoice == 2)
            {
                person = myDeque.peekLast();
            } else
            {
                return;
            }
            
            if(person == nullptr)
            {
                cout << "Ошибка: нет человека!" << endl;
                return;
            } else
            {
                Dealer* dealer = dynamic_cast<Dealer*>(person);
                Employer* employer = dynamic_cast<Employer*>(person);
                Tourist* tourist = dynamic_cast<Tourist*>(person);
                
                string options[2] = {"1. Изменить все данные", "2. Изменить особые поля"};
                drawMenu("Что изменить?", options, 2);
                cout << "Выбор: ";
                int modifyChoice;
                modifyChoice = getValidNumericValue(cin, 1, 2);
                
                if(modifyChoice == 1)
                {
                    if(dealer != nullptr)
                    {
                        cin >> *dealer;
                    }
                    else if(employer != nullptr)
                    {
                        cin >> *employer;
                    }
                    else if(tourist != nullptr)
                    {
                        cin >> *tourist;
                    }
                    return;
                } else
                {
                    int fieldChoice;
                    if(employer != nullptr)
                    {
                        string fieldOption[5] = {"1. Имя", "2. Дата рождения", "3. Лицензия", "4. Дата налога", "5. Сумма налога"};
                        drawMenu("Выберите поле", fieldOption, 5);
                        cout << "Выбор: ";
                        fieldChoice = getValidNumericValue(cin, 1, 5);
                    } else if(tourist != nullptr)
                    {
                        string fieldOption[5] = {"1. Имя", "2. Дата рождения", "3. Номер паспорта", "4. Дата визита", "5. Название страны"};
                        drawMenu("Выберите поле", fieldOption, 5);
                        cout << "Выбор: ";
                        fieldChoice = getValidNumericValue(cin, 1, 5);
                    }else if(dealer != nullptr)
                    {
                        string fieldOption[9] = {"1. Имя", "2. Дата рождения", "3. Лицензия", "4. Дата налога", "5. Сумма налога", "6. Номер паспорта", "7. Дата визита", "8. Название страны", "9. Адресс"};
                        drawMenu("Выберите поле", fieldOption, 9);
                        cout << "Выбор: ";
                        fieldChoice = getValidNumericValue(cin, 1, 9);
                    }
                    person->updateFields(fieldChoice);
                }
            }
        }
    }
    
    static void deleteDeque()
    {
        string options[3] = {"1. Удалить начало", "2. Удалить конец", "3. Выход"};
        drawMenu("Что удалить?", options, 3);
        cout << "Выбор: ";
        int del;
        del = getValidNumericValue(cin, 1, 3);
    
        if(del == 1)
        {
            Person* person = myDeque.popFront();
            delete person;
        } else if(del == 2)
        {
            Person* person = myDeque.popBack();
            delete person;
        } else 
        {
            return;
        }
    }
    
    static int choosePerson()
    {
        string fieldOption[5] = {"1. Работник", "2. Турист", "3. Дилер", "4. Выход"};
        drawMenu("Выберите человека", fieldOption, 4);
        cout << "Выбор: ";
        int choice;
        choice = getValidNumericValue(cin, 1, 4);
    
        return choice;
    }
    
    static void addPerson(int choice)
    {
        Person* person = nullptr;
        if(choice == 1) 
        {
            Employer* newEmployer = new Employer();
            cin >> *newEmployer;
            // cout << "create Employer" << endl;
            person = newEmployer;
    
        } else if(choice == 2) 
        {
            Tourist* newTourist = new Tourist();
            cin >> *newTourist;
            // cout << "create Tourist" << endl;
            person = newTourist;
        } else 
        {
            Dealer* newDealer = new Dealer();
            cin >> *newDealer;
            // cout << "create Dealer" << endl;
            person = newDealer;
        }
    
        addDeque(person);
        return;
    }
    
    static void searchDeque()
    {
        if(myDeque.isEmpty())
        {
            cout << "Пусто!" << endl;
            return;
        }
        
        string fieldOption[4] = {"1. Искать по имени", "2. Искать по дате рождения", "3. Искать по всему", "4. Выход"};
        drawMenu("Выберите метод поиска", fieldOption, 4);
        cout << "Выбор: ";
        int choice;
        choice = getValidNumericValue(cin, 1, 4);
        
        if(choice == 4)
        {
            return;
        } else
        {
            Person* searchPerson = new Employer();
            
            if(choice == 1)
            {
                cout << "Введите имя для поиска: ";
                string name;
                name = safeGetline(cin, true);
                searchPerson->setName(name.c_str());
                Person::setSearchMode(NAME);
            }
            else if(choice == 2)
            {
                cout << "Введите дату рождения(DD-MM-YYYY): ";
                Date bd;
                bd = readDate(cin);
                searchPerson->setBirthday(bd);
                Person::setSearchMode(BIRTHDAY);
            }
            else
            {
                cout << "Введите критерий для совпадения:" << endl;
                cout << "Введите имя: ";
                string name;
                name = safeGetline(cin, true);
                searchPerson->setName(name.c_str());
                cout << "Введите дату рождения(DD-MM-YYYY): ";
                Date bd;
                bd = readDate(cin);
                searchPerson->setBirthday(bd);
                Person::setSearchMode(FULL_MATCH);
            }
            
            Deque<Person*> results = myDeque.search(searchPerson);
            delete searchPerson;
            
            if(results.isEmpty())
            {
                cout << "Совпадения не найдены." << endl;
            }
            else
            {
                cout << "Результат поиска (" << results.size() << " совпадений):" << endl;
                results.peekFirst()->printHeader();
                Deque<Person*> tmpResults = results;
                while(!tmpResults.isEmpty())
                {
                    (*tmpResults.popFront()).printTable();
                }
            }
        }
    }
    
    static void sortDeque()
    {
        if(myDeque.isEmpty())
        {
            cout << "Нечего сортировать." << endl;
            return;
        }
        
        string fieldOption[3] = {"1. Сортировка по имени", "2. Сортировка по дате рождения", "3. Выход"};
        drawMenu("Выберите поле для сортировки", fieldOption, 3);
        cout << "Выбор: ";
        int choice;
        choice = getValidNumericValue(cin, 1, 3);
        
        if(choice == 1)
        {
            Person::setSearchMode(NAME);
            cout << "Сортировка по имени..." << endl;
        }
        else if(choice == 2)
        {
            Person::setSearchMode(BIRTHDAY);
            cout << "Сортировка по дате рождения..." << endl;
        }
        else
        {
            return;
        }
        
        myDeque.sort();
        cout << "Сортировка прошла успешно!." << endl;
        if(!myDeque.isEmpty())
        {
            myDeque.peekFirst()->printHeader();
            Deque<Person*> tmpDeque = myDeque;
            while(!tmpDeque.isEmpty())
            {
                (*tmpDeque.popFront()).printTable();
            }
        }
    }
    
    static void actionPerson(int action)
    {
        if(action == 1)
        {
            addPerson(choosePerson());
        } else if(action == 2)
        {
            showDeque();
        } else if(action == 3)
        {
            modifyObject();
        } else if(action == 4)
        {
            deleteDeque();
        } else if(action == 5)
        {
            searchDeque();
        } else if(action == 6)
        {
            sortDeque();
        }
    }

    static void run()
    {
        do
        {
            int action;
            menu();
            cout << "Выбор: ";
            action = getValidNumericValue(cin, 1, 7);
            if(action == 7)
            {
                break;
            } else 
            {
                actionPerson(action);
            }
    
        } while(true);
        
        while(!myDeque.isEmpty()) //ощичаем дек
        {
            Person* person = myDeque.popFront();
            delete person;
        }
    }
};