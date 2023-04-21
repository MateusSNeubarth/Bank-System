#include <iostream>

using namespace std;

class Client {
public:
    // Setters
    void setBalance(double s) { balance = s; }
    void setName(string n) { name = n; }
    void setNAccount(int n) { nAccount = n; }
    void setAgency(string a) { agency = a; }
    void setPass(string p) { pass = p; }

    // Getters
    double getBalance() { return balance; }
    string getName() { return name; }
    int getNAccount() { return nAccount; }
    string getAgency() { return agency; }
    string getPass() { return pass; }
private:
    double balance;
    string name;
    int nAccount;
    string agency;
    string pass;
};
