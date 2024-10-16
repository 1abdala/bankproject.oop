#pragma once
#include "Glopal.h"
#include"clsUser.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"

class clsLoginScreen:clsScreen

{
	static void _login() {
		bool Faildlogine = false;

		do {
			if (Faildlogine) {
				cout << "\nuser name or password is wrong\n";


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


		} while (Faildlogine);
		clsMainScreen::ShowMainMenue();
	}

public:
	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t login screen ");
		_login();


	}

};

