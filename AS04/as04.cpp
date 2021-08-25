//AS04: Gustavo Lopes
#include <vector>
#include <stdint.h>
#include <array> 
#include<bits/stdc++.h>

#define EMPTY -1

//criando o tipo 'peso' e 'contador'
using weight  = int;
using counter = uint16_t;

/* Complexidade: O(E * log(E) + E* log(V)) E -> Arestas(edges), V-> Vertices
* Como o algoritmo usa um Kruskal para encontrar o custo dos
* cabos, o custo da operação será o custo do Kruskal. Na minha implementacao
* ele irá levar O(E* log(e)) para fazer o sort da estrutura
* de arestas e seus pesos, e E*log(v) para criar o disjoint-set
* contendo a minimum spanning tree
*/

//Struct do DisjoinSets
typedef struct DisjoinSets {

    private: 
        
        //Vetor de nós e seus parentes
        std::vector<std::pair<int,int>> nodes;

    public: 

        //Iniciar o DisjointSets
        DisjoinSets(int n) {
            
            
            for(int i = 0; i < n ; i++) 
                this->nodes.push_back({0,i});
        
        }

        //Achar o pai do no index
        int find(int index) {

            if(index != this->nodes.at(index).second)

                this->nodes.at(index).second = find(this->nodes.at(index).second);
            
            return this->nodes.at(index).second;
        }

        //Fazer uma combinacao do no 'x' com o no 'y'
        void merge(int x,int y) {

            x = find(x);
            y = find(y);

            if(this->nodes.at(x).first > this->nodes.at(y).first)
                this->nodes.at(y).second = x;
            else 
                this->nodes.at(x).second = y;

            if(this->nodes.at(x).first == this->nodes.at(y).first)
                this->nodes.at(y).first++;
                
        }

}DisjoinSets;

// Classe de grafos
class Graph {

    private: 

        // Num de vertices e arestas
        counter vertices;
        counter edges;

        // Armazenar arestas e seus respectivos pesos
        std::vector<std::pair<weight,std::pair<counter,counter>>> edges_weights;

    public:

        // Iniciar grafo com 'v' numero de vertices
        Graph(counter v) {

            weight default_value = EMPTY;
            
            this->edges    = 0;
            this->vertices = 0;

            for(int i =0 ; i < v; i++) 
                add_vertex();
        }

        counter vertices_num() {
            return this->vertices;
        }

        counter edges_num() {
            return this->edges;
        }

        /** Adicionar aresta ao grafo
         */ 
        bool add_edge(counter first, counter last, weight value = 0) {
            bool result = false;

            //Se algum dos vertices nao existir no grafo
            if(first < this->vertices_num() && last < this->vertices_num()) {
                this->edges++;

                // Fazer par de vertices e peso e adicionar ao grafo
                auto edges_pair        = std::make_pair(first,last);
                auto weight_edges_pair = std::make_pair(value,edges_pair);
                this->edges_weights.push_back(weight_edges_pair);

                result = true;
            }

            return result;
        }

        // Adicionar nova vertice
        counter add_vertex() {
            counter result = -1;
            counter pos    = this->vertices;

            result = this->vertices;
            this->vertices++;

            std::vector<counter> it;

            return result;
        }

        // Algoritmo de kruskal, modificado para 
        // calcular o peso da MST
        counter kruskal() {

            // Fazer ordenação das arestas 
            std::sort(edges_weights.begin(), edges_weights.end());

            counter total_weight = 0;

            // Comecar o DisjointSet com o número de vertices 
            // de grafos
            DisjoinSets ds(this->vertices);
        
            for (auto it=edges_weights.begin(); it!=edges_weights.end(); it++) {

                // Armazenar os vertices da aresta atual
                int source      = it->second.first;
                int destination = it->second.second;
        
                // Resgatar o pai das vertices
                int parent_source      = ds.find(source);
                int parent_destination = ds.find(destination);

                // Se os pais das vertices nao sao os mesmos, significa
                // que junta-los nao formara um ciclo, logo, podemos
                // fazer o merge
                if (parent_source != parent_destination) {
                    ds.merge(parent_source, parent_destination);
                    total_weight += it->first;
                }

            }

            return total_weight;
        }
};      


int main() {

    uint16_t num_roteadores;
    uint16_t quant_cabos; 

    // Ler o numero de roteadores(num de vertices)
    // e ler o numero de cabos(numero de arestas)
    std::cin >> num_roteadores >> quant_cabos;

    // Criar grafo
    Graph* g = new Graph(num_roteadores);

    // Fazer a leitura das arestas
    for(int i = 0; i < quant_cabos; i++) {
        
        uint16_t comeco;
        uint16_t fim;
        uint16_t peso;

        // Ler vertice inicial, final e o peso da aresta
        std::cin >> comeco >> fim >> peso;

        // Adicionar aresta, diminuindo em 1 a vertice, 
        // para considerar que o indice do vetor comeco eh igual a 0
        g->add_edge(--comeco,--fim,peso);
    }
    
    std::cout << g->kruskal() << std::endl;

    return 0;
}
