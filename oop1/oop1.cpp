
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"



clsBankClient readclientinfo(clsBankClient& client) {

    cout << "\ninter first name: ";
    client.FirstName = clsInputValidate::ReadString();
    cout << "\ninter last name: ";
    client.LastName = clsInputValidate::ReadString();
    cout << "\ninter Email: ";
    client.Email = clsInputValidate::ReadString();
    cout << "\ninter Phone number: ";
    client.Phone = clsInputValidate::ReadString();
    cout << "\ninter Pinconde number: ";
    client.PinCode= clsInputValidate::ReadString();
    cout << "\ninter Accoun tBalance : ";
    client.AccountBalance = stoi(clsInputValidate::ReadString());
    return client;
}

void addnewclient() {
    string accnum="";
    cout << "inter account number: ";
    cin >> accnum;
    while (clsBankClient::IsClientExist(accnum)) {

        cout << " account number exist, inter another number : ";
        cin >> accnum;


    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(accnum);
    
    readclientinfo(NewClient);
    clsBankClient::enSaveResults result;
    result=  NewClient.Save();

    switch (result) {

    case clsBankClient::enSaveResults::svSucceeded:
        cout << "saved :-)";
    }


}


    

void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.AccountBalance;

}


void ShowTotalBalances()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}





int main()

{
    clsMainScreen::ShowMainMenue();
    system("pause>0");
    return 0;
}