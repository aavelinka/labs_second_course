#include "Person.h"
#include "Deque.hpp"
#include "Dealer.h"
#include <string.h>

Deque<Person*> myDeque;

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

void updatePersonFields(Person* person)
{
    char name[30];
    Data bd;
    
    cout << "------- Select Person Field -------" << endl;
    cout << "| 1. Name                         |" << endl;
    cout << "| 2. Birthday                     |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice == '1')
    {
        cout << "New name: ";
        cin >> name;
        person->setName(name);
    } else if(choice == '2')
    {
        cout << "New birthday(DD MM YYYY): ";
        cin >> bd.day >> bd.month >> bd.year;
        person->setBirthday(bd);
    }
}

void updateEmployerFields(Employer* employer)
{
    char license[30];
    Taxes tax;
    
    cout << "------- Select Employer Field ------" << endl;
    cout << "| 1. License                       |" << endl;
    cout << "| 2. Tax Sum                       |" << endl;
    cout << "| 3. Tax Date                      |" << endl;
    cout << "------------------------------------" << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice == '1')
    {
        cout << "New license: ";
        cin >> license;
        employer->setLicense(license);
    }
    else if(choice == '2')
    {
        cout << "New tax sum: ";
        cin >> tax.sum;
        tax.time = employer->getTaxes().time;
        employer->setTaxes(tax);
    }
    else if(choice == '3')
    {
        cout << "New tax date(DD MM YYYY): ";
        cin >> tax.time.day >> tax.time.month >> tax.time.year;
        tax.sum = employer->getTaxes().sum;
        employer->setTaxes(tax);
    }
}

void updateTouristFields(Tourist* tourist)
{
    char passport[8];
    Countries country;
    
    cout << "------- Select Tourist Field -------" << endl;
    cout << "| 1. Passport                     |" << endl;
    cout << "| 2. Country Name                 |" << endl;
    cout << "| 3. Visit Date                   |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice == '1')
    {
        cout << "New passport: ";
        cin >> passport;
        tourist->setPassport(passport);
    } else if(choice == '2')
    {
        cout << "New country name: ";
        cin >> country.countryName;
        country.time = tourist->getCountry().time;
        tourist->setCountry(country);
    } else if(choice == '3')
    {
        cout << "New visit date(DD MM YYYY): ";
        cin >> country.time.day >> country.time.month >> country.time.year;
        strcpy(country.countryName, tourist->getCountry().countryName);
        tourist->setCountry(country);
    }
}

void updateDealerFields(Dealer* dealer)
{
    char address[30];
    
    cout << "------- Select Dealer Field -------" << endl;
    cout << "| 1. Address                      |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice == '1')
    {
        cout << "New address: ";
        cin >> address;
        dealer->setAddress(address);
    }
}

void modifyObject()
{
    if(myDeque.isEmpty())
    {
        cout << "Deque is empty." << endl;
        return;
    }
    
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
            else
            {
                cin >> *person;
            }
            return;
        } else
        {
            int numFieldOptions = 1;
            cout << "------- Select Field Category -------" << endl;
            cout << "| 1. Person Fields                  |" << endl;
            
            if(employer != nullptr)
            {
                cout << "| " << (numFieldOptions + 1) << ". Employer Fields              |" << endl;
                numFieldOptions++;
            }

            if(tourist != nullptr)
            {
                cout << "| " << (numFieldOptions + 1) << ". Tourist Fields               |" << endl;
                numFieldOptions++;
            }

            if(dealer != nullptr)
            {
                cout << "| " << (numFieldOptions + 1) << ". Dealer Fields                |" << endl;
                numFieldOptions++;
            }
            cout << "--------------------------------------" << endl;
            cout << "Choice: ";
            int fieldChoice;
            cin >> fieldChoice;
            
            int currentOption = 1;
            
            if(fieldChoice == currentOption)
            {
                updatePersonFields(person);
                return;
            }
            currentOption++;
            
            if(employer != nullptr)
            {
                if(fieldChoice == currentOption)
                {
                    updateEmployerFields(employer);
                    return;
                }
                currentOption++;
            }
            
            if(tourist != nullptr)
            {
                if(fieldChoice == currentOption)
                {
                    updateTouristFields(tourist);
                    return;
                }
                currentOption++;
            }
            
            if(dealer != nullptr)
            {
                if(fieldChoice == currentOption)
                {
                    updateDealerFields(dealer);
                    return;
                }
            }
        }
    }
}

void editDeque()
{
    modifyObject();
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
    
    cout << "------- Choose search mode -------" << endl;
    cout << "| 1. Search by Name              |" << endl;
    cout << "| 2. Search by Birthday          |" << endl;
    cout << "| 3. Search by Birth Year        |" << endl;
    cout << "| 4. Search by Full Match        |" << endl;
    cout << "| 5. Exit                        |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    
    if(choice < '1' || choice > '4')
    {
        return;
    } else
    {
        Employer* searchKey = new Employer();
        SearchMode mode = FULL_MATCH;
        
        if(choice == '1')
        {
            cout << "Enter name to search: ";
            char name[30];
            cin >> name;
            searchKey->setName(name);
            Person::setSearchMode(NAME);
        }
        else if(choice == '2')
        {
            cout << "Enter birthday(DD MM YYYY): ";
            Data bd;
            cin >> bd.day >> bd.month >> bd.year;
            searchKey->setBirthday(bd);
            Person::setSearchMode(BIRTHDAY);
        }
        else if(choice == '3')
        {
            cout << "Enter birth year to search: ";
            Data bd;
            bd.day = 0;
            bd.month = 0;
            cin >> bd.year;
            searchKey->setBirthday(bd);
            Person::setSearchMode(BIRTH_YEAR);
        }
        else
        {
            cout << "Enter criteria for Full Match:" << endl;
            cout << "Enter name: ";
            char name[30];
            cin >> name;
            searchKey->setName(name);
            cout << "Enter birthday(DD MM YYYY): ";
            Data bd;
            cin >> bd.day >> bd.month >> bd.year;
            searchKey->setBirthday(bd);
            Person::setSearchMode(FULL_MATCH);
        }
        
        Person* searchPerson = searchKey;
        
        Deque<Person*> results = myDeque.search(searchPerson);
        Person::setSearchMode(FULL_MATCH);
        delete searchKey;
        
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
    
    cout << "------- Choose sort mode -------" << endl;
    cout << "| 1. Sort by Name              |" << endl;
    cout << "| 2. Sort by Birthday          |" << endl;
    cout << "| 3. Sort by Birth Year       |" << endl;
    cout << "| 4. Exit                     |" << endl;
    cout << "--------------------------------" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    
    if(choice == 1)
    {
        Person::setSearchMode(NAME);
        cout << "Sorting by Name..." << endl;
    }
    else if(choice == 2)
    {
        Person::setSearchMode(BIRTHDAY);
        cout << "Sorting by Birthday..." << endl;
    }
    else if(choice == 3)
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
    Person::setSearchMode(NAME);
    
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
        editDeque();
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