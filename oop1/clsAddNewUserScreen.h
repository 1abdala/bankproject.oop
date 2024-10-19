
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUser.h"

class clsAddNewUserScreen :protected clsScreen
{

    static void _ReadCUserInfo(clsUser & User) {

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


    static void AddNewUserScreen() {


        string UserName = "";
        _DrawScreenHeader("Add New User Screen");
        cout << "inter Username : ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName)) {

            cout << " UserName exist, inter another One : ";
            UserName = clsInputValidate::ReadString();


        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadCUserInfo(NewUser);
        clsUser::enSaveResults result;
        result = NewUser.Save();

        switch (result) {

        case clsUser::enSaveResults::svSucceeded:
        {
            _PrintUser
            
            (NewUser);
            cout << "saved :-)";
            break;
        }


        case clsUser::enSaveResults::svFaildUserExists:
        {

            cout << "\nError account was not saved because it's already exists";
            break;



        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {

            cout << "\nError account was not saved because it's empty ";
            break;



        }

        }
    }


};
