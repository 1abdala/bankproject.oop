
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"



    using namespace std;

    class clsCurrencyMainScreen :protected clsScreen
    {


    private:
        enum enCurrencyMenueOptions {
            eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
            eCurrencyCalculator = 4, eExit = 5
        };

        static short _ReadCurrencyMenueOption()
        {
            cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
            return Choice;
        }

        static  void _GoBackToCurrencyMainMenue()
        {
            cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Curreency Menue...\n";

            system("pause>0");
            ShowCurrencyMenue();
        }

        static void _ShoweListCurrenciesScreen()
        {
            clsCurrenciesListScreen::ShowUsersList();

        }

        static void _ShowFindCurrencyScreen()
        {
            clsFindCurrencyScreen::FindCurrency();

        }

        static void _ShoweUpdateRateScreen()
        {
            clsUpdateCurrencyRate::ShowsUpdateCurrencyRateScreen();

        }

        static void _ShowCurrencyCalculatorScreen()
        {
            clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();


        }


        static void _Logout()
        {
            

        }

       

        

        static void _PerfromCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOption)
        {
            switch (CurrencyMenueOption)
            {
            case enCurrencyMenueOptions::eListCurrencies:
            {
                system("cls");
                _ShoweListCurrenciesScreen();
                _GoBackToCurrencyMainMenue();
                break;
            }
            case enCurrencyMenueOptions::eFindCurrency:
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyMainMenue();
                break;

            case enCurrencyMenueOptions::eUpdateRate:
                system("cls");
                _ShoweUpdateRateScreen();
                _GoBackToCurrencyMainMenue();
                break;

            case enCurrencyMenueOptions::eCurrencyCalculator:
                system("cls");
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrencyMainMenue();
                break;

            

            case enCurrencyMenueOptions::eExit:
                system("cls");
                _Logout();
                break;
            }

        }



    public:


        static void ShowCurrencyMenue()
        {

            system("cls");
            _DrawScreenHeader("\tCurrency Exhange Main Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\Currency Exhange  Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List All Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromCurrencyMenueOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
        }
        

    };





