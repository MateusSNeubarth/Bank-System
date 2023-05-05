#include "App.h"


void App::start() {
	cout << "System initialized" << endl;
	system("pause");
}

bool passCheck(string pass) {
    string spChar = "!@#$%&*";
    string nums = "1234567890";

    bool hasSpChar = false;
    bool hasUpper = false;
    bool hasNum = false;
    bool withinRange = false;

    for (int i = 0; i < pass.size(); i++) {
        //check for special character
        for (int j = 0; j < spChar.size(); j++) {
            if (pass[i] == spChar[j])
                hasSpChar = true;
        }

        //check for upper case letter
        if (isupper(pass[i])) {
            hasUpper = true;
        }

        //check for number
        for (int n = 0; n < nums.size(); n++) {
            if (pass[i] == nums[n])
                hasNum = true;
        }

    }
    //check size of password is within range
    if (pass.size() >= 8 && pass.size() <= 16)
        withinRange = true;

    if (!hasSpChar || !hasUpper || !hasNum || !withinRange) {
        cout << "Your password does not compete to the requisites" << endl;
        return false;
    }
    else
        return true;
}

void menuUser(Client client) {
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
            if (entry < client.getBalance() + 1) {
                temp = client.getBalance() - entry;
                client.setBalance(temp);
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
                temp = client.getBalance() + entry;
                client.setBalance(temp);
                cout << "New balance: " << temp << endl;
            }
            system("pause");
            break;

        case '3': cout << "BALANCE" << endl;
            cout << "Your current balance: " << client.getBalance() << endl;
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

void App::run() {
    auto v = vector<Client>();
    int called = 0;
    char op;
    do {
        Client c;
        cout << "Welcome to our bank" << endl;
        cout << "1 - Log in" << endl;
        cout << "2 - Sign in" << endl;
        cout << "3 - Exit" << endl;
        cin >> op;

        switch (op) {
        case '1': {
            bool found = false;
            string name;
            string pass;
            cout << "Name: ";
            cin >> name;
            cout << "Password: ";
            cin >> pass;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].getName() == name) {
                    if (v[i].getPass() == pass)
                        found = true;
                    menuUser(v[i]);
                    break;
                }
            }
            if (!found)
                cout << "User doesn't exist" << endl;
            break;
        }
        case '2': {
            called++;
            string name;
            string pass;
            string agency;
            cout << "Name: ";
            cin >> name;
            c.setName(name);
            cout << "Agency: ";
            cin >> agency;
            c.setAgency(agency);
            do {
                cout << "Password: ";
                cin >> pass;
                if (passCheck(pass))
                    c.setPass(pass);
            } while (!passCheck(pass));
            c.setNAccount(called);
            c.setBalance(0.0);
            v.push_back(c);
            break;
        }
        case '3': {
            cout << "Thanks for using our bank" << endl;
            break;
        }
        default:
            cout << "Invalid entry! Try again" << endl;
            break;
        }

    } while (op != '3');

}

void App::finish() {
	cout << "System Finalized" << endl;
	system("pause");
}