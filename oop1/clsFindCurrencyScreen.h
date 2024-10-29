#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>
using namespace std;


class clsFindCurrencyScreen:clsScreen
{

static short _chois() {
	short choise;
		cout << "Find by: [1] code or [2] Country ? ";
		choise=	clsInputValidate::ReadShortNumberBetween(1, 2,"Inter number between 1 and 2: ");
		return choise;
	}


static void PrintCurrency(clsCurrency Currency) {

	cout << "\ncurrency card:\n ";
	cout << left<<"________________________________________________\n";
	cout << setw(10) << "country " << ":" << Currency.Country()<<endl;
	cout << setw(10) << "Code " << ":" << Currency.CurrencyCode() << endl;
	cout << setw(10) << "Name " << ":" << Currency.CurrencyName() << endl;
	cout << setw(10) << "Rate(1$) " << ":" << Currency.Rate() << endl;
	cout << left<<"________________________________________________\n";


}


public:

	static void FindCurrency() {

		_DrawScreenHeader("\tFind Currency Screen");

		short Choise = _chois();
		if (Choise == 1) {
			string code;
			cout << "Please Inter Currency Code: ";
			code =clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(code);
			if (!Currency.IsEmpty()) {

				PrintCurrency(Currency);

			}

			else cout << "\nCurrency with this code not found ";


		}

		else {

			string Name;
			cout << "Please Inter Country Name: ";
			Name=clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Name);
			if (!Currency.IsEmpty()) {

				PrintCurrency(Currency);

			}
			else cout << "\nCurrency with this Name not found ";
		
		}





	}




};

