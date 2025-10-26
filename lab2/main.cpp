#include "../include/Dealer.h"
#define MAX_PERSONS 10

Dealer persons[MAX_PERSONS];
int i = 0;


void menu()
{
    cout << "-------- MENU --------" << endl;
    cout << "| 1. Add person      |" << endl;
    cout << "| 2. Show persons    |" << endl;
    cout << "| 3. Edit person     |" << endl;
    cout << "| 4. Delete person   |" << endl;
    cout << "| 5. Exit            |" << endl;
    cout << "----------------------" << endl;
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

void showPersonsInTable()
{
    persons[0].printHeader();
    
    for(int j = 0; j < i; ++j)
    {
        persons[j].printTable();
    }

}

void showPersons()
{
    for(int j = 0; j < i; ++j)
    {
        cout << (j + 1) << '.' << persons[j].getName() << endl;
    }
}

void deletePerson() 
{
    showPersons();
    cout << "What person do you want to delete?\nChoice: ";
    int numberPerson;
    cin >> numberPerson;

    for(int j = numberPerson - 1; j < i - 1; ++j)
    {
        persons[j] = persons[j + 1];
    }  
    i--; 
}

void actionPerson(char action)
{
    if(action == '1' || action == '3')
    {
        char chooseP = choosePerson();
        if(action == '1')
        {
            if(i > MAX_PERSONS)
            {
                cout << "You can't add a new person" << endl;
                return;
            }
            if(chooseP == '1')
            {
                static_cast<Employer&>(persons[i]).addEmployer(i);
            } else if(chooseP == '2')
            {
                static_cast<Tourist&>(persons[i]).addTourist(i);
            } else
            {
                persons[i].addDealer(i);
            }
        } else
        {
            showPersons();
            cout << "What the person do you want to edit?\nChoice: ";
            int numberPerson;
            cin >> numberPerson;
            persons[numberPerson - 1].editPerson();
        }

    } else if(action == '2' || action == '4')
    {
       if(action == '2')
       {
            showPersonsInTable();
       } else
       {
            deletePerson();
       }
    } else
    {
        return;
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