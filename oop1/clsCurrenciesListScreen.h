#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsCurrency.h"

class clsCurrenciesListScreen : protected clsScreen
{


    private:
        static void _PrintCurrencyRecordLine(clsCurrency Currency)
        {

            cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
            cout << "| " << setw(7) << left << Currency.CurrencyCode();
            cout << "| " << setw(30) << left << Currency.CurrencyName();
            cout << "| " << setw(20) << left << Currency.Rate();

        }

    public:


        static void ShowUsersList()
        {


            vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

            string Title = "\t  currencies List Screen";
            string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currencies(s).";

            _DrawScreenHeader(Title, SubTitle);


            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
            cout << "| " << left << setw(7) << "Code";
            cout << "| " << left << setw(30) << "Name";
            cout << "| " << left << setw(20) << "Rate";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vCurrencies.size() == 0)
                cout << "\t\t\t\tNo Curencies Available In the System!";
            else

                for (clsCurrency Currency : vCurrencies)
                {

                    _PrintCurrencyRecordLine(Currency);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }


    };

