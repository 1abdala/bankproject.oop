#pragma once
#include <iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferLogScreen:clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsBankClient::stTrasnferLog LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.date;
        cout << "| " << setw(15) << left << LoginRegisterRecord.SourceClient;
        cout << "| " << setw(15) << left << LoginRegisterRecord.DestenitionClient;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Amount;
        cout << "| " << setw(10) << left << LoginRegisterRecord.SClientBalance;
        cout << "| " << setw(10) << left << LoginRegisterRecord.DClientBalance;
        cout << "| " << setw(10) << left << LoginRegisterRecord.UserName;

    }

public:

    static void ShowTransferRegisterScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pShowTransferlog))
        {
            return;// this will exit the function and it will not continue
        }


        vector <clsBankClient::stTrasnferLog> vLoginRegisterRecord = clsBankClient::LoadTransferDataFromFile();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(15) << "s.Account";
        cout << "| " << left << setw(15) << "D.account";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;
        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTrasnferLog Record : vLoginRegisterRecord)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

    }


};

