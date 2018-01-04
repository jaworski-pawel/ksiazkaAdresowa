#ifndef USERSBOOK_H
#define USERSBOOK_H

#include <iostream>
#include <vector>
#include "user.h"

using namespace std;

class UsersBook
{
    int numberOfUsers;

public:
    UsersBook();
    int getNumberOfUsers();
    int signIn(vector<User> &users);
    void signUp(vector<User> &users);
    void changePassword(vector<User> &users, int idOfTheLoggedUser);

private:
    int convertStringToInt(string number);
    void setNumberOfUsers(int numberOfUsers);
    void loadUsersFromFile(vector<User> &users);
    void saveUsersToFile(vector<User> &users);
};

#endif
