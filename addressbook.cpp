#include <iostream>
#include "AddressBook.h"
#include <windows.h>
#include "file.h"


using namespace std;

AddressBook::AddressBook(int idLoginUser)
{
    loggedUserId = idLoginUser;
}

Friend AddressBook::giveNewFriendData()
{
    string name, surname, address, phoneNumber, email;
    int friendID, userID;
    Friend newFriend;
    FriendsFile userFriendsFile;

    cout << endl << "Zapisywanie nowego znajomego." << endl << endl;
    cout << "Podaj imie: ";
    cin >> name;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin,phoneNumber);
    cout << "Podaj mail: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin,address);

    friendID = userFriendsFile.findNextFriendID();
    userID = loggedUserId;

    newFriend.setFriendID(friendID);
    newFriend.setUserID(userID);
    newFriend.setFriendName(name);
    newFriend.setFriendSurname(surname);
    newFriend.setFriendPhoneNumer(phoneNumber);
    newFriend.setFriendEmail(email);
    newFriend.setFriendAddress(address);

    return newFriend;
}

void AddressBook::saveNewFriend()
{
    bool isFileEmpty;
    isFileEmpty = userFriendsFile.isFileEmpty("AddressBook.txt");

    if (isFileEmpty == 1) //"Plik zawiera dane." << endl;
        userFriendsFile.loadFriendsFromFile(friends, loggedUserId);

    Friend newFriend = giveNewFriendData();

    friends.push_back(newFriend);
    userFriendsFile.addFriendToFile(newFriend);

    cout << "Dane znajomego zostaly zapisne." << endl;
    Sleep(1000);
}

void AddressBook::searchName()
{
    userFriendsFile.loadFriendsFromFile(friends,loggedUserId);

    string searchedName;
    bool foundFriend = 0;
    cout << endl << "Podaj imie znajomego, ktorego wyszukac: ";
    cin >> searchedName;

    for (vector <Friend>::iterator itr = friends.begin(); itr != friends.end(); itr++)
    {
        if (itr -> getFriendName() == searchedName)
        {
            foundFriend = 1;
            cout << endl;
            cout << "Numer ID Znajomego: " << itr -> getFriendID() << endl;
            cout << itr -> getFriendName() << " " << itr -> getFriendSurname() << endl;
            cout << "Numer telefonu: " << itr -> getFriendPhoneNumer() << endl;
            cout << "Mail: " << itr -> getFriendEmail() << endl;
            cout << "Adres: " << itr -> getFirnedAddress() << endl;
            cout << endl;
        }
    }

    if(!foundFriend)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << endl << "Nie znaleziono osoby o tym imieniu." << endl << endl;
    }
    system("pause");
}

void AddressBook::searchSurname()
{
    userFriendsFile.loadFriendsFromFile(friends,loggedUserId);

    string searchedSurname;
    bool foundFriend = 0;
    cout << endl << "Podaj nazwisko znajomego, ktorego wyszukac: ";
    cin >> searchedSurname;

    for (vector <Friend>::iterator itr = friends.begin(); itr != friends.end(); itr++)
    {
        if (itr -> getFriendSurname() == searchedSurname)
        {
            foundFriend = 1;
            cout << endl;
            cout << "Numer ID Znajomego: " << itr -> getFriendID() << endl;
            cout << itr -> getFriendName() << " " << itr -> getFriendSurname() << endl;
            cout << "Numer telefonu: " << itr -> getFriendPhoneNumer() << endl;
            cout << "Mail: " << itr -> getFriendEmail() << endl;
            cout << "Adres: " << itr -> getFirnedAddress() << endl;
            cout << endl;
        }
    }

    if(!foundFriend)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << endl << "Nie znaleziono osoby o tym imieniu." << endl << endl;
    }
    system("pause");
}

void AddressBook::displayAllFriends()
{
    userFriendsFile.loadFriendsFromFile(friends,loggedUserId);

    for (vector <Friend>::iterator itr = friends.begin(); itr != friends.end(); itr++)
    {
        cout << endl;
        cout << "Numer ID Znajomego: " << itr -> getFriendID() << endl;
        cout << itr -> getFriendName() << " " << itr -> getFriendSurname() << endl;
        cout << "Numer telefonu: " << itr -> getFriendPhoneNumer() << endl;
        cout << "Mail: " << itr -> getFriendEmail() << endl;
        cout << "Adres: " << itr -> getFirnedAddress() << endl;
        cout << endl;
    }
    system("pause");
}

