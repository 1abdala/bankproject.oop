#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen :protected clsScreen
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

    static void ShowDeleteClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
            
            return;

        }
        string accnumber = "";
        char sure;
        clsScreen::_DrawScreenHeader("Delete client screen ");
        cout << "inter client number ";
        cin >> accnumber;
        while (!clsBankClient::IsClientExist(accnumber)) {
            cout << "account number not found please inrer another number : ";
            cin >> accnumber;


        }
        clsBankClient c1 = clsBankClient::Find(accnumber);
        _PrintClient(c1);
        cout << "are you sure to delete this clident ? y/n";
        cin >> sure;
        if (tolower(sure) == tolower('y')) {
            if (c1.Delete()) {

                cout << "delete it ";
                _PrintClient(c1);
            }
            else cout << "error client did not delete it ";

        }

    }
};





