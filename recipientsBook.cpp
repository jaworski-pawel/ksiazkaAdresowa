#include <iostream>
#include "recipientsBook.h"

RecipientsBook::RecipientsBook()
{
    idOfTheLoggedUser = 0;
    numberOfUsers = 0;
    numberOfRecipients = 0;
}

int RecipientsBook::getIdOfTheLoggedUser()
{
    return idOfTheLoggedUser;
}

void RecipientsBook::setIdOfTheLoggedUser(int idOfTheLoggedUser)
{
    this -> idOfTheLoggedUser = idOfTheLoggedUser;
}

int RecipientsBook::getNumberOfUsers()
{
    return numberOfUsers;
}

void RecipientsBook::setNumberOfUsers(int numberOfUsers)
{
    this -> numberOfUsers = numberOfUsers;
}

void RecipientsBook::addRecipient(vector<Recipient> &recipients)
{
    loadRecipientsOfTheUserFromFile(recipients, idOfTheLoggedUser, "Recipients.txt");
    int recipientId;
    string name, surname, telephone, email, address;

    system("cls");
    cout << "Adding a recipient" << endl;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the surname: ";
    cin >> surname;
    cout << "Enter the telephone: ";
    cin.sync();
    getline(cin, telephone);
    cout << "Enter e-mail: ";
    cin >> email;
    cout << "Enter address: ";
    cin.sync();
    getline(cin, address);

    recipientId = assignId();
    cout << "Assigned id " << recipientId << endl;

    Recipient temporaryRecipient(recipientId, idOfTheLoggedUser, name, surname, telephone, email, address);
    recipients.push_back(temporaryRecipient);


    fstream file;
    file.open("Recipients.txt", ios::out | ios::app);
    if (file.good())
    {
        file << recipientId << "|" << idOfTheLoggedUser << "|" << name << "|" << surname << "|" << telephone << "|" << email << "|" << address << endl;
        file.close();

        cout << "Recipient added.";
        Sleep(1000);
    }
    else
    {
        cout << "The file can not be opened." << endl;
    }
    numberOfRecipients++;
    recipients.erase(recipients.begin(), recipients.end());
}

void RecipientsBook::editTheRecipient(vector<Recipient> &recipients)
{
    int searchedId;
    int recipientIterator;
    string temporaryName;
    string temporarySurname;
    string temporaryTelephone;
    string temporaryEmail;
    string temporaryAddress;

    numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, idOfTheLoggedUser, "Recipients.txt");

    system("cls");
    cout << "Editing the recipient" << endl;
    cout << "Enter ID: ";
    cin >> searchedId;
    recipientIterator = findIteratorOfRecipient(recipients, searchedId);

    if (recipientIterator == -1)
    {
        cout << "Incorrect ID" << endl;
        editTheRecipient(recipients);
    }
    else
    {
        system("cls");
        cout << "Edit data"<< endl;
        cout << "ID: " << recipients[recipientIterator].getRecipientId() << endl;
        cout << "Name: " << recipients[recipientIterator].getName() << endl;
        cout << "Surname: " << recipients[recipientIterator].getSurname() << endl;
        cout << "Telephone: " << recipients[recipientIterator].getTelephone() << endl;
        cout << "E-mail: " << recipients[recipientIterator].getEmail() << endl;
        cout << "Address: " << recipients[recipientIterator].getAddress() << endl;
        cout << endl;

        cout << "Enter the name: ";
        cin >> temporaryName;
        cout << "Enter the surname: ";
        cin >> temporarySurname;
        cout << "Enter the telephone: ";
        cin.sync();
        getline(cin, temporaryTelephone);
        cout << "Enter e-mail: ";
        cin >> temporaryEmail;
        cout << "Enter address: ";
        cin.sync();
        getline(cin, temporaryAddress);

        createACopyOfTheRecipients(recipients);

        fstream file;
        file.open("Recipients.txt", ios::out);
        if (file.good())
        {
            file << "";
            file.close();
        }
        else
        {
            cout << "The file can not be opened." << endl;
        }

        for (int i = 1; i <= numberOfUsers; i++)
        {
            int numberOfRecipients;
            numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, i, "temporaryRecipients.txt");

            for (int j = 0; j < numberOfRecipients; j++)
            {
                if (recipients[j].getRecipientId() == searchedId)
                {
                    fstream file;
                    file.open("Recipients.txt", ios::out | ios::app);
                    if (file.good())
                    {
                        file << recipients[j].getRecipientId() << "|" << recipients[j].getUserId() << "|" << temporaryName << "|" << temporarySurname << "|" << temporaryTelephone << "|" << temporaryEmail << "|" << temporaryAddress << endl;
                        file.close();
                    }
                    else
                    {
                        cout << "The file can not be opened." << endl;
                    }
                }
                else
                {
                    fstream file;
                    file.open("Recipients.txt", ios::out | ios::app);
                    if (file.good())
                    {
                        file << recipients[j].getRecipientId() << "|" << recipients[j].getUserId() << "|" << recipients[j].getName() << "|" << recipients[j].getSurname() << "|" << recipients[j].getTelephone() << "|" << recipients[j].getEmail() << "|" << recipients[j].getAddress() << endl;
                        file.close();
                    }
                    else
                    {
                        cout << "The file can not be opened." << endl;
                    }

                }
            }
        }

        fstream fileTemp;
        fileTemp.open("tempRecipients.txt", ios::out);
        if (fileTemp.good())
        {
            fileTemp << "";
            fileTemp.close();
        }
        else
        {
            cout << "The file can not be opened." << endl;
        }
    }
}

