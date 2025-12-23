#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <filesystem>
#include <deque>
#include "exceptions/include/InputValidator.h"
#include "include/Dealer.h"
#include "include/Deque.tpp"
#include "repo/include/TextFile.h"
#include "repo/include/BinaryFile.h"

using namespace std;

using PersonDeque = Deque<Person*>;
using PersonIterator = typename PersonDeque::Iterator;

inline PersonIterator lastIterator(PersonDeque& deque) {
    PersonIterator last = deque.end();
    for (PersonIterator it = deque.begin(); it != deque.end(); ++it) {
        last = it;
    }
    return last;
}

void drawMenu(const string& title, const string options[], int numOptions);

template <typename T>
void addObject(PersonDeque& deque) {
    const string sideOptions[2] = {"1. Добавить вначало", "2. Добавить в конец"};
    drawMenu("Выберите сторону", sideOptions, 2);
    cout << "Выбор: ";
    int sideChoice = getValidNumericValue(cin, 1, 2);

    T* object = new T();
    cin >> *object;

    Person* basePtr = object;
    if (sideChoice == 1) {
        deque.pushFront(basePtr);
    } else {
        deque.pushBack(basePtr);
    }
}

template <typename T>
void removeObject(PersonDeque& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    const string options[2] = {"1. Удалить сначала", "2. Удалить сконца"};
    drawMenu("Удалить объект", options, 2);
    cout << "Выбор: ";
    int choice = getValidNumericValue(cin, 1, 2);

    Person* removed = (choice == 1) ? deque.popFront() : deque.popBack();
    delete removed;
}

void modifyObject(PersonDeque& deque);

template <typename T>
void peekObject(PersonDeque& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    const string options[2] = {"1. Показать первый", "2. Показать последний"};
    drawMenu("Показать объект", options, 2);
    cout << "Выбор: ";
    int choice = getValidNumericValue(cin, 1, 2);

    PersonIterator it = (choice == 1) ? deque.begin() : lastIterator(deque);
    if (it == deque.end()) {
        cout << "Пусто." << endl;
        return;
    }
    Person* obj = *it;

    if (obj != nullptr) {
        obj->printHeader();
        obj->printTable();
    }
}

template <typename T>
void printDeque(PersonDeque& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    PersonIterator it = deque.begin();
    if (it != deque.end() && *it != nullptr) {
        (*it)->printHeader();
    }

    for (; it != deque.end(); ++it) {
        Person* obj = *it;
        if (obj != nullptr) {
            obj->printTable();
        }
    }
}

template <typename T>
void searchInDeque(PersonDeque& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    const string searchOptions[5] = {
        "1. Искать по имени",
        "2. Искать по дате рождения",
        "3. Искать по году рождения",
        "4. Искать по полному совпадению",
        "5. Выход"
    };
    drawMenu("Выбор поиска", searchOptions, 5);
    cout << "Выбор: ";
    int choice = getValidNumericValue(cin, 1, 5);

    if (choice == 5) {
        return;
    }

    T* searchObj = new T();
    Data searchDate{};
    string searchName;

    switch (choice) {
        case 1:
            cout << "Введите имя для поиска: ";
            searchName = isUpp(cin,true);
            searchObj->setName(searchName);
            Person::setSearchMode(NAME);
            break;
        case 2:
            cout << "Введите дату рождения(YYYY-MM-DD): ";
            searchDate = readDate(cin);
            searchObj->setBirthday(searchDate);
            Person::setSearchMode(BIRTHDAY);
            break;
        case 3:
            cout << "Введите год рождения: ";
            searchDate.year = getValidNumericValue(cin, 1999, 2025);
            searchDate.day = 0;
            searchDate.month = 0;
            searchObj->setBirthday(searchDate);
            Person::setSearchMode(BIRTH_YEAR);
            break;
        case 4:
            cout << "Введите имя: ";
            searchName = isUpp(cin, true);
            searchObj->setName(searchName);
            cout << "Введите дату рождения(YYYY-MM-DD): ";
            searchDate = readDate(cin);
            searchObj->setBirthday(searchDate);
            Person::setSearchMode(FULL_MATCH);
            break;
    }

    Deque<Person*> searchResults = deque.search(searchObj);
    delete searchObj;
    Person::setSearchMode(FULL_MATCH);

    if (searchResults.isEmpty()) {
        cout << "Совпадений не найдено." << endl;
    } else {
        cout << "найденные результаты (" << searchResults.size() << " найдено):" << endl;
        printDeque<T>(searchResults);
    }
}

template <typename T>
void sortDequeByField(PersonDeque& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст. нечего сортировать." << endl;
        return;
    }

    const string sortOptions[4] = {
        "1. Сортировать по имени",
        "2. Сртировать по дате рождения",
        "3. Сортировать по году рождения",
        "4. Выход"
    };
    drawMenu("Опции сортировки", sortOptions, 4);
    cout << "Выбор: ";
    int choice = getValidNumericValue(cin, 1, 4);

    if (choice == 1) {
        Person::setSearchMode(NAME);
        cout << "Сортировка по имени..." << endl;
    } else if (choice == 2) {
        Person::setSearchMode(BIRTHDAY);
        cout << "Сортировка по дате рождения..." << endl;
    } else if (choice == 3) {
        Person::setSearchMode(BIRTH_YEAR);
        cout << "Сортровка по году..." << endl;
    } else {
        cout << "Выход." << endl;
        return;
    }

    deque.sort();
    Person::setSearchMode(FULL_MATCH);

    cout << "Сортировка прошла успешно." << endl;
    printDeque<T>(deque);
}

