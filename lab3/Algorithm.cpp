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
    cout << "| " << title << string(maxLen - static_cast<int>(title.length()) - 1, ' ') << "|" << endl;
    cout << "+" << string(maxLen, '-') << "+" << endl;
    for (int i = 0; i < numOptions; i++) {
        cout << "| " << options[i] << string(maxLen - static_cast<int>(options[i].length()) - 1, ' ') << "|" << endl;
    }
    cout << "+" << string(maxLen, '-') << "+" << endl;
}

void modifyObject(Deque<Person*>& deque) {
    if (deque.isEmpty()) {
        cout << "Deque is empty." << endl;
        return;
    }

    const string sideOptions[2] = {"1. Modify First", "2. Modify Last"};
    drawMenu("Select Object to Modify", sideOptions, 2);
    cout << "Choice: ";
    int sideChoice;
    cin >> sideChoice;

    Person* person = (sideChoice == 1) ? deque.peekFirst() : deque.peekLast();
    if (person == nullptr) {
        cout << "Selected element is null." << endl;
        return;
    }

    Dealer* dealer = dynamic_cast<Dealer*>(person);
    Employer* employer = dealer ? nullptr : dynamic_cast<Employer*>(person);
    Tourist* tourist = dealer ? nullptr : dynamic_cast<Tourist*>(person);

    if (dealer) {
        dealer->Dealer::fieldBy();
    } else if (employer) {
        employer->Employer::fieldBy();
    } else if (tourist) {
        tourist->Tourist::fieldBy();
    } else {
        cout << "Unknown object type." << endl;
        return;
    }

    cout << "Choice: ";
    int fieldChoice;
    cin >> fieldChoice;

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

    cout << "Field updated successfully." << endl;
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
        drawMenu("Select type to work with", typeOptions, 3);
        cout << "Choice: ";
        int typeChoice;
        cin >> typeChoice;
    
        switch (typeChoice) {
            case 1: runForType<Employer>("Employer"); break;
            case 2: runForType<Tourist>("Tourist"); break;
            case 3: runForType<Dealer>("Dealer"); break;
            default: cout << "Invalid choice." << endl; break;
        }

        cout << "Do you want to repeate?(y - 1, n - 0)" << endl;
        cout << "Choice: ";
        cin >> choice;

    } while(choice == 1);
}
