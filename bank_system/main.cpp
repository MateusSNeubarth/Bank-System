#include <iostream>

using namespace std;

class Cliente {
public:
    // Setters
    void setSaldo(double s) { saldo = s; }
    void setNome(string n) { nome = n; }
    void setNconta(int n) { nConta = n; }
    void setAgencia(int a) { agencia = a; }

    // Getters
    double getSaldo() { return saldo; }
    string getNome() { return nome; }
    int getNconta() { return nConta; }
    int getAgencia() { return agencia; }
private:
    double saldo;
    string nome;
    int nConta;
    int agencia;
};

void menuUser(Cliente cliente[], int usuarioAtivo) {
    char op;
    do
    {
        system("cls");
        cout << ">>>> MENU <<<<" << endl;
        cout << "1 - Saque" << endl;
        cout << "2 - Deposito" << endl;
        cout << "3 - Saldo" << endl;
        cout << "4 - Sair" << endl;
        cout << "Insira sua opcao" << endl;
        cin >> op;
        double entry;
        int temp;
        switch (op)
        {
        case '1': cout << "SAQUE" << endl;
            cout << "Insira quanto deseja sacar" << endl;
            cin >> entry;
            if (entry < cliente[usuarioAtivo - 1].getSaldo() + 1) {
                temp = cliente[usuarioAtivo - 1].getSaldo() - entry;
                cliente[usuarioAtivo - 1].setSaldo(temp);
                cout << "Novo saldo: " << temp << endl;
            }
            else
                cout << "Saldo insuficiente" << endl;
            system("pause");
            break;

        case '2': cout << "DEPOSITO" << endl;
            cout << "Insira quanto deseja depositar" << endl;
            cin >> entry;
            if (entry < 0) {
                cout << "Entrada invalida!" << endl;
            }
            else {
                temp = cliente[usuarioAtivo - 1].getSaldo() + entry;
                cliente[usuarioAtivo - 1].setSaldo(temp);
                cout << "Novo saldo: " << temp << endl;
            }
            system("pause");
            break;

        case '3': cout << "SALDO" << endl;
            cout << "Seu saldo atual: " << cliente[usuarioAtivo - 1].getSaldo() << endl;
            system("pause");
            break;

        case '4': cout << "Nosso banco agradece nossa visita" << endl;
            system("pause");
            break;

        default: cout << "Opcao Invalida! Tente Novamente" << endl;
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
    Cliente cliente[2];
    int usuarioAtivo;

    cliente[0].setNome("Mateus");
    cliente[0].setNconta(1);
    cliente[0].setAgencia(1);
    cliente[0].setSaldo(0.0);

    cliente[1].setNome("Julia");
    cliente[1].setNconta(2);
    cliente[1].setAgencia(1);
    cliente[1].setSaldo(0.0);

    cout << "Informe o numero da conta: ";
    cin >> usuarioAtivo;
    string nome = cliente[usuarioAtivo - 1].getNome();
    cout << "Ola, " << nome << endl;
    system("pause");

    menuUser(cliente, usuarioAtivo);

    return 0;
}