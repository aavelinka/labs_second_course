#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "exceptions/include/InputValidator.h"
#include "include/Dealer.h"
#include "include/Deque.tpp"

using namespace std;

void drawMenu(const string& title, const string options[], int numOptions);

template <typename T>
void addObject(Deque<Person*>& deque) {
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
void removeObject(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    const string options[2] = {"1. Удалить сначала", "2. Удалить сконца"};
    drawMenu("Удалить объект", options, 2);
    cout << "Выбор: ";
    int choice = getValidNumericValue(cin, 1, 2);

    Person* removed = nullptr;
    removed = (choice == 1) ? deque.popFront() : deque.popBack();

    delete removed;
}

void modifyObject(Deque<Person*>& deque);

template <typename T>
void peekObject(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    const string options[2] = {"1. Показать первый", "2. Показать последний"};
    drawMenu("Показать объект", options, 2);
    cout << "Выбор: ";
    int choice = getValidNumericValue(cin, 1, 2);

    Person* obj = nullptr;
    obj = (choice == 1) ? deque.peekFirst() : deque.peekLast();

    if (obj != nullptr) {
        obj->printHeader();
        obj->printTable();
    }
}

template <typename T>
void printDeque(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пуст." << endl;
        return;
    }

    Person* head = deque.peekFirst();
    if (head != nullptr) {
        head->printHeader();
    }

    Deque<Person*> copy = deque;
    while (!copy.isEmpty()) {
        Person* obj = copy.popFront();
        if (obj != nullptr) {
            obj->printTable();
        }
    }
}

template <typename T>
void searchInDeque(Deque<Person*>& deque) {
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
void sortDequeByField(Deque<Person*>& deque) {
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
void clearDeque(Deque<Person*>& deque) {
    while (!deque.isEmpty()) {
        delete deque.popFront();
    }
    cout << "Дек очищен." << endl;
}

template <typename T>
void runForType(const string& typeName) {
    Deque<Person*> myDeque;
    int choice;
    const string mainMenuOptions[9] = {
        "1. Добавить объект",
        "2. Удалить объект",
        "3. Изменить объект",
        "4. Показать объект",
        "5. Вывести дек",
        "6. Поиск",
        "7. Сортировка",
        "8. Очистить дек",
        "9. Выход"
    };

    do {
        drawMenu("Главное Меню - " + typeName, mainMenuOptions, 9);
        cout << "Выбор: ";
        choice = getValidNumericValue(cin, 1, 9);

        switch (choice) {
            case 1: addObject<T>(myDeque); break;
            case 2: removeObject<T>(myDeque); break;
            case 3: modifyObject(myDeque); break;
            case 4: peekObject<T>(myDeque); break;
            case 5: printDeque<T>(myDeque); break;
            case 6: searchInDeque<T>(myDeque); break;
            case 7: sortDequeByField<T>(myDeque); break;
            case 8: clearDeque<T>(myDeque); break;
            case 9: break;
        }
    } while (choice != 9);

    clearDeque<T>(myDeque);
}

void run();

