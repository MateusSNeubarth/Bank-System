#include "Client.h"

// Setters
void Client::setBalance(double s) { balance = s; }
void Client::setName(string n) { name = n; }
void Client::setNAccount(int n) { nAccount = n; }
void Client::setAgency(string a) { agency = a; }
void Client::setPass(string p) { pass = p; }

// Getters
double Client::getBalance() { return balance; }
string Client::getName() { return name; }
int Client::getNAccount() { return nAccount; }
string Client::getAgency() { return agency; }
string Client::getPass() { return pass; }