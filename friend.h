#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <vector>
#include <fstream>
#include "users.h"

using namespace std;

/*
Klasa na podstawie ktorej jest tworzony Friend(gettery i settery).
*/

class Friend
{
    string name, surname, phoneNumber, email, address;
    int friendID, userID;

public:
    Friend();
    virtual ~Friend();

    //Zwraca (get) numer ID nazwe i haslo Uzytkownika
    int getFriendID();
    int getUserID();
    string getFriendName();
    string getFriendSurname();
    string getFriendPhoneNumer();
    string getFriendEmail();
    string getFirnedAddress();

    //Ustawia (set) numer ID uzytkownika, nazwê
    void setFriendID(int friendID);
    void setUserID(int userID);
    void setFriendName(string name);
    void setFriendSurname(string surname);
    void setFriendPhoneNumer(string phoneNumber);
    void setFriendEmail(string email);
    void setFriendAddress(string address);
};

#endif // FRIEND_H
