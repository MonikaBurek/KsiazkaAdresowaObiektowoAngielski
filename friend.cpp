#include <iostream>
#include <vector>
#include <fstream>
#include "friend.h"
#include "user.h"

using namespace std;

Friend::Friend()
{
    friendID = 0;
    userID = 0;
    name = "";
    surname = "";
    phoneNumber = "";
    email = "";
    address = "";
}

Friend::~Friend()
{
    ;
}

int Friend::getFriendID()
{
    return friendID;
}
int Friend::getUserID()
{
    return userID;
}

string Friend::getFriendName()
{
    return name;
}
string Friend::getFriendSurname()
{
    return surname;
}
string Friend::getFriendPhoneNumer()
{
    return phoneNumber;
}
string Friend::getFriendEmail()
{
    return email;
}
string Friend::getFirnedAddress()
{
    return address;
}

void Friend::setFriendID(int friendID)
{
    this -> friendID = friendID;
}
void Friend::setUserID(int userID)
{
    this -> userID = userID;
}
void Friend::setFriendName(string name)
{
    this -> name = name;
}
void Friend::setFriendSurname(string surname)
{
    this -> surname = surname;
}
void Friend::setFriendPhoneNumer(string phoneNumber)
{
    this -> phoneNumber = phoneNumber;
}
void Friend::setFriendEmail(string email)
{
    this -> email = email;
}
void Friend::setFriendAddress(string address)
{
    this -> address = address;
}
