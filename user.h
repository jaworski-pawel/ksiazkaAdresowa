#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string login;
    string password;

public:
    User(int id, string login, string password);
    int getId();
    void setId(int id);
    string getLogin();
    void setLogin(string login);
    string getPassword();
    void setPassword(string password);
};

#endif
