#include "Algorithm.h"

void drawMenu(const string& title, const string options[], int numOptions) {
    int maxLen = static_cast<int>(title.length());
    for (int i = 0; i < numOptions; i++) {
        if (static_cast<int>(options[i].length()) > maxLen) {
            maxLen = static_cast<int>(options[i].length());
        }
    }
    maxLen += 4;
    cout << "+" << string(maxLen, '-') << "+" << endl;
    cout << title << string(maxLen - static_cast<int>(title.length()) - 1, ' ') << endl;
    cout << "+" << string(maxLen, '-') << "+" << endl;
    for (int i = 0; i < numOptions; i++) {
        cout << options[i] << string(maxLen - static_cast<int>(options[i].length()) - 1, ' ')  << endl;
    }
    cout << "+" << string(maxLen, '-') << "+" << endl;
}

void modifyObject(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Дек пустой." << endl;
        return;
    }

    const string sideOptions[2] = {"1. Редактировать первый", "2. Редактироваь последний"};
    drawMenu("выберите поле", sideOptions, 2);
    cout << "Выбор: ";
    int sideChoice = getValidNumericValue(cin, 1, 2);

    Person* person = (sideChoice == 1) ? deque.peekFirst() : deque.peekLast();
    if (person == nullptr) {
        cout << "Пусто." << endl;
        return;
    }

    Dealer* dealer = dynamic_cast<Dealer*>(person);
    Employer* employer = dealer ? nullptr : dynamic_cast<Employer*>(person);
    Tourist* tourist = dealer ? nullptr : dynamic_cast<Tourist*>(person);

    int fieldChoice;
    if (dealer) {
        dealer->Dealer::fieldBy();
        cout << "Выбор: ";
        fieldChoice = getValidNumericValue(cin, 1, 5);
    } else if (employer) {
        employer->Employer::fieldBy();
        cout << "Выбор: ";
        fieldChoice = getValidNumericValue(cin, 1, 5);
    } else if (tourist) {
        tourist->Tourist::fieldBy();
        cout << "Выбор: ";
        fieldChoice = getValidNumericValue(cin, 1, 9);
    } else {
        cout << "неизвестный тип." << endl;
        return;
    }

    if (dealer) {
        Dealer copy = *dealer;
        copy.updateFields(fieldChoice);
        *dealer = copy;
    } else if (employer) {
        Employer copy = *employer;
        copy.updateFields(fieldChoice);
        *employer = copy;
    } else if (tourist) {
        Tourist copy = *tourist;
        copy.updateFields(fieldChoice);
        *tourist = copy;
    }

    cout << "Поля обноалены успешно." << endl;
}

void run() {
    int choice;
    do
    {
        const string typeOptions[3] = {
            "1. Employer",
            "2. Tourist",
            "3. Dealer"
        };
        drawMenu("Объект", typeOptions, 3);
        cout << "Выбор: ";
        int typeChoice = getValidNumericValue(cin, 1, 3);
    
        switch (typeChoice) {
            case 1: runForType<Employer>("Employer"); break;
            case 2: runForType<Tourist>("Tourist"); break;
            case 3: runForType<Dealer>("Dealer"); break;
        }

        cout << "Хотите повторить?(y - 1, n - 0)" << endl;
        cout << "Выбор: ";
        choice = getValidNumericValue(cin, 0, 1);

    } while(choice == 1);
}
