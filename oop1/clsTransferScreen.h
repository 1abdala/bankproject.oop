#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsTransferScreen:clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber to transfer for:  ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   transfer Screen");

        string FromAccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(FromAccountNumber))
        {
            cout << "\nClient with [" << FromAccountNumber << "] does not exist.\n";
            FromAccountNumber = _ReadAccountNumber();
        }

        clsBankClient SourceClient = clsBankClient::Find(FromAccountNumber);
        _PrintClient(SourceClient);

        double Amount = 0;
        cout << "\nPlease enter AccountNumber to transfer to: ";
        string ToAccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(ToAccountNumber))
        {
            cout << "\nClient with [" << ToAccountNumber << "] does not exist.";
            cout << "Please inter another account";
            ToAccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient DestinationClient = clsBankClient::Find(ToAccountNumber);
        _PrintClient(DestinationClient);
        cout << "\nPlease inter amount to transfer to: ";
        Amount = clsInputValidate::ReadDplNumber();
        while (Amount > SourceClient.AccountBalance) {
            cout << "\namount exceeded avilable balance, Please inter another amount: ";
            Amount = clsInputValidate::ReadDplNumber();

        }

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient)) {
                cout << "\nAmount trasferd Successfully.\n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
              
            }

            else cout << "Faild to trasfer";
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

