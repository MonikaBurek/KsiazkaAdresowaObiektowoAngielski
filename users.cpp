#include <iostream>
#include "users.h"
#include <windows.h>
#include "file.h"


using namespace std;


Users::Users()
{
    LoggedUserId = 0;
}

int Users::getLoggedUserID()
{
    return LoggedUserId;
}

User Users::giveNewUserData()
{
    string userName, userPassword;
    int userID;
    User newUser;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> userName;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        while(itr -> User::getUserName() == userName)
        {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> userName;
        }
    }

    cout << "Podaj haslo: ";
    cin >> userPassword;

    if (users.empty() == true)  // je¿eli ksiazka adresowa jest pusta
    {
        userID = 1;           // to nowy adresat ma id=1
    }
    else
    {
        userID = users.back().getUserID() + 1; // w przeciwnym przypadku pobierz id ostatniej osoby z ksiazki adresowej i zwiêksz wartoœæ o jeden.
    }


    newUser.setUserName(userName);
    newUser.setUserPassword(userPassword);
    newUser.setUserID(userID);

    return newUser;
}

void Users::registerUser()
{
    bool isFileEmpty;
    isFileEmpty = applicationUsersFile.isFileEmpty("Users.txt");

    if (isFileEmpty == 1)
        applicationUsersFile.loadUsersFromFile(users);

    User newUser = giveNewUserData();

    users.push_back(newUser);
    applicationUsersFile.addUserToFile(newUser);

    cout << endl << "Konto zalozone." << endl;
    Sleep(1000);
}

int Users::logInUser()
{
    string userName, userPassword;
    bool foundUser = 0;
    int attempts = 0;
    bool isFileEmpty;

    isFileEmpty = applicationUsersFile.isFileEmpty("Users.txt");

    if (isFileEmpty == 1)
        applicationUsersFile.loadUsersFromFile(users);

    cout << "Podaj nazwe uzytkownika: ";
    cin >>  userName;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if(itr -> getUserName() == userName)
        {
            foundUser = 1;
            for(int attemptsNumber = 0; attemptsNumber < 3; attemptsNumber++)
            {
                attempts = attemptsNumber + 1;
                cout << "Podaj haslo. Pozostalo prob " << 3 - attemptsNumber << ":";
                cin >> userPassword;
                if (itr -> getUserPassword() == userPassword)
                {
                    cout<< "Zalogowales sie."<<endl;
                    LoggedUserId = itr -> getUserID();
                    return LoggedUserId;
                }
            }
            if( attempts == 3)
            {
                cout << "Podales 3 razy bledne haslo.Poczekaj przez 3 sekundy przed kolejna proba." << endl;
            }
        }
    }

    if(!foundUser)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << "Nie ma uzytkownika z takim loginem." << endl;
    }

    Sleep(1500);
    return 0;
}

void Users::passwordChange( )
{
    string userPassword;
    int foundPersonPosition = 0;

    cout << "Podaj nowe haslo: ";
    cin >> userPassword;

    applicationUsersFile.loadUsersFromFile(users);

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if(itr -> getUserID() == getLoggedUserID())
        {
            users[foundPersonPosition].getUserPassword() = userPassword;
            users[foundPersonPosition].setUserPassword(userPassword);
            cout << "Haslo zostalo zmienione." << endl;
            Sleep(1500);
        }
        foundPersonPosition++;
    }


    applicationUsersFile.saveUsersDataToFile(users);
}

int Users::logoutUser()
{
    LoggedUserId = 0;
    return LoggedUserId;
}

