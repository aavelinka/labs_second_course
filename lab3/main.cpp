#include "Dealer.h"
#include "Deque.h"

Deque<Person*> myDeque;

void menu()
{
    cout << "--------- MENU --------" << endl;
    cout << "| 1. Add person       |" << endl;
    cout << "| 2. Show persons     |" << endl;
    cout << "| 3. Edit person      |" << endl;
    cout << "| 4. Delete person    |" << endl;
    cout << "| 5. Exit             |" << endl;
    cout << "-----------------------" << endl;
}

char addDeque()
{
    cout << "--------- MENU ---------" << endl;
    cout << "| 1. Add to Front      |" << endl;
    cout << "| 2. Add to Back       |" << endl;
    cout << "| 3. Exit              |" << endl;
    cout << "------------------------" << endl;
    cout << "Choice: ";
    char add;
    cin >> add;

    return add;
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

    Deque<Person*> tmpDeque = myDeque;
    (myDeque.peekFirst())->printHeader();
    if(show == '1')
    {
        while(!tmpDeque.isEmpty())
        {
            (*tmpDeque.popFront()).printTable();
        }
    } else if(show == '2')
    {
        while(!tmpDeque.isEmpty())
        {
            (*tmpDeque.popBack()).printTable();
        }
    } else
    {
        return;
    }
}

void editDeque()
{
    cout << "--------- MENU ---------" << endl;
    cout << "| 1. Edit Front        |" << endl;
    cout << "| 2. Edit Back         |" << endl;
    cout << "| 3. Exit              |" << endl;
    cout << "------------------------" << endl;
    cout << "Choice: ";
    char edit;
    cin >> edit;

    if(edit == '1')
    {
        //Dealer person = myDeque.popFront();

    } else if(edit == '2')
    {
        //Dealer person = myDeque.popBack();

    } else 
    {
        return;
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

// void showPersonsInTable()
// {
//     persons[0].printHeader();
//     for(int j = 0; j < i; ++j)
//     {
//         persons[j].printTable();
//     }
// }

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
        person = newDealer;
    }

    char add = addDeque();
    if(add == '1')
    {
        myDeque.pushFront(person);
        // cout << "Как объект класса - " << *person << endl;
        // cout << "Как объект списка - " << *myDeque.popFront();
    } else if(add == '2')
    {
        myDeque.pushBack(person);
        // cout << "Как объект класса - " << *person << endl;
        // cout << "Как объект списка - " << *myDeque.popFront();
    } else 
    {
        return;
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
        if(action == '5')
        {
            break;
        } else 
        {
            actionPerson(action);
        }

    } while(true);
    
    cout << "Goodbuy!";
    return 0;
}