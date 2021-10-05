//AS08: Gustavo Lopes Rodrigues
#include <iostream>
#include <vector>

/*
Complexidade: O(n*log(n)) O jogo de bolhas de baldes consiste em realizar um algoritmo de 
Divisão e conquista. Para a resolução do problema, foi utilizado o algoritmo de mergesort,
logo, o preço do algoritmo é o preço do mergesort
*/

//Classe para gerenciamento do jogo
class BolhasBaldes {

    private:
        
        // Fazer a juncao da esquerda e da direita
        std::vector<int> merge(std::vector<int> esq, std::vector<int> dir) {
            
            int i = 0;
            int j = 0;

            std::vector<int> juncao;

            while (i < esq.size() && j < dir.size()) {

                if (esq[i] < dir[j]) {
                    juncao.push_back(esq[i++]);

                } else { // troca dos números, logo ,+ numero de jogadas
                    juncao.push_back(dir[j++]);
                    num_jogadas += esq.size() - i;
                }
            }

            while (i  < esq.size() ) 
                juncao.push_back(esq [i++ ]);

            while (j < dir.size()) 
                juncao.push_back(dir[j++]);

            return juncao;
        }

        // Iniciando o algoritmo de mergesort
        std::vector<int> mergeSort(std::vector<int>& arr) {

            if (arr.size() <= 1)
                return arr;

            int tam = arr.size() / 2;

            // Fazer divisao do vetor
            std::vector<int> esq (arr.begin(),arr.begin() + tam);
            std::vector<int> dir(arr.begin() + tam, arr.end());

            // Fazer a juncao dos segmentos da esquerda e direita
            return merge(mergeSort(esq), mergeSort(dir));
        }

    public: 

        // Numero de jogadas realizadas
        int num_jogadas;

        // Guardando os numeros aleatorios
        std::vector<int> numeros;

        BolhasBaldes(std::vector<int> array) {
            this->numeros     = array;
            this->num_jogadas = 0;
        }

        // Funcao para ser chamada, ao jogar o jogo
        void jogar() {
            num_jogadas = 0;
            this->mergeSort(this->numeros);
        }

};

int main() {

    int n;

    std::cin >> n;

    while (n != 0)
    {

        std::vector<int> numeros;

        for (int i = 0; i < n; i++)
        {
            int tmp;
            std::cin >> tmp;
            numeros.push_back(tmp);
        }

        BolhasBaldes jogo(numeros);
        jogo.jogar();

        std::cout << ((jogo.num_jogadas % 2 == 0) ? "Carlos" : "Marcelo") << std::endl;

        std::cin >> n;
    }
}