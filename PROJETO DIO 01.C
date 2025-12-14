 #include <stdio.h>

// ===============================
// FUNÇÃO TRANSVERSAL (ASPECTO)
// ===============================
void verificarSaldo(double saldo, double valor) {
    if (saldo < valor) {
        printf("[ERRO] Saldo insuficiente! Saldo: R$ %.2f | Valor solicitado: R$ %.2f\n",
               saldo, valor);
    }
}

// ===============================
// "CLASSE" BASE (SIMULAÇÃO POO)
// ===============================
struct Conta {
    double saldo;
};

// Função de saque (aspecto aplicado)
void sacar(struct Conta *conta, double valor) {

    verificarSaldo(conta->saldo, valor);

    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("Saque realizado: R$ %.2f\n", valor);
    }
}

// ===============================
// PROGRAMA PRINCIPAL
// ===============================
int main() {

    struct Conta corrente = {500};
    struct Conta poupanca = {200};

    sacar(&corrente, 300);   // OK
    sacar(&poupanca, 500);   // ERRO

    return 0;
}
