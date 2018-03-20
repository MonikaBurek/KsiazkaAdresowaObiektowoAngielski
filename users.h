#ifndef USERS_H
#define USERS_H

#include <iostream>
#include "usersfile.h"


using namespace std;

/*
Klasa odpowiedzialna m.in. za logowanie, rejestracjê, zmianê has³a, wylogowanie.
*/

class Users
{
    vector <User> users;
    UsersFile applicationUsersFile;
    int LoggedUserId;

public:
    Users();
    User giveNewUserData();
    int getLoggedUserID();
    void registerUser();
    int logInUser();
    void passwordChange();
    int logoutUser();
};

#endif
