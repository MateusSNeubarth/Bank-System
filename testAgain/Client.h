#include <iostream>

using namespace std;

class Client {
public:
    // Setters
    void setBalance(double s);
    void setName(string n);
    void setNAccount(int n);
    void setAgency(string a);
    void setPass(string p);

    // Getters
    double getBalance();
    string getName();
    int getNAccount();
    string getAgency();
    string getPass();
private:
    double balance;
    string name;
    int nAccount;
    string agency;
    string pass;
};
