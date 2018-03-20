#include <iostream>
#include "usersfile.h"
#include <windows.h>
#include <cstdlib>
#include "conversion.h"

using namespace std;


void UsersFile::loadUsersFromFile( vector <User> &users)
{
    string line;
    string word;
    int verticalLinesNumber = 0;
    int howManyCharactersExpose = 0;
    int beginning = 0 ;
    User user;

    users.clear();
    file.open("Users.txt",ios::in); // aby otworzyc plik do odczytu
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
                    switch (verticalLinesNumber)
                    {
                    case 1:
                        user.setUserID(atoi(word.c_str()));
                        break;
                    case 2:
                        user.setUserName(word);
                        break;
                    case 3:
                        user.setUserPassword(word);
                        break;
                    }
                    beginning = beginning + howManyCharactersExpose + 1;
                }
            }
            users.push_back(user);
        }
        file.close();
    }
}

void UsersFile::saveUsersDataToFile( vector <User> &users)
{
    string lineWithUserData = "";
    file.open("Users.txt", ios::out);
    Conversion number;

    if (file.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {

            lineWithUserData += number.conversionIntToString(itr -> getUserID()) + '|';
            lineWithUserData += itr -> getUserName() + '|';
            lineWithUserData += itr -> getUserPassword() + '|';

            file << lineWithUserData << endl;
            lineWithUserData = "";
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

void UsersFile::addUserToFile(User newUser)
{
    string lineWithUserData = "";
    file.open("Users.txt", ios::out | ios::app);
    Conversion number;

    if (file.good() == true)
    {
        lineWithUserData += number.conversionIntToString(newUser.getUserID()) + '|';
        lineWithUserData += newUser.getUserName() + '|';
        lineWithUserData += newUser.getUserPassword() + '|';

        file << lineWithUserData << endl;
        lineWithUserData = "";

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
