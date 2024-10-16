#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Glopal.h"










class clsMainScreen: protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients=1,eAddNewClient,eDeleteClient,
		eUpdateClient,eFindClient,eShowTransactionsMenue,
		eManageUsers,eExit
        
};

		
	static short _ReadMainMenueOption() {
		cout << setw(37) << left << "" << "choose what do you want to do from [1] to [8] : ";
		short choise = clsInputValidate::ReadShortNumberBetween(1, 8,"Invalid Number,enter number between 1 and 8 ");
		return choise;

	}


    static void  _GoBackToMainMenue() {

        cout << setw(37) << "" << "press any key to get back to main menu";
        system("pause>0");
        ShowMainMenue();

        
   }


   static void _ShowAllClientsScreen() {

       clsClientListScreen::ShowClientsList();

  }

   static void _ShowAddNewClientsScreen() {

     clsAddNewClientScreen::AddNewClientScreen();

   }

   static void _ShowDeleteClientScreen() {
       clsDeleteClientScreen::ShowDeleteClientScreen();

   }
   static void  _ShowUpdateClientScreen() {

       clsUpdateClientScreen::ShowUpdateClientScreen();

  }


   static void _ShowFindClientScreen() {

       clsFindClientScreen::ShowFindClientScreen();


  }
   static void _ShowManageUsersMenue() {

       clsManageUsersScreen::ShowManageuUsersMenue();


   }


   static void _ShowTransactionsMenue() {

       clsTransactionsScreen::ShowTransactionsMenue();

   }


  


   static void _logout() {
   
       CurrentUser = clsUser::Find("","");

   }


    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            ShowMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            ShowMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _logout();
            //Logeout();

            break;
        }

    }











public:

    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }


};

