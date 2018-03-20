#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

/*
Klasa na podstawie ktorej jest tworzony Uzytkownik(gettery i settery).
*/

class User
{
    int userID;
    string name;
    string password;

public:
    User();
    virtual ~User();

    int getUserID();
    string getUserName();
    string getUserPassword();

    void setUserID(int userID);
    void setUserName(string name);
    void setUserPassword(string password);
};

#endif // USER_H
