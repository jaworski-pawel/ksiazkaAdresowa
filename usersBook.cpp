#include <iostream>
#include <windows.h>
#include <fstream>
#include "usersBook.h"

using namespace std;

UsersBook::UsersBook()
{
    numberOfUsers = 0;
}

int UsersBook::getNumberOfUsers()
{
    return numberOfUsers;
}

int UsersBook::signIn(vector<User> &users)
{
    string login, password;
    loadUsersFromFile(users);

    cout << "Enter the login: ";
    cin >> login;
    int i = 0;
    while (i < numberOfUsers)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempt = 0; attempt < 3; attempt++)
            {
                cout << "Enter the password: ";
                cin >> password;
                if (users[i].getPassword() == password)
                {
                    cout << "You signed in." << endl;
                    Sleep(1000);
                    return users[i].getId();
                }
            }
            cout << "You entered the wrong password 3 times. Wait 5 seconds..." << endl;
            Sleep(5000);
            return 0;
        }
        i++;
    }
    cout << "There is no such user." << endl;
    Sleep(3000);
    return 0;
}

void UsersBook::signUp(vector<User> &users)
{
    string login, password;
    loadUsersFromFile(users);

    cout << "Enter the login: ";
    cin >> login;
    int i = 0;

    while (i < numberOfUsers)
    {
        if (users[i].getLogin() == login)
        {
            cout << "Such a user exists. Enter another login: ";
            cin >> login;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << "Enter the password: ";
    cin >> password;
    numberOfUsers++;
    User temporaryUser(numberOfUsers, login, password);
    users.push_back(temporaryUser);
    cout << "You signed up" << endl;
    Sleep(1000);
    saveUsersToFile(users);
}

void UsersBook::changePassword(vector<User> &users, int idOfTheLoggedUser)
{
    string password;
    cout << "Enter a new password: ";
    cin >> password;
    for (int i = 0; i < numberOfUsers; i++)
    {
        if (users[i].getId() == idOfTheLoggedUser)
        {
            users[i].setPassword(password);
            cout << "Password changed." << endl;
            Sleep(1000);
        }
    }
    saveUsersToFile(users);
}

void UsersBook::loadUsersFromFile(vector<User> &users)
{
    string loadedLine;
    numberOfUsers = 0;

    users.erase(users.begin(), users.end());

    fstream file;
    file.open("Users.txt", ios::in);
    if(file.good())
    {
        while (getline(file, loadedLine))
        {
            int lenghtOfTheLoadedLine = loadedLine.size();
            int numberOfAttribute = 0;
            vector<string> attributeOfUser(3);

            for (int loadedChar = 0; loadedChar < lenghtOfTheLoadedLine; loadedChar++)
            {
                if (loadedLine[loadedChar] != 124)
                {
                    attributeOfUser[numberOfAttribute] +=loadedLine[loadedChar];
                }
                else
                {
                    numberOfAttribute++;
                }
            }
            User temporaryUser(convertStringToInt(attributeOfUser[0]), attributeOfUser[1], attributeOfUser[2]);
            users.push_back(temporaryUser);
            attributeOfUser.erase(attributeOfUser.begin(), attributeOfUser.end());

            numberOfUsers++;
        }
        file.close();
    }
    else
    {
        cout << "The file can not be opened." << endl;

    }
}

int UsersBook::convertStringToInt(string number)
{
    int integerNumber = atoi(number.c_str());
    return integerNumber;
}

void UsersBook::setNumberOfUsers(int numberOfUsers)
{
    this -> numberOfUsers = numberOfUsers;
}

void UsersBook::saveUsersToFile(vector<User> &users)
{
    fstream file;
    file.open("Users.txt", ios::out);
    if (file.good())
    {
        file << users[0].getId() << "|" << users[0].getLogin() << "|" << users[0].getPassword() << endl;
        file.close();
    }
    else
    {
        cout << "The file can not be opened." << endl;
    }

    for (int i = 1; i < numberOfUsers; i++)
    {
        fstream file;
        file.open("Users.txt", ios::out | ios::app);
        if (file.good())
        {
            file << users[i].getId() << "|" << users[i].getLogin() << "|" << users[i].getPassword() << endl;
            file.close();
        }
        else
        {
            cout << "The file can not be opened." << endl;
        }
    }
}
