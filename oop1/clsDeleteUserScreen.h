
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"



    using namespace std;

    class clsDeleteUserScreen :protected clsScreen
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

        static void ShowDeletUserScreen() {
            string accnumber = "";
            char sure;
            clsScreen::_DrawScreenHeader("Delete user screen ");
            cout << "inter UserName ";
            cin >> accnumber;
            while (!clsUser::IsUserExist(accnumber)) {
                cout << "UserName not found please inrer another number : ";
                cin >> accnumber;


            }
            clsUser c1 = clsUser::Find(accnumber);
            _PrintUser(c1);
            cout << "are you sure to delete this User ? y/n";
            cin >> sure;
            if (tolower(sure) == tolower('y')) {
                if (c1.Delete()) {

                    cout << "delete it ";
                    _PrintUser(c1);
                }
                else cout << "error User did not delete it ";

            }

        }
    };









