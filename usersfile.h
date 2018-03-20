#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include "user.h"
#include "file.h"

using namespace std;

/*
Klasa odpowiedzialna za operacje na pliku Uzytkownicy.txt
*/

class UsersFile :public File
{
    fstream file;

public:
    void loadUsersFromFile(vector <User> &users);
    void saveUsersDataToFile (vector <User> &users);
    void addUserToFile(User newUser);
};

#endif // USERSFILE_H