void RecipientsBook::deleteTheRecipient(vector<Recipient> &recipients)
{
    int searchedId;
    int recipientIterator;
    char answer;

    numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, idOfTheLoggedUser, "Recipients.txt");

    system("cls");
    cout << "Deleting the recipient" << endl;
    cout << "Enter ID: ";
    cin >> searchedId;
    recipientIterator = findIteratorOfRecipient(recipients, searchedId);

    if (recipientIterator == -1)
    {
        cout << "Incorrect ID" << endl;
        deleteTheRecipient(recipients);
    }
    else
    {
        system("cls");
        cout << "Delete the recipient"<< endl;
        cout << "ID: " << recipients[recipientIterator].getRecipientId() << endl;
        cout << "Name: " << recipients[recipientIterator].getName() << endl;
        cout << "Surname: " << recipients[recipientIterator].getSurname() << endl;
        cout << "Telephone: " << recipients[recipientIterator].getTelephone() << endl;
        cout << "E-mail: " << recipients[recipientIterator].getEmail() << endl;
        cout << "Address: " << recipients[recipientIterator].getAddress() << endl;
        cout << endl;

        cout << "Are you sure? (Y/N)";
        cin >> answer;
        if (answer == 'Y' || answer =='y')
        {
            createACopyOfTheRecipients(recipients);

            fstream file;
            file.open("Recipients.txt", ios::out);
            if (file.good())
            {
                file << "";
                file.close();
            }
            else
            {
                cout << "The file can not be opened." << endl;
            }

            for (int i = 1; i <= numberOfUsers; i++)
            {
                numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, i, "temporaryRecipients.txt");

                for (int j = 0; j < numberOfRecipients; j++)
                {
                    if (recipients[j].getRecipientId() != searchedId)
                    {
                        fstream file;
                        file.open("Recipients.txt", ios::out | ios::app);
                        if (file.good())
                        {
                            file << recipients[j].getRecipientId() << "|" << recipients[j].getUserId() << "|" << recipients[j].getName() << "|" << recipients[j].getSurname() << "|" << recipients[j].getTelephone() << "|" << recipients[j].getEmail() << "|" << recipients[j].getAddress() << endl;
                            file.close();
                        }
                        else
                        {
                            cout << "The file can not be opened." << endl;
                        }

                    }
                }
            }

            fstream fileTemp;
            fileTemp.open("tempRecipients.txt", ios::out);
            if (fileTemp.good())
            {
                fileTemp << "";
                fileTemp.close();
            }
            else
            {
                cout << "The file can not be opened." << endl;
            }
        }
        numberOfRecipients--;
    }
}

