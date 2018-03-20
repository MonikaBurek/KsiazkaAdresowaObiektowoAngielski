#ifndef FRIENDSFILE_H
#define FRIENDSFILE_H

#include <iostream>
#include <vector>
#include "friend.h"
#include "file.h"

using namespace std;

/*
Klasa odpowiedzialna za operacje na pliku Znajomi.txt
*/

class FriendsFile :public File
{
    fstream file;

public:
    int findNextFriendID();
    void addFriendToFile(Friend newFriend);

    void saveUserFriendsToVector(vector <Friend> &friends, string line, int numberOfFriends);
    void loadFriendsFromFile(vector <Friend> &friends, int loggedUserId);

    void removeLinesFromFile (int loggedUserId);
    void saveFriendsDataToFile(vector <Friend> &friends, int loggedUserId);
};

#endif // FRIENDSFILE_H
