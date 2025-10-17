#include "../include/Dealer.h"
#define MAX_DEALERS 10

Dealer dealers[MAX_DEALERS];
int i = 0;


// char choosePerson()
// {
//     cout << "------- Choose person -------" << endl;
//     cout << "1. Employer" << endl;
//     cout << "2. Tourist" << endl;
//     cout << "3. Dealer" << endl;
//     cout << "4. Exit" << endl;

//     char choice;
//     cin >> choice;

//     return choice;
// }

void menu()
{
    cout << "-------- MENU --------" << endl;
    cout << "| 1. Add dealer      |" << endl;
    cout << "| 2. Show dealer     |" << endl;
    cout << "| 3. Edit dealer     |" << endl;
    cout << "| 4. Delete dealer   |" << endl;
    cout << "| 5. Exit            |" << endl;
    cout << "----------------------" << endl;
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

void addDealer()
{
    if(i > MAX_DEALERS)
    {
        cout << "You can't add a new dealer" << endl;
        return;
    }

    Dealer dealer;
    cout << (i + 1) << ". Add dealer: " << endl;
    cin >> dealer;
    dealers[i++] = dealer;
}

void showDealersInTable()
{
    if(i == 0)
    {
        cout << "No dealers" << endl;
        return;
    }
    
    if(i > 0) {
        dealers[0].printHeader();
    }
    
    for(int j = 0; j < i; ++j)
    {
        dealers[j].printTable();
    }
}

void showDealers()
{
    if(i == 0)
    {
        cout << "No dealers" << endl;
        return;
    }
    for(int j = 0; j < i; ++j)
    {
        cout << (j + 1) << '.' << dealers[j];
    }
}


char editPunkt()
{
    cout << "-------------------------" << endl;
    cout << "| 1. Edit name          |" << endl;
    cout << "| 2. Edit birthday      |" << endl;
    cout << "| 3. Edit license       |" << endl;
    cout << "| 4. Edit taxe          |" << endl;
    cout << "| 5. Edit passport      |" << endl;
    cout << "| 6. Edit country       |" << endl;
    cout << "| 7. Edit address       |" << endl;
    cout << "| 8. Edit all           |" << endl;
    cout << "-------------------------" << endl;


    char option;
    cin >> option;

    return option;
}

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

void editDealer()
{
    showDealers();
    cout << "What the dealer do you want to edit?\nChoice: ";
    int numberDealer;
    cin >> numberDealer;

    switch (editPunkt())
    {
    case '1':
    {
        char newName[30];
        cout << "Enter new name: ";
        cin >> newName;
        dealers[numberDealer - 1].setName(newName);
        break;
    }
    case '2':
    {
        Data newBirthday;
        cout << "Enter new birthday(XX.YY.ZZZZ): ";
        cin >> newBirthday.day >> newBirthday.month >> newBirthday.year;
        dealers[numberDealer - 1].setBirthday(newBirthday);
        break;
    }
    case '3':
    {
        char newLicense[30];
        cout << "Enter new license: ";
        cin >> newLicense;
        dealers[numberDealer - 1].setLicense(newLicense);
        break;
    }
    case '4':
    {
        Taxes newTaxe;
        cout << "Enter new taxe:\nSumm - ";
        cin >> newTaxe.sum;
        cout << "Time(XX.YY.ZZZZ) - ";
        cin >> newTaxe.time.day >> newTaxe.time.month >> newTaxe.time.year;
        dealers[numberDealer - 1].setTaxes(newTaxe);
        break;
    }
    case '5':
    {
        char newPassport[8];
        cout << "Enter new data to passport: ";
        cin >> newPassport;
        dealers[numberDealer - 1].setPassport(newPassport);
        break;
    }
    case '6':
    {
        Countries newCountry;
        cout << "Enter new country(name and time): " << endl;
        cout << "Name of country - ";
        cin >> newCountry.countryName;
        cout << "Time(XX.YY.ZZZZ) - ";
        cin >> newCountry.time.day >> newCountry.time.month >> newCountry.time.month;
        dealers[numberDealer - 1].setCountry(newCountry);
        break;
    }
    case '7':
    {
        char newAddress[30];
        cout << "Enter new address: ";
        cin >> newAddress;
        dealers[numberDealer - 1].setAddress(newAddress);
        break;
    }
    case '8':
    {
        Dealer newDealer;
        cin >> newDealer;
        dealers[numberDealer - 1] = newDealer;
        break;
    }
    }
}

void deleteDealer() //????????????????????
{
    showDealers();
    cout << "What dealer do you want to delete?\nChoice: ";
    int numberDealer;
    cin >> numberDealer;

    for(int j = numberDealer - 1; j < i - 1; ++j)
    {
        dealers[j] = dealers[j + 1];
    }  
    i--; 
}

void actionDealer(char choice)
{
    if(choice == '1')
    {
        addDealer();
    } else if(choice == '2')
    {
        showDealersInTable();
    } else if(choice == '3')
    {
        editDealer();
    } else if(choice == '4')
    {
        deleteDealer();
    }
}

int main()
{
    do
    {
        char choice;
        menu();
        cin >> choice;
        if(choice == '5')
        {
            break;
        } else 
        {
            actionDealer(choice);
        }

    } while(true);
    
    cout << "Goodbuy!";
    return 0;
}