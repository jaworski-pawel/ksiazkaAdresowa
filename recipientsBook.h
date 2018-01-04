#ifndef RECIPIENTSBOOK_H
#define RECIPIENTSBOOK_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include "recipient.h"

using namespace std;

class RecipientsBook
{
    int idOfTheLoggedUser;
    int numberOfUsers;
    int numberOfRecipients;

public:
    RecipientsBook();
    int getIdOfTheLoggedUser();
    void setIdOfTheLoggedUser(int idOfTheLoggedUser);
    int getNumberOfUsers();
    void setNumberOfUsers(int numberOfUsers);
    void addRecipient(vector<Recipient> &recipients);
    void editTheRecipient(vector<Recipient> &recipients);
    void deleteTheRecipient(vector<Recipient> &recipients);
    void searchByName(vector<Recipient> &recipients, string searchedWord);
    void searchBySurname(vector<Recipient> &recipients, string searchedWord);
    void showAllRecipients(vector<Recipient> &recipients);

private:
    int assignId();
    int loadRecipientsOfTheUserFromFile(vector<Recipient> &recipients, int userId, string fileName);
    int findIteratorOfRecipient(vector<Recipient> &recipients, int searchedId);
    void createACopyOfTheRecipients(vector<Recipient> recipients);
    int convertStringToInt(string number);
};

#endif