template <typename T>
void clearDeque(PersonDeque& deque) {
    for (PersonIterator it = deque.begin(); it != deque.end(); ++it) {
        delete *it;
    }
    deque.clear();
    cout << "Дек очищен." << endl;
}

template <typename T>
void saveDequeToFile(PersonDeque& deque, const string& typeName) {
    if (deque.isEmpty()) {
        cout << "Дек пуст. Сохранять нечего." << endl;
        return;
    }

    const string fileOptions[3] = {
        "1. Текстовый файл",
        "2. Бинарный файл",
        "3. Назад"
    };
    drawMenu("Запись в файл", fileOptions, 3);
    cout << "Выбор: ";
    int fileChoice = getValidNumericValue(cin, 1, 3);

    if (fileChoice == 3) {
        return;
    }

    filesystem::create_directories("output");
    cout << "Введите имя файла (без расширения): ";
    string userFilename = safeGetline(cin, false);
    string filename = "output/" + userFilename + (fileChoice == 1 ? ".txt" : ".bin");

    try {
        if (fileChoice == 1) {
            TextFile<T> file(filename);
            file.clearFileTxt();

            for (PersonIterator it = deque.begin(); it != deque.end(); ++it) {
                Person* person = *it;
                if (auto object = dynamic_cast<T*>(person)) {
                    file.saveRecordTxt(*object);
                }
            }
        } else {
            BinaryFile<T> file(filename);
            file.clearFileBin();

            for (PersonIterator it = deque.begin(); it != deque.end(); ++it) {
                Person* person = *it;
                if (auto object = dynamic_cast<T*>(person)) {
                    file.saveRecordBin(*object);
                }
            }
        }

        cout << "Данные сохранены в " << filename << endl;
    } catch (const exception& e) {
        cout << "Ошибка при сохранении: " << e.what() << endl;
    }
}

template <typename T>
void loadDequeFromFile(PersonDeque& deque, const string& typeName) {
    const string fileOptions[3] = {
        "1. Текстовый файл",
        "2. Бинарный файл",
        "3. Назад"
    };
    drawMenu("Чтение из файла", fileOptions, 3);
    cout << "Выбор: ";
    int fileChoice = getValidNumericValue(cin, 1, 3);

    if (fileChoice == 3) {
        return;
    }

    filesystem::create_directories("output");
    cout << "Введите имя файла (без расширения): ";
    string userFilename = safeGetline(cin, false);
    string filename = "output/" + userFilename + (fileChoice == 1 ? ".txt" : ".bin");

    try {
        Deque<T*> records;

        if (fileChoice == 1) {
            TextFile<T> file(filename);
            if (!file.hasRecordsTxt()) {
                cout << "Файл пуст или не найден." << endl;
                return;
            }
            records = file.readAllRecordsTxt();
        } else {
            BinaryFile<T> file(filename);
            records = file.readAllRecordsBin();
            if (records.isEmpty()) {
                cout << "Файл пуст или не найден." << endl;
                return;
            }
        }

        clearDeque<T>(deque);
        std::deque<Person*> bufferQueue; //std::deque
        for (auto it = records.begin(); it != records.end(); ++it) {
            bufferQueue.push_back(*it);
        }
        for (Person* person : bufferQueue) {
            if (person != nullptr) {
                deque.pushBack(person);
            }
        }

        cout << "Данные загружены из " << filename << endl;
        printDeque<T>(deque);
    } catch (const exception& e) {
        cout << "Ошибка при чтении: " << e.what() << endl;
    }
}

template <typename T>
void runForType(const string& typeName) {
    PersonDeque myDeque;
    int choice;
    const string mainMenuOptions[11] = {
        "1. Добавить объект",
        "2. Удалить объект",
        "3. Изменить объект",
        "4. Показать объект",
        "5. Вывести дек",
        "6. Поиск",
        "7. Сортировка",
        "8. Записать в файл",
        "9. Прочитать из файла",
        "10. Очистить дек",
        "11. Выход"
    };

    do {
        drawMenu("Главное Меню - " + typeName, mainMenuOptions, 11);
        cout << "Выбор: ";
        choice = getValidNumericValue(cin, 1, 11);

        switch (choice) {
            case 1: addObject<T>(myDeque); break;
            case 2: removeObject<T>(myDeque); break;
            case 3: modifyObject(myDeque); break;
            case 4: peekObject<T>(myDeque); break;
            case 5: printDeque<T>(myDeque); break;
            case 6: searchInDeque<T>(myDeque); break;
            case 7: sortDequeByField<T>(myDeque); break;
            case 8: saveDequeToFile<T>(myDeque, typeName); break;
            case 9: loadDequeFromFile<T>(myDeque, typeName); break;
            case 10: clearDeque<T>(myDeque); break;
            case 11: break;
        }
    } while (choice != 11);

    clearDeque<T>(myDeque);
}

void run();
