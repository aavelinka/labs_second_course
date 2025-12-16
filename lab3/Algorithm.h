#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "include/Dealer.h"
#include "include/Deque.tpp"

using namespace std;

void drawMenu(const string& title, const string options[], int numOptions);

template <typename T>
void addObject(Deque<Person*>& deque) {
    const string sideOptions[2] = {"1. Add to Front", "2. Add to Back"};
    drawMenu("Select Side", sideOptions, 2);
    cout << "Choice: ";
    int sideChoice;
    cin >> sideChoice;

    if (sideChoice != 1 && sideChoice != 2) {
        cout << "Invalid choice." << endl;
        return;
    }

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
        cout << "Deque is empty." << endl;
        return;
    }

    const string options[2] = {"1. Remove from Front", "2. Remove from Back"};
    drawMenu("Remove Object", options, 2);
    cout << "Choice: ";
    int choice;
    cin >> choice;

    Person* removed = nullptr;
    removed = (choice == 1) ? deque.popFront() : deque.popBack();

    delete removed;
}

void modifyObject(Deque<Person*>& deque);

template <typename T>
void peekObject(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Deque is empty." << endl;
        return;
    }

    const string options[2] = {"1. Peek First", "2. Peek Last"};
    drawMenu("Peek Object", options, 2);
    cout << "Choice: ";
    int choice;
    cin >> choice;

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
        cout << "Deque is empty." << endl;
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
        cout << "Deque is empty." << endl;
        return;
    }

    const string searchOptions[5] = {
        "1. Search by Name",
        "2. Search by Birthday",
        "3. Search by Birth Year",
        "4. Search by Full Match",
        "5. Cancel"
    };
    drawMenu("Search Options", searchOptions, 5);
    cout << "Choice: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > 4) {
        return;
    }

    T* searchObj = new T();
    Data searchDate{};
    char searchName[30];

    switch (choice) {
        case 1:
            cout << "Enter name to search: ";
            cin >> searchName;
            searchObj->setName(searchName);
            Person::setSearchMode(NAME);
            break;
        case 2:
            cout << "Enter birthday(DD MM YYYY): ";
            cin >> searchDate.day >> searchDate.month >> searchDate.year;
            searchObj->setBirthday(searchDate);
            Person::setSearchMode(BIRTHDAY);
            break;
        case 3:
            cout << "Enter birth year: ";
            cin >> searchDate.year;
            searchDate.day = 0;
            searchDate.month = 0;
            searchObj->setBirthday(searchDate);
            Person::setSearchMode(BIRTH_YEAR);
            break;
        case 4:
            cout << "Enter name: ";
            cin >> searchName;
            searchObj->setName(searchName);
            cout << "Enter birthday(DD MM YYYY): ";
            cin >> searchDate.day >> searchDate.month >> searchDate.year;
            searchObj->setBirthday(searchDate);
            Person::setSearchMode(FULL_MATCH);
            break;
    }

    Deque<Person*> searchResults = deque.search(searchObj);
    delete searchObj;
    Person::setSearchMode(FULL_MATCH);

    if (searchResults.isEmpty()) {
        cout << "No matches found." << endl;
    } else {
        cout << "Search results (" << searchResults.size() << " found):" << endl;
        printDeque<T>(searchResults);
    }
}

template <typename T>
void sortDequeByField(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Deque is empty. Nothing to sort." << endl;
        return;
    }

    const string sortOptions[4] = {
        "1. Sort by Name",
        "2. Sort by Birthday",
        "3. Sort by Birth Year",
        "4. Cancel"
    };
    drawMenu("Sort Options", sortOptions, 4);
    cout << "Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Person::setSearchMode(NAME);
        cout << "Sorting by Name..." << endl;
    } else if (choice == 2) {
        Person::setSearchMode(BIRTHDAY);
        cout << "Sorting by Birthday..." << endl;
    } else if (choice == 3) {
        Person::setSearchMode(BIRTH_YEAR);
        cout << "Sorting by Birth Year..." << endl;
    } else {
        cout << "Invalid choice. Aborting sort." << endl;
        return;
    }

    deque.sort();
    Person::setSearchMode(FULL_MATCH);

    cout << "Deque sorted successfully." << endl;
    printDeque<T>(deque);
}

template <typename T>
void clearDeque(Deque<Person*>& deque) {
    while (!deque.isEmpty()) {
        delete deque.popFront();
    }
    cout << "Deque cleared." << endl;
}

template <typename T>
void runForType(const string& typeName) {
    Deque<Person*> myDeque;
    int choice;
    const string mainMenuOptions[9] = {
        "1. Add Object",
        "2. Remove Object",
        "3. Modify Object",
        "4. Peek Object",
        "5. Print Deque",
        "6. Search",
        "7. Sort",
        "8. Clear Deque",
        "9. Exit"
    };

    do {
        drawMenu("Main Menu - " + typeName, mainMenuOptions, 9);
        cout << "Choice: ";
        cin >> choice;

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
            default: cout << "Invalid choice." << endl; break;
        }
    } while (choice != 9);

    clearDeque<T>(myDeque);
}

void run();

