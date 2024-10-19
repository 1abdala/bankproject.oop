#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsFindClientScreen :protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:

   static void ShowFindClientScreen() {

       if (!CheckAccessRights(clsUser::enPermission::pFindClient)) {

           return;

       }
        string accnumber;
        clsScreen::_DrawScreenHeader("find client screen ");
        cout << "inter client number:  ";
        accnumber= clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(accnumber)) {
            cout << "account number not found please inrer another number : ";
            cin >> accnumber;


        }
        clsBankClient c1 = clsBankClient::Find(accnumber);

        if (!c1.IsEmpty()) {

            cout << "client is found ";

        }

        else cout << "client is not found ";



        _PrintClient(c1);


    }
};

