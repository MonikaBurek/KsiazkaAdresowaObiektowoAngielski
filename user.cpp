#include <iostream>
#include "user.h"

using namespace std;

User::User()
{
    userID = 0;
    name = "";
    password = "";
}

User::~User()
{
    ;
}

int User::getUserID()
{
    return userID;
}

string User::getUserName()
{
    return name;
}

string User::getUserPassword()
{
    return password;
}

void User::setUserID(int userID)
{
    this -> userID = userID;
}

void User::setUserName(string name)
{
    this -> name = name;
}

void User::setUserPassword(string password)
{
    this -> password = password;
}
