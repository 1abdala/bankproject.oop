#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen :protected clsScreen
{





    static void _ReadClientInfo(clsBankClient& client) {

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
        cout << "\ninter Accoun tBalance : ";
        client.AccountBalance = stoi(clsInputValidate::ReadString());
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


    static void AddNewClientScreen() {


        if (!CheckAccessRights(clsUser::enPermission::pAddNewClient)) {
            
            return;

        }

        string accnum = "";
        _DrawScreenHeader("Add New Client Screen");
        cout << "inter account number: ";
        accnum = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(accnum)) {

            cout << " account number exist, inter another number : ";
            accnum = clsInputValidate::ReadString();


        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(accnum);

        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResults result;
        result = NewClient.Save();

        switch (result) {

        case clsBankClient::enSaveResults::svSucceeded:
        {
            _PrintClient(NewClient);
            cout << "saved :-)";
            break;
        }


        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {

            cout << "\nError account was not saved because it's already exists";
            break;



        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {

            cout << "\nError account was not saved because it's empty ";
            break;



        }

        }
    }


};
