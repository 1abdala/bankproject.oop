#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsFindCUserScreen :protected clsScreen
{
    static void _PrintUser(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions     : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen() {
        string Username;
        clsScreen::_DrawScreenHeader("find client screen ");
        cout << "inter client number:  ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username)) {
            cout << "account number not found please inrer another number : ";
            cin >> Username;


        }
        clsUser User = clsUser::Find(Username);

        if (!User.IsEmpty()) {

            cout << "client is found ";

        }

        else cout << "client is not found ";



        _PrintUser(User);


    }
};

