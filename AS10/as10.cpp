#include<iostream> 

// Calcular quantas notas(ou moedas) existem, dado 
// uma quantia total e um certo valor
int numNotasOuMoedas(double* total,double valor);

int main() {

    //Leitura do dinheiro
    double dinheiro;
    std::cin >> dinheiro;

    //Imprimindo quantidade de notas
    std::cout << "NOTAS:" << std::endl;
    std::cout << numNotasOuMoedas(&dinheiro,100) << " nota(s) de R$ 100.00" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,50) << " nota(s) de R$ 50.00" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,20) << " nota(s) de R$ 20.00" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,10) << " nota(s) de R$ 10.00" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,5) << " nota(s) de R$ 5.00" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,2) << " nota(s) de R$ 2.00" << std::endl; 

    // Imprimindo quantidade de moedas
    std::cout << "MOEDAS:" << std::endl;
    std::cout << numNotasOuMoedas(&dinheiro,1) << " moeda(s) de R$ 1.00" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,0.5) << " moeda(s) de R$ 0.50" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,0.25) << " moeda(s) de R$ 0.25" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,0.10) << " moeda(s) de R$ 0.10" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,0.05) << " moeda(s) de R$ 0.05" << std::endl; 
    std::cout << numNotasOuMoedas(&dinheiro,0.01) << " moeda(s) de R$ 0.01" << std::endl; 
}

int numNotasOuMoedas(double* total, double valor) {

    double resultado;

    // Calculando a quantidade de notas(ou moedas) e entao 
    // subtraindo esse valor do total, para o calculo de futuras
    // operacoes
    resultado = *total / valor;
    *total -= (int)resultado * valor;

    return resultado;
}
