#ifndef AddressBook_H
#define AddressBook_H

#include <iostream>
#include "FriendsFile.h"

using namespace std;

/*
The class responsible for adding a new friend, editing, deleting, searching for a friend.
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