void RecipientsBook::searchByName(vector<Recipient> &recipients, string searchedWord)
{
    int foundedRecipients = 0;

    numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, idOfTheLoggedUser, "Recipients.txt");

    cout << "Addressees who have a surname " << searchedWord << ": " << endl;

    for (int i = 0; i < numberOfRecipients; i++)
    {
        if (recipients[i].getName() == searchedWord)
        {
            cout << "ID: " << recipients[i].getRecipientId() << endl;
            cout << "Name: " << recipients[i].getName() << endl;
            cout << "Surname: " << recipients[i].getSurname() << endl;
            cout << "Telephone: " << recipients[i].getTelephone() << endl;
            cout << "E-mail: " << recipients[i].getEmail() << endl;
            cout << "Address: " << recipients[i].getAddress() << endl;
            cout << endl;
            foundedRecipients++;
        }
    }
    if (foundedRecipients == 0)
    {
        cout << "No recipients found." << endl;
    }
    else
    {
        cout << foundedRecipients << " recipients found." << endl;
    }
    system("pause");
}

void RecipientsBook::searchBySurname(vector<Recipient> &recipients, string searchedWord)
{
    int foundedRecipients = 0;

    numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, idOfTheLoggedUser, "Recipients.txt");
    cout << "Addressees who have a surname " << searchedWord << ": " << endl;

    for (int i = 0; i < numberOfRecipients; i++)
    {
        if (recipients[i].getSurname() == searchedWord)
        {
            cout << "ID: " << recipients[i].getRecipientId() << endl;
            cout << "Name: " << recipients[i].getName() << endl;
            cout << "Surname: " << recipients[i].getSurname() << endl;
            cout << "Telephone: " << recipients[i].getTelephone() << endl;
            cout << "E-mail: " << recipients[i].getEmail() << endl;
            cout << "Address: " << recipients[i].getAddress() << endl;
            cout << endl;
            foundedRecipients++;
        }
    }
    if (foundedRecipients == 0)
    {
        cout << "No recipients found." << endl;
    }
    else
    {
        cout << foundedRecipients << " recipients found." << endl;
    }
    system("pause");
}

void RecipientsBook::showAllRecipients(vector<Recipient> &recipients)
{
    int foundedRecipients = 0;

    numberOfRecipients = loadRecipientsOfTheUserFromFile(recipients, idOfTheLoggedUser, "Recipients.txt");
    cout << "All recipients: " << endl;

    for (int i = 0; i < numberOfRecipients; i++)
    {
        cout << "ID: " << recipients[i].getRecipientId() << endl;
        cout << "Name: " << recipients[i].getName() << endl;
        cout << "Surname: " << recipients[i].getSurname() << endl;
        cout << "Telephone: " << recipients[i].getTelephone() << endl;
        cout << "E-mail: " << recipients[i].getEmail() << endl;
        cout << "Address: " << recipients[i].getAddress() << endl;
        cout << endl;
        foundedRecipients++;
    }

    if (foundedRecipients == 0)
    {
        cout << "No recipients found." << endl;
    }
    else
    {
        cout << foundedRecipients << " recipients found." << endl;
    }
    system("pause");
}

