
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"



class clsUpdateUserScreen : protected clsScreen


    {
    static void _ReadCUserInfo(clsUser& User) {

        /*cout << "\ninter Username: ";
        User.UserName = clsInputValidate::ReadString();*/
        cout << "\ninter first name: ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\ninter last name: ";
        User.LastName = clsInputValidate::ReadString();
        cout << "\ninter Email: ";
        User.Email = clsInputValidate::ReadString();
        cout << "\ninter Phone number: ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\ninter Password number: ";
        User.Password = clsInputValidate::ReadString();
        cout << "\ninter Permissions : ";
        User.Permissions = stoi(clsInputValidate::ReadString());
    }
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
        static void ShowUpdatUserScreen() {
            string accnumber = "";
            _DrawScreenHeader("update client screen ");
            cout << "inter client account ";
            cin >> accnumber;
            while (!clsUser::IsUserExist(accnumber)) {
                cout << "account number not found please inter another number : ";
                cin >> accnumber;


            }
            clsUser c1 = clsUser::Find(accnumber);
            _PrintUser(c1);
            cout << "update client info:";
            cout << "are you sure you want to delete this client ? y/n ";
            char answer = 'n';
            cin >> answer;
            if (tolower(answer) == tolower('y')); {
                cout << "\n   update client info:";
                cout << "\n_________________________\n";
                _ReadCUserInfo(c1);
                clsUser::enSaveResults saveresult;
                saveresult = c1.Save();

                switch (saveresult) {

                case clsUser::enSaveResults::svSucceeded:
                {
                    cout << "save has been done -_- ";
                    _PrintUser(c1);
                    break;

                }

                case clsUser::enSaveResults::svFaildEmptyObject:
                    cout << "save faild";
                    break;
                }


            }
        }


    };



