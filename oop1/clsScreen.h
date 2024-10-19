#pragma once
#include <iostream>
#include "Glopal.h"
#include"clsUser.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "") {

        clsDate date = clsDate::GetSystemDate();
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tuser: " << CurrentUser.GetUserName()<<endl;
        cout << "\t\t\t\t\tdate: " << clsDate::DateToString(clsDate());
        cout<<"\n\n";
    }
    static bool CheckAccessRights(clsUser::enPermission Peremission) {

        if (!CurrentUser.ChekceAccessPermisson(Peremission)) {
            system("cls");
            cout << "\t\t\t\t\t___________________________________________";
            cout << "\n\n\t\t\t\t\t Access Denied! Contact uer Admin ";
            cout << "\n\t\t\t\t\t___________________________________________";
            return false;
        }
        else return true;
    }



};

