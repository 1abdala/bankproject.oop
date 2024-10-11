#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



class clsUpdateClientScreen : protected clsScreen


{
    static clsBankClient readclientinfo(clsBankClient& client) {

        cout << "\ninter first name: ";
        client.FirstName = clsInputValidate::ReadString();
        cout << "\ninter last name: ";
        client.LastName = clsInputValidate::ReadString();
        cout << "\ninter Email: ";
        client.Email = clsInputValidate::ReadString();
        cout << "\ninter Phone number: ";
        client.Phone = clsInputValidate::ReadString();
        cout << "\ninter Pinconde number: ";
        client.PinCode = clsInputValidate::ReadString();
        cout << "\ninter Account Balance : ";
        client.AccountBalance = stoi(clsInputValidate::ReadString());
        return client;
    }
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

    
public: 
    static void ShowUpdateClientScreen() {
        string accnumber = "";
        _DrawScreenHeader("update client screen ");
        cout << "inter client account ";
        cin >> accnumber;
        while (!clsBankClient::IsClientExist(accnumber)) {
            cout << "account number not found please inter another number : ";
            cin >> accnumber;


        }
        clsBankClient c1 = clsBankClient::Find(accnumber);
        _PrintClient(c1);
        cout << "update client info:";
        cout << "are you sure you want to delete this client ? y/n ";
        char answer = 'n';
        cin >> answer;
        if (tolower(answer) == tolower('y')); {
            cout << "\n   update client info:";
            cout << "\n_________________________\n";
            readclientinfo(c1);
            clsBankClient::enSaveResults saveresult;
            saveresult = c1.Save();

            switch (saveresult) {

            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "save has been done -_- ";
                _PrintClient(c1);
                break;

            }

            case clsBankClient::enSaveResults::svFaildEmptyObject:
                cout << "save faild";
                break;
            }


        }
    }


};

