//AS01
//Autor: Gustavo Lopes Rodrigues
#include<iostream>
#include<string>
#include<stdint.h>

//Definindo intervalo númerico que o 
//usuário pode usar
#define MIN 0  
#define MAX 20

//fat_size = fatorial size
using fat_size=uint64_t;

int isInInterval(int number);
int stringToInt(std::string input, int firstIndex, int lastIndex );
fat_size fatorial(int n);

int main() {

    std::string input;
  
    //Fazer a leitura da entrada do teclado, enquanto o mesmo
    //não for vazia
    while (std::getline(std::cin, input) && !input.empty()) {

        //Resgatar numeros da entrada do usuario
        int m = stringToInt(input,0,input.find(" "));
        int n = stringToInt(input,input.find(" "),input.length() -1);

        if(isInInterval(m) && isInInterval(n))
            std::cout<< fatorial(m) + fatorial(n) << std::endl;
    }

}

// Converter um intervalo de uma std::string para um numero inteiro(int)
int stringToInt(std::string input, int firstIndex, int lastIndex ) {
    return std::stoi(input.substr(firstIndex,lastIndex));
}

// Verificar se numero esta dentro do intervalo
int isInInterval(int number) {
    return (number >= MIN && number <= MAX);
}

// Retornar o resultado do fatorial do número 'n'
fat_size fatorial(int n) {
    if(n == 0)
        return 1;
    
    return n * fatorial(n-1); 
}