void AddressBook::editContact()
{
    string phoneNumber, email, address;
    char selectedMenuItem;

    int searchedIdNumber;
    bool foundFriend = 0;
    int foundPersonPosition = 0;

    userFriendsFile.loadFriendsFromFile(friends, loggedUserId);

    cout << "Wyszukanie znajomego. Podaj numer ID znajomego: ";
    cin >> searchedIdNumber;

    for (vector <Friend>::iterator itr = friends.begin(); itr != friends.end(); itr++)
    {
        if (itr -> getFriendID() == searchedIdNumber)
        {
            foundFriend = 1;
            system("cls");
            cout << "Edycja kontaktu." << endl;
            cout << endl;
            cout << "Numer ID Znajomego: " << itr -> getFriendID() << endl;
            cout << itr -> getFriendName() << " " << itr -> getFriendSurname() << endl;
            cout << "Numer telefonu: " << itr -> getFriendPhoneNumer() << endl;
            cout << "Mail: " << itr -> getFriendEmail() << endl;
            cout << "Adres: " << itr -> getFirnedAddress() << endl;
            cout << endl;

            cout << "1.Edytuj numer telefonu." << endl;
            cout << "2.Edytuj adres mailowy." << endl;
            cout << "3.Edytuj adres kontaktowy." << endl;
            cout << "4.Edytuj wszystkie informacje." << endl;
            cout << "9.Zakoncz edycje." << endl<<endl;
            cin>> selectedMenuItem;

            switch(selectedMenuItem)
            {
            case '1':
                cout << "Podaj nowy numer telefonu: ";
                cin.sync();
                getline(cin,phoneNumber);
                friends[foundPersonPosition].getFriendPhoneNumer() = phoneNumber;
                friends[foundPersonPosition].setFriendPhoneNumer(phoneNumber);
                break;
            case '2':
                cout << "Podaj nowy adres mailowy: ";
                cin >>  email;
                friends[foundPersonPosition].getFriendEmail() = email;
                friends[foundPersonPosition].setFriendEmail(email);
                break;
            case '3':
                cout << "Podaj nowy adres kontaktowy: ";
                cin.sync();
                getline(cin,address);
                friends[foundPersonPosition].getFirnedAddress() = address;
                friends[foundPersonPosition].setFriendAddress(address);
                break;
            case '4':
                cout << "Podaj nowy numer telefonu: ";
                cin.sync();
                getline(cin,phoneNumber);
                cout << "Podaj nowy adres mailowy: ";
                cin >>  email;
                cout << "Podaj nowy adres kontaktowy: ";
                cin.sync();
                getline(cin,address);

                friends[foundPersonPosition].getFriendPhoneNumer() = phoneNumber;
                friends[foundPersonPosition].getFriendEmail() = email;
                friends[foundPersonPosition].getFirnedAddress() = address;

                friends[foundPersonPosition].setFriendPhoneNumer(phoneNumber);
                friends[foundPersonPosition].setFriendEmail(email);
                friends[foundPersonPosition].setFriendAddress(address);

                break;
            case '9':
                system("pause");
                break;
            }
            cout << "Edycja kontaktu przebiegla pomyslnie." << endl << endl;

        }
        foundPersonPosition++;
    }

    if(!foundFriend)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << endl << "Nie znaleziono osoby o podanym: imieniu i nazwisku." << endl << endl;
        system("pause");
    }

    userFriendsFile.saveFriendsDataToFile(friends,loggedUserId);
}

void AddressBook::removeContact()
{
    int searchedIdNumber;

    userFriendsFile.loadFriendsFromFile(friends,loggedUserId);

    cout << "Wyszukanie znajomego. Podaj numer ID znajomego: ";
    cin >> searchedIdNumber;

    for (vector <Friend>::iterator itr = friends.begin(); itr != friends.end(); itr++)
    {
        if (itr -> getFriendID() == searchedIdNumber)
        {
            itr = friends.erase(itr);
            cout << "Kontakt zostal usuniety." << endl << endl;
            system("pause");
            break;
        }
    }

    userFriendsFile.saveFriendsDataToFile(friends,loggedUserId);
}

