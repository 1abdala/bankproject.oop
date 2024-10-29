#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsCurrencyCalculatorScreen :clsScreen
{

private:
    static void PrintCurrency(clsCurrency Currency) {

        
        cout << left << "________________________________________________\n";
        cout << setw(10) << "country " << ":" << Currency.Country() << endl;
        cout << setw(10) << "Code " << ":" << Currency.CurrencyCode() << endl;
        cout << setw(10) << "Name " << ":" << Currency.CurrencyName() << endl;
        cout << setw(10) << "Rate(1$) " << ":" << Currency.Rate() << endl;
        cout << left << "________________________________________________\n";


    }




    static bool _ShowResults(clsCurrency Currency) {
        if (!Currency.IsEmpty()) {

            return true;
        }

        else cout << "no country with this code avilable";
        return false;


    }

    static void _Convertform(clsCurrency Currency1, clsCurrency Currency2,float amount) {
        
        if (Currency2.CurrencyCode() == "USD") {
            cout << "\coveert form:\n ";
            PrintCurrency(Currency1);
            cout << amount << Currency1.CurrencyCode() << '=';
            cout << amount / Currency1.Rate();
        }
        else {
            double currency1todollar = amount / Currency1.Rate();
            cout << "\coveert form:\n ";
            PrintCurrency(Currency1);
            cout << amount << " " << Currency1.CurrencyCode() << " = " << currency1todollar <<" usd \n";
            cout << "coverting from usd to:\n"; 
            cout<<"to:\n ";
            PrintCurrency(Currency2);

            cout<<endl << amount << " " << Currency1.CurrencyCode() << "=" << currency1todollar*Currency2.Rate()<<endl;


        }
    }


public:

    static void ShowCurrencyCalculatorScreen() {
        char answer = 'n';
        string code1, code2;
        float amount;
        do {
            system("cls");
            _DrawScreenHeader("\tUpdate Currency Screen");
            cout << "please inter currency 1 code: ";
            cin >> code1;

            cout << "please inter currency 2 code: ";
            cin >> code2;

            cout << "inter mount to exhnage";
            cin >> amount;



            clsCurrency Currency1 = clsCurrency::FindByCode(code1);
            clsCurrency Currency2 = clsCurrency::FindByCode(code2);

            if (_ShowResults(Currency1) && _ShowResults(Currency2)) {
                _Convertform(Currency1, Currency2, amount);


            }
            
            cout << "\ndo you want to perform another calculation ? y/n";
            cin >> answer;


        } 
        while (tolower(answer) == 'y');

    }




};

