#include <iostream>

using namespace std;

class Client {
public:
    // Setters
    void setBlance(double s) { balance = s; }
    void setName(string n) { name = n; }
    void setNAccount(int n) { nAccount = n; }
    void setAgency(int a) { agency = a; }

    // Getters
    double getBalance() { return balance; }
    string getName() { return name; }
    int getNAccount() { return nAccount; }
    int getAgency() { return agency; }
private:
    double balance;
    string name;
    int nAccount;
    int agency;
};

void menuUser(Client client[], int activeUser) {
    char op;
    do
    {
        system("cls");
        cout << ">>>> MENU <<<<" << endl;
        cout << "1 - Withdraw" << endl;
        cout << "2 - Deposit" << endl;
        cout << "3 - Balance" << endl;
        cout << "4 - Exit" << endl;
        cout << "Insert your option" << endl;
        cin >> op;
        double entry;
        int temp;
        switch (op)
        {
        case '1': cout << "WITHDRAW" << endl;
            cout << "Insert the amount for withdraw" << endl;
            cin >> entry;
            if (entry < client[activeUser - 1].getBalance() + 1) {
                temp = client[activeUser - 1].getBalance() - entry;
                client[activeUser - 1].setBlance(temp);
                cout << "New balance: " << temp << endl;
            }
            else
                cout << "Not enough balance" << endl;
            system("pause");
            break;

        case '2': cout << "DEPOSIT" << endl;
            cout << "Insert the amount for deposit" << endl;
            cin >> entry;
            if (entry < 0) {
                cout << "Invalid entry" << endl;
            }
            else {
                temp = client[activeUser - 1].getBalance() + entry;
                client[activeUser - 1].setBlance(temp);
                cout << "New balance: " << temp << endl;
            }
            system("pause");
            break;

        case '3': cout << "BALANCE" << endl;
            cout << "Your current balance: " << client[activeUser - 1].getBalance() << endl;
            system("pause");
            break;

        case '4': cout << "Out bank appreciate your visit!" << endl;
            system("pause");
            break;

        default: cout << "Invalid option! Try again" << endl;
            system("pause");
            break;
        }
    } while (op != '4');
}

void menuWelcome() {
    // to do
}

int main()
{
    Client client[2];
    int activeUser;

    client[0].setName("Mateus");
    client[0].setNAccount(1);
    client[0].setAgency(1);
    client[0].setBlance(0.0);

    client[1].setName("Julia");
    client[1].setNAccount(2);
    client[1].setAgency(1);
    client[1].setBlance(0.0);

    cout << "Inform your account number: ";
    cin >> activeUser;
    string nome = client[activeUser - 1].getName();
    cout << "Hello, " << nome << endl;
    system("pause");

    menuUser(client, activeUser);

    return 0;
}