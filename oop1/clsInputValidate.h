#pragma once
#include<iostream>
using namespace std;
#include "clsString.h";
#include "clsDate.h";
#include<vector>
class clsInputValidate
{
public:
	static bool IsNumberBetween(short number, short from, short to) {

		return number >= from && number <= to;

	}

	static bool IsNumberBetween(int number, int from, int to) {

		return number >= from && number <= to;

	}

	static bool IsNumberBetween(float number, float from, float to) {

		return number >= from && number <= to;

	}

	static double IsNumberBetween(double number, double  from, double to) {

		return number >= from && number <= to;

	}



	static bool IsDateBetween(clsDate date(), clsDate from(), clsDate to()) {
		 //date1 >=from & <=to
		if((clsDate::IsDate1AfterDate2(date(), from()) || clsDate::IsDate1EqualDate2(date(), to()))
			&& (clsDate::IsDate1BeforeDate2(date(), to()) || clsDate::IsDate1EqualDate2(date(), to())))
			return true;
		
		//date1 <=from & >=to

		if (clsDate::IsDate1AfterDate2(date(), to()) || clsDate::IsDate1EqualDate2(date(), to())
			&& (clsDate::IsDate1BeforeDate2(date(), from()) || clsDate::IsDate1EqualDate2(date(), to())))
			return true;

		return false;


	}

	static int ReadIntNumber(string invalid) {
		int number;
		cout << "\ninter an intger: ";
		while (true) {
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << invalid;


			}
			else {
				return number;
			}

		}


	}

	static double ReadDplNumber(string invalid) {
		double number;
		cout << "\ninter a duoble: ";
		while (true) {
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << invalid;


			}
			else {
				return number;
			}

		}


	}
	static int  ReadIntNumberBetween(int from, int to, string invalidm) {
		int number;
		cout << "inter a number from " << from << " to " << to << ":";

		number = ReadIntNumber(invalidm);
		while (!IsNumberBetween(number, from, to)) {
			cout << invalidm;
			number = ReadIntNumber(invalidm);


		}
		return number;
	};
	static double ReadDblNumberBetween(double from, double to, string invalidm) {
		double number;
		cout << "inter a number from " << from << " to " << to << ":";

		number =ReadDplNumber(invalidm);
		while (!IsNumberBetween(number, from, to)) {
			cout << invalidm;
			number = ReadIntNumber(invalidm);


		}
		return number;
	}

	static string ReadString() {
		string s1="";
		getline(cin >> ws, s1);
		return s1;


	}
	static	bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}
};