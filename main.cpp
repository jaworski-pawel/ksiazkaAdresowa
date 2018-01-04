#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "user.h"
#include "recipient.h"
#include "usersBook.h"
#include "recipientsBook.h"

using namespace std;

int main()
{
    vector<User> users;
    vector<Recipient> recipients;
    UsersBook usersBook;
    RecipientsBook recipientsBook;
    char selection;

    while (true)
    {
        if (recipientsBook.getIdOfTheLoggedUser() == 0)
        {
            system("cls");
            cout << "Address book - main menu." << endl << endl;
            cout << "1. Sign up" << endl;
            cout << "2. Sign in" << endl;
            cout << "9. Exit" << endl << endl;
            cout << "Selection: ";
            cin >> selection;

            switch(selection)
            {
            case '1':
            {
                usersBook.signUp(users);
                break;
            }
            case '2':
            {
                recipientsBook.setIdOfTheLoggedUser(usersBook.signIn(users));
                break;
            }
            case '9':
            {
                exit(0);
                break;
            }
            }
        }
        else
        {
            recipientsBook.setNumberOfUsers(usersBook.getNumberOfUsers());
            system("cls");
            cout << "Address book - user menu." << endl << endl;
            cout << "1. Add recipient" << endl;
            cout << "2. Search by first name" << endl;
            cout << "3. Search by surname" << endl;
            cout << "4. Show all recipients" << endl;
            cout << "5. Delete the recipient" << endl;
            cout << "6. Edit the recipient" << endl;
            cout << "7. Change password" << endl;
            cout << "8. Sign out" << endl << endl;
            cin >> selection;

            switch(selection)
            {
            case '1':
            {
                recipientsBook.addRecipient(recipients);
                break;
            }
            case '2':
            {
                string searchedWord;
                cout << "Search by name." << endl;
                cout << "Enter the name: ";
                cin >> searchedWord;
                recipientsBook.searchByName(recipients, searchedWord);
                break;
            }
            case '3':
            {
                string searchedWord;
                cout << "Search by surname." << endl;
                cout << "Enter the surname: ";
                cin >> searchedWord;
                recipientsBook.searchBySurname(recipients, searchedWord);
                break;
            }
            case '4':
            {
                recipientsBook.showAllRecipients(recipients);
                break;
            }
            case '5':
            {
                recipientsBook.deleteTheRecipient(recipients);
                break;
            }
            case '6':
            {
                recipientsBook.editTheRecipient(recipients);
                break;
            }
            case '7':
            {
                usersBook.changePassword(users, recipientsBook.getIdOfTheLoggedUser());
                break;
            }
            case '8':
            {
                recipientsBook.setIdOfTheLoggedUser(0);
                break;
            }
            }
        }

    }
    return 0;
}