int RecipientsBook::assignId()
{
    int freeId = 1;
    string loadedLine;
    string loadedId;

    fstream file;
    file.open("Recipients.txt", ios::in);
    if(file.good())
    {
        while (getline(file, loadedLine))
        {
            int lengthOfLoadedLine = loadedLine.size();

            for (int loadedChar = 0; loadedChar < lengthOfLoadedLine; loadedChar++)
            {
                if (loadedLine[loadedChar] != 124)
                {
                    loadedId += loadedLine[loadedChar];
                }
                else
                {
                    if (freeId <= convertStringToInt(loadedId))
                    {
                        freeId = convertStringToInt(loadedId) + 1;
                    }
                    loadedId = "";
                    break;
                }
            }
        }
        file.close();
    }
    else
    {
        cout << "The file can not be opened." << endl;
    }
    return freeId;
}

int RecipientsBook::loadRecipientsOfTheUserFromFile(vector<Recipient> &recipients, int userId, string fileName)
{
    string loadedLine;
    int numberOfRecipientsOfUser = 0;

    recipients.erase(recipients.begin(), recipients.end());

    fstream file;
    file.open(fileName.c_str(), ios::in);
    if(file.good())
    {
        while (getline(file, loadedLine))
        {
            int lengthOfLoadedLine = loadedLine.size();
            int numberOfAttribute = 0;
            vector<string> attributeOfRecipients(7);

            for (int loadedChar = 0; loadedChar < lengthOfLoadedLine; loadedChar++)
            {
                if (loadedLine[loadedChar] != 124)
                {
                    attributeOfRecipients[numberOfAttribute] +=loadedLine[loadedChar];
                }
                else
                {
                    numberOfAttribute++;
                }
            }

            if (convertStringToInt(attributeOfRecipients[1]) == userId)
            {
                Recipient temporaryRecipient(convertStringToInt(attributeOfRecipients[0]), convertStringToInt(attributeOfRecipients[1]), attributeOfRecipients[2], attributeOfRecipients[3], attributeOfRecipients[4], attributeOfRecipients[5], attributeOfRecipients[6]);
                recipients.push_back(temporaryRecipient);
                attributeOfRecipients.erase(attributeOfRecipients.begin(), attributeOfRecipients.end());

                numberOfRecipientsOfUser++;
            }
        }
        file.close();
    }
    else
    {
        cout << "The file can not be opened." << endl;

    }
    return numberOfRecipientsOfUser;
}

int RecipientsBook::findIteratorOfRecipient(vector<Recipient> &recipients, int searchedId)
{
    bool foundId = false;
    int foundRecipientIterator;

    for (int recipientIterator = 0; recipientIterator < numberOfRecipients; recipientIterator++)
    {
        if ((searchedId == recipients[recipientIterator].getRecipientId()) && (idOfTheLoggedUser == recipients[recipientIterator].getUserId()))
        {
            foundId = true;
            foundRecipientIterator = recipientIterator;
            break;
        }
        else
        {
            foundId = false;
        }
    }

    if (foundId)
    {
        return foundRecipientIterator;
    }
    else
    {
        return(-1);
    }
}

void RecipientsBook::createACopyOfTheRecipients(vector<Recipient> recipients)
{
    for (int i = 1; i <= numberOfUsers; i++)
    {
        int numberOfRecipientsOfUser;
        numberOfRecipientsOfUser = loadRecipientsOfTheUserFromFile(recipients, i, "Recipients.txt");

        for (int j = 0; j < numberOfRecipientsOfUser; j++)
        {
            fstream file;
            file.open("temporaryRecipients.txt", ios::out | ios::app);
            if (file.good())
            {
                file << recipients[j].getRecipientId() << "|" << recipients[j].getUserId() << "|" << recipients[j].getName() << "|" << recipients[j].getSurname() << "|" << recipients[j].getTelephone() << "|" << recipients[j].getEmail() << "|" << recipients[j].getAddress() << endl;
                file.close();
            }
            else
            {
                cout << "The file can not be opened." << endl;
            }
        }
    }
}

int RecipientsBook::convertStringToInt(string number)
{
    int integerNumber = atoi(number.c_str());
    return integerNumber;
}
