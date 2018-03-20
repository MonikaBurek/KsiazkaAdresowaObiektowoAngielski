#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "users.h"
#include "AddressBook.h"

using namespace std;

int main()
{
    Users usersList;

    char selectedMenuItem;

    while(1)
    {
        if(usersList.getLoggedUserID() == 0)
        {
            system("cls");
            cout << "1.Rejestracja" << endl;
            cout << "2.Logowanie" << endl;
            cout << "9.Zamknij program" << endl;
            cin >> selectedMenuItem;

            switch(selectedMenuItem)
            {
            case '1':
                usersList.registerUser();

                break;
            case '2':
                usersList.logInUser();
                break;
            case '9':
                exit(0);
                break;
            }
        }
        else if(usersList.getLoggedUserID() > 0)
        {
            AddressBook friendsList(usersList.getLoggedUserID());
            system("cls");
            cout<< "Ksiazka adresowa."<<endl<<endl;
            cout << "1.Zapisz nowego znajomego." << endl;
            cout << "2.Wyszukaj znajomego." << endl;
            cout << "3.Wyswietl liste znajomych." << endl;
            cout << "4.Edytuj kontakt." << endl;
            cout << "5.Usun kontakt." << endl;
            cout << "6.Zmien haslo." << endl;
            cout << "9.Wyloguj sie." << endl<<endl;
            cin>> selectedMenuItem;

            switch(selectedMenuItem)
            {
            case '1':
                friendsList.saveNewFriend();
                break;
            case '2':

                system("cls");
                cout<< "Wyszukiwanie znajomego." <<endl<< endl;
                cout<<"1.Wyszukiwanie wg imienia." <<endl;
                cout<<"2.Wyszukiwanie wg nazwiska." <<endl;
                cout<<"9.Zakoncz wyszukiwanie."<< endl;
                cin>> selectedMenuItem;

                switch(selectedMenuItem)
                {
                case '1':
                    friendsList.searchName();
                    break;
                case '2':
                    friendsList.searchSurname();
                    break;
                case '9':
                    system("pause");
                }
                break;
            case '3':
                friendsList.displayAllFriends();
                break;
            case '4':
                friendsList.editContact();
                break;
            case '5':
                friendsList.removeContact();
                break;
            case '6':
                usersList.passwordChange();
                break;
            case '9':
                usersList.logoutUser();
                break;
            }
        }
    }

    return 0;
}

