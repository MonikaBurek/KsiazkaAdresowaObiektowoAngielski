#ifndef AddressBook_H
#define AddressBook_H

#include <iostream>
#include "FriendsFile.h"

using namespace std;

/*
Klasa odpowiedzialna m.in. za dodawanie nowego znajomego, edycje usuwanie, wyszukiwanie.
*/

class AddressBook
{
    vector <Friend> friends;
    FriendsFile userFriendsFile;
    int loggedUserId;

public:
    AddressBook(int loggedUserId);
    Friend giveNewFriendData();
    void saveNewFriend();
    void searchName();
    void searchSurname();
    void displayAllFriends();
    void editContact();
    void removeContact();
};

#endif
