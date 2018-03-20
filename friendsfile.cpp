#include <iostream>
#include "FriendsFile.h"
#include <windows.h>
#include <cstdlib>
#include "Conversion.h"

using namespace std;


int FriendsFile::findNextFriendID ()
{
    string line;
    string word;
    int verticalLinesNumber = 0;
    int howManyCharactersExpose = 0;
    int beginning = 0 ;
    int largestID = 0;
    int currentID = 0;
    int nextID = 0;
    fstream file;

    file.open("AddressBook.txt",ios::in);
    if (file.good() == true)
    {
        while (getline(file,line))
        {
            howManyCharactersExpose = 0;
            beginning = 0;
            verticalLinesNumber = 0;

            for (int i = 0; i < line.size(); i++)
            {
                howManyCharactersExpose = i - beginning;
                if (line[i] == '|')
                {
                    verticalLinesNumber++;
                    word = line.substr (beginning, howManyCharactersExpose);
                    currentID = atoi(word.c_str());
                    if ( verticalLinesNumber == 1 )
                    {
                        if (currentID > largestID)
                        {
                            largestID = currentID;
                        }
                    }
                }
            }
        }
    }
    nextID = largestID + 1;
    return nextID;
}

void FriendsFile::addFriendToFile(Friend newFriend)
{
    string lineWithFriendData = "";
    file.open("AddressBook.txt", ios::out | ios::app);
    Conversion number;

    if (file.good() == true)
    {
        lineWithFriendData += number.conversionIntToString(newFriend.getFriendID()) + '|';
        lineWithFriendData += number.conversionIntToString(newFriend.getUserID()) + '|';
        lineWithFriendData += newFriend.getFriendName() + '|';
        lineWithFriendData += newFriend.getFriendSurname() + '|';
        lineWithFriendData += newFriend.getFriendPhoneNumer() + '|';
        lineWithFriendData += newFriend.getFriendEmail() + '|';
        lineWithFriendData += newFriend.getFirnedAddress() + '|';

        file << lineWithFriendData << endl;
        lineWithFriendData = "";

        file.close();
        cout << "Dane zostaly zapisane." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
}

void FriendsFile::saveUserFriendsToVector (vector <Friend> &friends, string line, int numberOfFriends)
{
    string word;
    int verticalLinesNumber = 0;
    int howManyCharactersExpose = 0;
    int beginning = 0 ;

    Friend newFriend;

    howManyCharactersExpose = 0;
    beginning = 0;
    verticalLinesNumber = 0;

    for (int i = 0; i < line.size(); i++)
    {
        howManyCharactersExpose = i - beginning;
        if (line[i] == '|')
        {
            verticalLinesNumber++;
            word = line.substr (beginning,howManyCharactersExpose);
            switch (verticalLinesNumber)
            {
            case 1:
                newFriend.setFriendID(atoi(word.c_str()));
                break;
            case 2:
                newFriend.setUserID(atoi(word.c_str()));
                break;
            case 3:
                newFriend.setFriendName(word);
                break;
            case 4:
                newFriend.setFriendSurname(word);
                break;
            case 5:
                newFriend.setFriendPhoneNumer(word);
                break;
            case 6:
                newFriend.setFriendEmail(word);
                break;
            case 7:
                newFriend.setFriendAddress(word);
                break;
            }
            beginning = beginning + howManyCharactersExpose + 1;
        }
    }
    friends.push_back(newFriend);
}

void FriendsFile::loadFriendsFromFile(vector <Friend> &friends, int loggedUserId)
{
    string line;
    string word;
    int verticalLinesNumber = 0;
    int howManyCharactersExpose = 0;
    int beginning = 0 ;
    int userIDFromFile = 0;
    int numberOfFriends = 0;
    fstream file;

    friends.clear();
    file.open("AddressBook.txt",ios::in); // aby otworzyc plik do odczytu
    if (file.good() == true)
    {
        while (getline(file,line))
        {
            howManyCharactersExpose = 0;
            beginning = 0;
            verticalLinesNumber = 0;

            for (int i = 0; i < line.size(); i++)
            {
                howManyCharactersExpose = i - beginning;
                if (line[i] == '|')
                {
                    verticalLinesNumber++;
                    word = line.substr (beginning, howManyCharactersExpose);
                    userIDFromFile = atoi(word.c_str());
                    if ( verticalLinesNumber == 2 && loggedUserId == userIDFromFile)
                    {
                        numberOfFriends++;
                        saveUserFriendsToVector(friends, line, numberOfFriends);
                        break;
                    }
                    beginning = beginning + howManyCharactersExpose + 1;
                }
            }
        }
        file.close();
    }
}

void FriendsFile::removeLinesFromFile (int loggedUserId)
{
    vector <string> linesToRemove;
    string line;
    string word;
    int verticalLinesNumber = 0;
    int howManyCharactersExpose = 0;
    int beginning = 0 ;
    int userIDFromFile;
    bool foundLine;

    fstream file;
    ofstream newFile;

    linesToRemove.clear();
    file.open("AddressBook.txt", ios::in); // aby otworzyc plik do odczytu
    if (file.good() == true)
    {
        while (getline(file,line))
        {
            howManyCharactersExpose = 0;
            beginning = 0;
            verticalLinesNumber = 0;

            for (int i = 0; i < line.size(); i++)
            {
                howManyCharactersExpose = i - beginning;
                if (line[i] == '|')
                {
                    verticalLinesNumber++;
                    word = line.substr (beginning,howManyCharactersExpose);
                    userIDFromFile = atoi(word.c_str());
                    if ( verticalLinesNumber == 2 && loggedUserId == userIDFromFile)
                    {
                        linesToRemove.push_back(line);
                        break;
                    }
                    beginning = beginning + howManyCharactersExpose + 1;
                }
            }
        }
        file.close();
    }

    newFile.open("fileWithoutALine.txt");
    file.open("AddressBook.txt", ios::in);

    while (getline(file,line))
    {
        foundLine = 0;
        for( int i = 0; i < linesToRemove.size(); i++ )
        {
            if ( line == linesToRemove[i])
            {
                foundLine = 1;
            }
        }
        if (foundLine == 0)
            newFile << line << endl;

    }

    newFile.close();
    file.close();
    remove("AddressBook.txt"); // remove usuwa plik, aby usunac plik musi byc on zamkniety dotyczy to wszystkich funkcji ktorych sie uzywa
    rename("fileWithoutALine.txt","AddressBook.txt");
}

void FriendsFile::saveFriendsDataToFile(vector <Friend> &friends, int loggedUserId)
{
    fstream file;
    string lineWithFriendData = "";
    Conversion number;

    removeLinesFromFile(loggedUserId);

    file.open("AddressBook.txt", ios::out | ios::app);
    if (file.good() == true)
    {
        for (vector <Friend>::iterator itr = friends.begin(); itr != friends.end(); itr++)
        {
            lineWithFriendData += number.conversionIntToString(itr -> getFriendID()) + '|';
            lineWithFriendData += number.conversionIntToString(itr -> getUserID()) + '|';
            lineWithFriendData += itr -> getFriendName() + '|';
            lineWithFriendData += itr -> getFriendSurname() + '|';
            lineWithFriendData += itr -> getFriendPhoneNumer() + '|';
            lineWithFriendData += itr -> getFriendEmail() + '|';
            lineWithFriendData += itr -> getFirnedAddress() + '|';

            file << lineWithFriendData << endl;
            lineWithFriendData = "";
        }
        file.close();
        cout << "Dane zostaly zapisne." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
}
