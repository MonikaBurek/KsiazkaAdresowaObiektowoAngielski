#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <vector>
#include <fstream>
#include "users.h"

using namespace std;

/*
The class from which Friend is created (getters and setters).
*/

class Friend
{
    string name, surname, phoneNumber, email, address;
    int friendID, userID;

public:
    Friend();
    virtual ~Friend();

    int getFriendID();
    int getUserID();
    string getFriendName();
    string getFriendSurname();
    string getFriendPhoneNumer();
    string getFriendEmail();
    string getFirnedAddress();

    void setFriendID(int friendID);
    void setUserID(int userID);
    void setFriendName(string name);
    void setFriendSurname(string surname);
    void setFriendPhoneNumer(string phoneNumber);
    void setFriendEmail(string email);
    void setFriendAddress(string address);
};

#endif // FRIEND_H
