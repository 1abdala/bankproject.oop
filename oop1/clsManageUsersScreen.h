#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"





class clsManageUsersScreen:clsScreen
{
    enum enUsersMenueOption {
        eListUsers = 1, eAddNewUser, eDeleteUser,
        eUpdateUser, eFindUser, eExit

    };


    static short _ReadManageUsersMenueOption() {
        cout << setw(37) << left << "" << "choose what do you want to do from [1] to [6] : ";
        short choise = clsInputValidate::ReadShortNumberBetween(1, 6, "Invalid Number,enter number between 1 and 6 ");
        return choise;

    }


    static void  _GoBackToManageUsersMenue() {

        cout << setw(37) << "" << "press any key to get back to main menu";
        system("pause>0");
        ShowManageuUsersMenue();


    }

    static void _ShowAllUsersScreen() {

        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen() {

        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen() {

        clsDeleteUserScreen::ShowDeletUserScreen();
    }
    static void _ShowUpdateUserScreen() {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindCUserScreen() {

        clsFindCUserScreen::ShowFindUserScreen();
    } 
   
    static void _PerfromManageUsersMenueOption(enUsersMenueOption MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enUsersMenueOption::eListUsers:
        {
            system("cls");
            _ShowAllUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enUsersMenueOption::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case enUsersMenueOption::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case enUsersMenueOption::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case enUsersMenueOption::eFindUser:
            system("cls");
            _ShowFindCUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case enUsersMenueOption::eExit:
            system("cls");
           
            break;
           
        }

    }

public:
    static void ShowManageuUsersMenue() {

        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {

            return;

        }
        system("cls");
        _DrawScreenHeader("\tManage users screen");


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Manage users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show user List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New user.\n";
        cout << setw(37) << left << "" << "\t[3] Delete user.\n";
        cout << setw(37) << left << "" << "\t[4] Update user Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find user.\n";
        cout << setw(37) << left << "" << "\t[6] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromManageUsersMenueOption((enUsersMenueOption)_ReadManageUsersMenueOption());



    }





};

