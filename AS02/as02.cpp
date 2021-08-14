//AS02: Gustavo Lopes Rodrigues 
#include<iostream>
#include<cstdint>
/* Complexidade do programa: considerando a funcao numberOfLedsRequired,
*  podemos fazer o cálculo da complexidade da seguinte forma:
*  declaracao de variavel = +1
*  laco 'for' -> (input.length() as n) - 0 = + n
*  	dentro do for
*       switch case(pior caso = n -> numero de cases)= 
*             O(n) ou O(1) = +1
*             dentro do switch case
*             operacao de soma + break = +2
*  
*  return = +1
*
*  Resultado = 1 + (n + 1 + 2) = n + 4 = O(n)
*/

int numberOfLedsRequired(std::string input);

int main() {

    uint16_t n;           // numero de casos testes
    std::string ledInput; // input do painel led a ser calculada

    std::cin >> n;
    
    for(uint16_t i = 0; i < n; i++) {

	//Ler painel de leds e imprimir numero de leds necessarios
	//para fazer tal painel
        std::cin >> ledInput;
        std::cout << numberOfLedsRequired(ledInput) << " leds" << std::endl;
    }

    return 0;
}

//Calcular numero de leds necessario para 
//fazer um painel de leds da string usada
//como argumento
int numberOfLedsRequired(std::string input) {

    int leds = 0;

    //iterar por cada caracter da string
    for(uint16_t i = 0; i < input.length(); i++) 
    
        //Somar o numero de leds necessario dependendo
        //de qual caracter for lido
        switch(input.at(i)) {
            case '1':
                leds += 2;
                break;
            case '2':
                leds += 5;
                break;
            case '3':
                leds += 5;
                break;
            case '4':
                leds += 4;
                break;
            case '5':
                leds += 5;
                break; 
            case '6':
                leds += 6;
                break; 
            case '7':
                leds += 3;
                break; 
            case '8':
                leds += 7;
                break; 
            case '9':
                leds += 6;
                break;
            case '0':
                leds += 6;
                break;
            default:
                break; 
        }

    return leds;
}
