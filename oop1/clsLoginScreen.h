#pragma once
#include "Glopal.h"
#include"clsUser.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"

class clsLoginScreen:clsScreen
	
{
	static bool _login() {
		bool Faildlogine = false;
		short count = 3;

		do {

			if (Faildlogine) {
				cout << "\nuser name or password is wrong\n";
				count--;
				cout << "you have " <<count <<"(s) trailes to login.\n\n";
				
			}
			if (count == 0) {
				cout<<"you have been locked after 3 trais";
				return false ;
			}
			string username;
			cout << "Inter UserName: ";
			username = clsInputValidate::ReadString();
			string pass;
			cout << "\nInter a password: ";
			pass = clsInputValidate::ReadString();
			CurrentUser = clsUser::Find(username, pass);
			if (CurrentUser.IsEmpty()) {

				Faildlogine = true;
			}
			else Faildlogine = false;

		} while (Faildlogine);
		CurrentUser.RigesterLogin();
		clsMainScreen::ShowMainMenue();

		return true;
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t login screen ");
		return _login();


	}

};

