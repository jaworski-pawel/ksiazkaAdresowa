#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <iostream>

using namespace std;

class Recipient
{
    int recipientId;
    int userId;
    string name;
    string surname;
    string telephone;
    string email;
    string address;

public:
    Recipient(int recipientId, int userId, string name, string surname, string telephone, string email, string address);
    int getRecipientId();
    void setRecipientId(int recipientId);
    int getUserId();
    void setUserId(int userId);
    string getName();
    void setName(string name);
    string getSurname();
    void setSurname(string surname);
    string getTelephone();
    void setTelephone(string telephone);
    string getEmail();
    void setEmail(string email);
    string getAddress();
    void setAddress(string address);
};

#endif
