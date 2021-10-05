//AS08: Gustavo Lopes Rodrigues
#include <iostream>
#include <vector>
#include <string>

/*
Complexidade: O(n*log(n)) O jogo de bolhas de baldes consiste em realizar um algoritmo de 
Divisão e conquista. Para a resolução do problema, foi utilizado o algoritmo de mergesort,
logo, o preço do algoritmo é o preço do mergesort
*/

typedef std::vector<int> numeros;
typedef std::vector<std::string> jogadores;

//Classe para gerenciamento do jogo de Bolhas e Baldes
class BolhasBaldes {

    private:
        
        // Fazer a juncao da esquerda e da direita
        std::vector<int> merge(numeros esq, numeros dir) {
            
            int i = 0;
            int j = 0;

            numeros juncao;

            while (i < esq.size() && j < dir.size()) {

                if (esq[i] < dir[j]) {
                    juncao.push_back(esq[i++]);

                } else { // esq[i] > dir[j] 
                    juncao.push_back(dir[j++]);
                    num_jogadas += esq.size() - i; // adicionar numeros de jogadas feitas a variavel
                }
            }

            // Adicionar numeros restantes na juncao,
            // o i e o j nao sejam tamanho dos vetores que estao associados

            while (i  < esq.size() ) 
                juncao.push_back(esq[i++]);

            while (j < dir.size()) 
                juncao.push_back(dir[j++]);

            return juncao;
        }

        // Iniciando o algoritmo de mergesort
        std::vector<int> mergeSort(numeros& a) {

            if (a.size() <= 1)
                return a;

            int metade = a.size() / 2;

            // Fazer divisao do vetor
            std::vector<int> esq (a.begin(),a.begin() + metade);
            std::vector<int> dir(a.begin() + metade, a.end());

            // Fazer a juncao dos segmentos da esquerda e direita
            return merge(mergeSort(esq), mergeSort(dir));
        }

    public: 

        // Numero de jogadas realizadas
        int num_jogadas;

        // Jogar o jogo de Bolhas e baldes, usando o vetor
        // de numeros como base
        void jogar(std::vector<int> numeros) {
            num_jogadas = 0;
            this->mergeSort(numeros);
        }

        // Funcao para calcular o vencedor do jogo
        std::string vencedor(jogadores j) {

            // O vencedor do jogo, é o jogador que ira jogar o proximo
            // turno, depois do ultima jogada
            int indice_vencedor = num_jogadas % j.size();

            return j[indice_vencedor];
        }

};

int main() {

    int tam;
    BolhasBaldes bolhasEbaldes;
    jogadores participantes = {"Carlos", "Marcelo"};

    std::cin >> tam;

    //Leitura das jogadas
    while (tam != 0)
    {

        numeros nums;

        // Leitura dos numeros do jogo
        for (int i = 0; i < tam; i++)
        {
            int tmp;
            std::cin >> tmp;
            nums.push_back(tmp);
        }

        //Jogar o jogo do bolhas e baldes e imprimir o vencedor
        bolhasEbaldes.jogar(nums);
        std::cout << bolhasEbaldes.vencedor(participantes) << std::endl;

        std::cin >> tam;
    }
}