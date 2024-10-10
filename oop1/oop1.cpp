
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"


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

void updateclient() {
    string accnumber = "";
    cout << "inter client number ";
    cin >> accnumber;
    while (!clsBankClient::IsClientExist(accnumber)) {
        cout << "account number not found please inrer another number : ";
        cin >> accnumber;


    }
    clsBankClient c1 = clsBankClient::Find(accnumber);
    c1.Print();
    cout << "update client info:";
    cout << "\n_____________________________________________\n";
     readclientinfo(c1);
     c1.Save();
     clsBankClient::enSaveResults saveresult;
     saveresult= c1.Save();

     switch (saveresult) {

     case clsBankClient::enSaveResults::svSucceeded:
     {
         cout << "save has been done ";


     }

     case clsBankClient::enSaveResults::svFaildEmptyObject:
         cout << "save faild";

     }



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

void DeleteClient() {
    string accnumber = "";
    char sure;
    cout << "inter client number ";
    cin >> accnumber;
    while (!clsBankClient::IsClientExist(accnumber)) {
        cout << "account number not found please inrer another number : ";
        cin >> accnumber;


    }
    clsBankClient c1 = clsBankClient::Find(accnumber);
    c1.Print();
    cout << "are you sure to delete this clident ? y/n";
    cin >> sure;
    if (tolower(sure) == tolower('y')) {
        if (c1.Delete()) {

            cout << "delete it ";
            c1.Print();
       }

    }


}
void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowClientsList()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

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
    ShowClientsList();

    system("pause>0");
    return 0;
}