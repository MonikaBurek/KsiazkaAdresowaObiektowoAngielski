#ifndef USERS_H
#define USERS_H

#include <iostream>
#include "usersfile.h"


using namespace std;

/*
The class responsible for logging in, registering, changing the password, logging out
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
