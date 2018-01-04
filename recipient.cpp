#include <iostream>
#include "recipient.h"

using namespace std;

Recipient::Recipient(int recipientId, int userId, string name, string surname, string telephone, string email, string address)
{
    this -> recipientId = recipientId;
    this -> userId = userId;
    this -> name = name;
    this -> surname = surname;
    this -> telephone = telephone;
    this -> email = email;
    this -> address = address;
}

int Recipient::getRecipientId()
{
    return recipientId;
}

void Recipient::setRecipientId(int recipientId)
{
    this -> recipientId = recipientId;
}

int Recipient::getUserId()
{
    return userId;
}

void Recipient::setUserId(int userId)
{
    this -> userId = userId;
}

string Recipient::getName()
{
    return name;
}

void Recipient::setName(string name)
{
    this -> name = name;
}

string Recipient::getSurname()
{
    return surname;
}

void Recipient::setSurname(string surname)
{
    this -> surname = surname;
}

string Recipient::getTelephone()
{
    return telephone;
}

void Recipient::setTelephone(string telephone)
{
    this -> telephone = telephone;
}

string Recipient::getEmail()
{
    return email;
}

void Recipient::setEmail(string email)
{
    this -> email = email;
}

string Recipient::getAddress()
{
    return address;
}

void Recipient::setAddress(string address)
{
    this -> address = address;
}
