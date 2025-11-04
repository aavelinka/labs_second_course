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

    char show;
    cin >> show;

    if(show == '1')
    {
        while(!myDeque.isEmpty())
        {
            cout << *myDeque.peekFirst() << endl;
        }
    } else if(show == '2')
    {
        while(!myDeque.isEmpty())
        {
            cout << *myDeque.peekLast() << endl;
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

    char choice;
    cin >> choice;

    return choice;
}

// void menu()
// {
//     cout << setw(24) << setfill('-') << "" << setfill(' ') << endl;
//     cout << "|" << setw(10) << "" << "MENU" << setw(10) << "" << "|" << endl;
//     cout << setw(24) << setfill('-') << "" << setfill(' ') << endl;
//     cout << "| 1. Add dealer" << setw(8) << "" << "|" << endl;
//     cout << "| 2. Show dealer" << setw(7) << "" << "|" << endl;
//     cout << "| 3. Edit dealer" << setw(7) << "" << "|" << endl;
//     cout << "| 4. Delete dealer" << setw(5) << "" << "|" << endl;
//     cout << "| 5. Exit" << setw(13) << "" << "|" << endl;
//     cout << setw(24) << setfill('-') << "" << setfill(' ') << endl;
// }

// cout << setw(27) << setfill('-') << "" << setfill(' ') << endl;
// cout << "| 1. Edit name" << setw(11) << "" << "|" << endl;
// cout << "| 2. Edit birthday" << setw(7) << "" << "|" << endl;
// cout << "| 3. Edit license" << setw(8) << "" << "|" << endl;
// cout << "| 4. Edit taxe" << setw(11) << "" << "|" << endl;
// cout << "| 5. Edit passport" << setw(7) << "" << "|" << endl;
// cout << "| 6. Edit country" << setw(8) << "" << "|" << endl;
// cout << "| 7. Edit address" << setw(8) << "" << "|" << endl;
// cout << "| 8. Edit all" << setw(12) << "" << "|" << endl;
// cout << setw(27) << setfill('-') << "" << setfill(' ') << endl;

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
    if(choice == '1') {
        person = new Employer;
        cin >> *dynamic_cast<Employer*>(person);
    } else if(choice == '2') {
        person = new Tourist;
        cin >> *dynamic_cast<Tourist*>(person);
    } else {
        person = new Dealer;
        cin >> *dynamic_cast<Dealer*>(person);
    }

    char add = addDeque();
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