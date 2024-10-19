#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsTotalBalancesScreen.h"




class clsTransactionsScreen : protected clsScreen
{
    
        enum enTransactionsMenueOption {
            eDeposit = 1, eWithdarw,eTotalbalance, eExit

        };


        static short _ReadTransactionsMenueOption() {
            cout << setw(37) << left << "" << "choose what do you want to do from [1] to [4] : ";
            short choise = clsInputValidate::ReadShortNumberBetween(1, 4, "Invalid Number,enter number between 1 and 4 ");
            return choise;

        }


        static void  _GoBackToMainMenue() {

            cout << setw(37) << "" << "press any key to get back to main menu";
            system("pause>0");
            ShowTransactionsMenue();


        }
        
        static void _ShowDepositScreen() {

            clsDepositScreen::ShowDepositScreen();
 }
        static void _ShowWithdarwScreen() {

            clsWithdrawScreen::ShowWithdrawScreen();
        }


        static void _ShowTotalbalanceScreen() {

            clsTotalBalancesScreen::ShowTotalBalances();


        }

       

        static void _PerfromTransactionsMenueOption(enTransactionsMenueOption MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enTransactionsMenueOption::eDeposit:
            {
                system("cls");
                _ShowDepositScreen();
                _GoBackToMainMenue();
                break;
            }
            case enTransactionsMenueOption::eWithdarw:
                system("cls");
                _ShowWithdarwScreen();
                _GoBackToMainMenue();
                break;

            case enTransactionsMenueOption::eTotalbalance:
                system("cls");
                _ShowTotalbalanceScreen();
                _GoBackToMainMenue();
                break;

            

            case enTransactionsMenueOption::eExit:
                system("cls");
               
                //Login();

                break;
            }

        }
    
public:
	static void ShowTransactionsMenue() {

        if (!CheckAccessRights(clsUser::enPermission::pTranactions)) {

            return;

        }
        system("cls");
		_DrawScreenHeader("\tTransactions screen");
        

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionsMenueOption((enTransactionsMenueOption)_ReadTransactionsMenueOption());



    }



};

