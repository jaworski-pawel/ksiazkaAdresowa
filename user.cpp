#include <iostream>
#include "user.h"

using namespace std;

User::User(int id, string login, string password)
{
    this -> id = id;
    this -> login = login;
    this -> password = password;
}

int User::getId()
{
    return id;
}

void User::setId(int id)
{
    this -> id = id;
}

string User::getLogin()
{
    return login;
}

void User::setLogin(string login)
{
    this -> login = login;
}

string User::getPassword()
{
    return password;
}

void User::setPassword(string password)
{
    this -> password = password;
}
