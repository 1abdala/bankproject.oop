#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRate:clsScreen
{
	static void PrintCurrency(clsCurrency Currency) {

		cout << "\ncurrency card:\n ";
		cout << left << "________________________________________________\n";
		cout << setw(10) << "country " << ":" << Currency.Country() << endl;
		cout << setw(10) << "Code " << ":" << Currency.CurrencyCode() << endl;
		cout << setw(10) << "Name " << ":" << Currency.CurrencyName() << endl;
		cout << setw(10) << "Rate(1$) " << ":" << Currency.Rate() << endl;
		cout << left << "________________________________________________\n";


	}

	static bool _ShowResults(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			PrintCurrency(Currency);
			return true;
		}

		else cout << "no country with this code avilable";
		return false;


	}

	static void UpdateCurrencyRate(clsCurrency &Currency){
		float rate;
		cout << "\n\nUpdate Currency rate:\n";
		cout << "______________________________\n";
		cout << "enter a new rate: ";
		rate=clsInputValidate::ReadDplNumber();
		Currency.UpdateRate(rate);
		


	}


public:

	static void ShowsUpdateCurrencyRateScreen() {

		_DrawScreenHeader("Update Currency Rate Screen");

		cout << "Please Inter a country code: ";
		clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::ReadString());
		if (_ShowResults(Currency)) {
			char answer;
			cout << "Are you sure you want to change the rate of this currency y/n ? ";
			cin >> answer;
			if (tolower(answer) == 'y') {

				UpdateCurrencyRate(Currency);
				cout << "Currrency rate updated successfuly :)";
				PrintCurrency(Currency);



			}


		}



 }



};

