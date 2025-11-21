#include "Person.h"
#include "Deque.hpp"
#include "Dealer.h"
#include <string.h>

Deque<Person*> myDeque;

void drawMenu(const string& title, const string options[], int numOptions) {
    int max_len = title.length();
    for (int i = 0; i < numOptions; i++) {
        if (options[i].length() > max_len) max_len = options[i].length();
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

void menu()
{
    cout << "--------- MENU --------" << endl;
    cout << "| 1. Add person       |" << endl;
    cout << "| 2. Show persons     |" << endl;
    cout << "| 3. Edit person      |" << endl;
    cout << "| 4. Delete person    |" << endl;
    cout << "| 5. Search person    |" << endl;
    cout << "| 6. Sort persons     |" << endl;
    cout << "| 7. Exit             |" << endl;
    cout << "-----------------------" << endl;
}

void addDeque(Person* person)
{
    cout << "--------- MENU ---------" << endl;
    cout << "| 1. Add to Front      |" << endl;
    cout << "| 2. Add to Back       |" << endl;
    cout << "| 3. Exit              |" << endl;
    cout << "------------------------" << endl;
    cout << "Choice: ";
    char add;
    cin >> add;

    if(add == '1')
    {
        myDeque.pushFront(person);
    } else if(add == '2')
    {
        myDeque.pushBack(person);
    } else 
    {
        return;
    }
}

void showDeque()
{
    cout << "--------- MENU ---------" << endl;
    cout << "| 1. Show Front        |" << endl;
    cout << "| 2. Show Back         |" << endl;
    cout << "| 3. Exit              |" << endl;
    cout << "------------------------" << endl;
    cout << "Choice: ";
    char show;
    cin >> show;

    if(myDeque.isEmpty())
    {
        cout << "Deque is empty!" << endl;
        return;
    } else 
    {
        (myDeque.peekFirst())->printHeader();
        Deque<Person*> tmpDeque = myDeque;
        if(show == '1')
        {
            while(!tmpDeque.isEmpty())
            {
                Person* p = tmpDeque.popFront();
                if(p != nullptr)
                {
                    p->printTable();
                }
            }
        } else if(show == '2')
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

void modifyObject()
{
    if(myDeque.isEmpty())
    {
        cout << "Deque is empty." << endl;
        return;
    } else 
    {
        cout << "------- Select Object to Modify -------" << endl;
        cout << "| 1. Modify First                    |" << endl;
        cout << "| 2. Modify Last                     |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Choice: ";
        char sideChoice;
        cin >> sideChoice;
        
        Person* person;
        if(sideChoice == '1')
        {
            person = myDeque.peekFirst();
        } else
        {
            person = myDeque.peekLast();
        } 
        
        if(person == nullptr)
        {
            cout << "Error: Person is null!" << endl;
            return;
        } else
        {
            Dealer* dealer = dynamic_cast<Dealer*>(person);
            Employer* employer = dynamic_cast<Employer*>(person);
            Tourist* tourist = dynamic_cast<Tourist*>(person);
            
            cout << "------- Modify Options -------" << endl;
            cout << "| 1. Change All Data         |" << endl;
            cout << "| 2. Change Specific Field   |" << endl;
            cout << "------------------------------" << endl;
            cout << "Choice: ";
            char modifyChoice;
            cin >> modifyChoice;
            
            if(modifyChoice == '1')
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
                    string fieldOption[5] = {"1. Name", "2. Birthday", "3. Licence", "4. Tax Time", "5. Tax Sum"};
                    drawMenu("Select Field", fieldOption, 5);
                    cout << "Choice: ";
                    cin >> fieldChoice;
                } else if(tourist != nullptr)
                {
                    string fieldOption[5] = {"1. Name", "2. Birthday", "3. Passport", "4. Country Time", "5. Countru Name"};
                    drawMenu("Select Field", fieldOption, 5);
                    cout << "Choice: ";
                    cin >> fieldChoice;
                }else if(dealer != nullptr)
                {
                    string fieldOption[9] = {"1. Name", "2. Birthday", "3. Licence", "4. Tax Time", "5. Tax Sum", "6. Passport", "7. Country Time", "8. Countru Name", "9. Adress"};
                    drawMenu("Select Field", fieldOption, 9);
                    cout << "Choice: ";
                    cin >> fieldChoice;
                }
                person->updateFields(fieldChoice);
            }
        }
    }
}

void deleteDeque()
{
    cout << "--------- MENU ---------" << endl;
    cout << "| 1. Delete Front      |" << endl;
    cout << "| 2. Delete Back       |" << endl;
    cout << "| 3. Exit              |" << endl;
    cout << "------------------------" << endl;
    cout << "Choice: ";
    char del;
    cin >> del;

    if(del == '1')
    {
        Person* person = myDeque.popFront();
        delete person;
    } else if(del == '2')
    {
        Person* person = myDeque.popBack();
        delete person;
    } else 
    {
        return;
    }
}

char choosePerson()
{
    cout << "------- Choose person -------" << endl;
    cout << "| 1. Employer               |" << endl;
    cout << "| 2. Tourist                |" << endl;
    cout << "| 3. Dealer                 |" << endl;
    cout << "| 4. Exit                   |" << endl;
    cout << "-----------------------------" << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;

    return choice;
}

void addPerson(char choice)
{
    Person* person = nullptr;
    if(choice == '1') 
    {
        Employer* newEmployer = new Employer();
        cin >> *newEmployer;
        // cout << "create Employer" << endl;
        person = newEmployer;

    } else if(choice == '2') 
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

void searchDeque()
{
    if(myDeque.isEmpty())
    {
        cout << "Deque is empty." << endl;
        return;
    }
    
    string fieldOption[5] = {"1. Search by Name", "2. Search by Birthday", "3. Search by Birth Year", "4. Search by Full Match", "5. Exit"};
    drawMenu("Choose search mode", fieldOption, 5);
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice < '1' || choice > '4')
    {
        return;
    } else
    {
        Person* searchPerson = new Employer();
        
        if(choice == '1')
        {
            cout << "Enter name to search: ";
            char name[30];
            cin >> name;
            searchPerson->setName(name);
            Person::setSearchMode(NAME);
        }
        else if(choice == '2')
        {
            cout << "Enter birthday(DD MM YYYY): ";
            Data bd;
            cin >> bd.day >> bd.month >> bd.year;
            searchPerson->setBirthday(bd);
            Person::setSearchMode(BIRTHDAY);
        }
        else if(choice == '3')
        {
            cout << "Enter birth year to search: ";
            Data bd;
            bd.day = 0;
            bd.month = 0;
            cin >> bd.year;
            searchPerson->setBirthday(bd);
            Person::setSearchMode(BIRTH_YEAR);
        }
        else
        {
            cout << "Enter criteria for Full Match:" << endl;
            cout << "Enter name: ";
            char name[30];
            cin >> name;
            searchPerson->setName(name);
            cout << "Enter birthday(DD MM YYYY): ";
            Data bd;
            cin >> bd.day >> bd.month >> bd.year;
            searchPerson->setBirthday(bd);
            Person::setSearchMode(FULL_MATCH);
        }
        
        Deque<Person*> results = myDeque.search(searchPerson);
        delete searchPerson;
        
        if(results.isEmpty())
        {
            cout << "No matches found." << endl;
        }
        else
        {
            cout << "Search results (" << results.size() << " found):" << endl;
            results.peekFirst()->printHeader();
            Deque<Person*> tmpResults = results;
            while(!tmpResults.isEmpty())
            {
                (*tmpResults.popFront()).printTable();
            }
        }
    }
}

void sortDeque()
{
    if(myDeque.isEmpty())
    {
        cout << "Deque is empty. Nothing to sort." << endl;
        return;
    }
    
    string fieldOption[4] = {"1. Sort by Name", "2. Sort by Birthday", "3. Sort by Birth Year", "4. Exit"};
    drawMenu("Choose sort mode", fieldOption, 4);
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice == '1')
    {
        Person::setSearchMode(NAME);
        cout << "Sorting by Name..." << endl;
    }
    else if(choice == '2')
    {
        Person::setSearchMode(BIRTHDAY);
        cout << "Sorting by Birthday..." << endl;
    }
    else if(choice == '3')
    {
        Person::setSearchMode(BIRTH_YEAR);
        cout << "Sorting by Birth Year..." << endl;
    }
    else
    {
        cout << "Invalid choice. Aborting sort." << endl;
        return;
    }
    
    myDeque.sort();
    cout << "Deque sorted successfully." << endl;
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

void actionPerson(char action)
{
    if(action == '1')
    {
        addPerson(choosePerson());
    } else if(action == '2')
    {
        showDeque();
    } else if(action == '3')
    {
        modifyObject();
    } else if(action == '4')
    {
        deleteDeque();
    } else if(action == '5')
    {
        searchDeque();
    } else if(action == '6')
    {
        sortDeque();
    }
}

int main()
{
    do
    {
        char action;
        menu();
        cout << "Choice: ";
        cin >> action;
        if(action == '7')
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
    
    cout << "Goodbuy!";
    return 0;
}