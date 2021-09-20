//AS06: Gustavo Lopes
#include<vector>
#include<stdint.h>
#include<array> 
#include<bits/stdc++.h>
#include<iostream>

#define EMPTY -1

//criando o tipo 'peso' e 'contador'
using weight  = int;
using counter = uint16_t;

/* Complexidade: O(v^2) -> pois o codigo irá fazer o algoritmo DFS
e depois uma versão modificada do DFS, que irá ordenar os vertices a serem visitados a
cada iteração, logo, o maior preço será para ordenar os vertices, que no caso mais
caro, irá custar O(v^2)
*/

// Classe de grafos
class Graph {

    private: 

        // Num de vertices e arestas
        counter vertices;
        counter edges;

        // Lista de adjacencia , com os pesos de cada relação
        std::vector<std::vector<std::pair<counter,weight>>> adj;

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
                auto v1 = std::make_pair(first,value);
                auto v2 = std::make_pair(last,value);

                // Adicionar vertices a lista de adjacencia
                add_adj(first, v2);
                add_adj(last, v1);

                result = true;
            }

            return result;
        }

        // Adicionar vertice na lista de adjacencia
        void add_adj(counter vertex, std::pair<counter,weight> value) {
            auto it = &this->adj.at(vertex); // Resgatar ponteiro para a lista na posicao 'first'

            // Inserir 'last' para a lista resgatada, como a variavel eh um 
             // ponteiro, o elemento sera atualizado na memoria
            it->push_back(value);            
        }

        // Adicionar nova vertice
        void add_vertex() {
            this->vertices++;

            std::vector<std::pair<counter,weight>> it;

            this->adj.push_back(it);
        }

        int num_components() {

            int num = 0; // variavel de resultado

            // Variavel para marcar vertices visitadas
            bool* visited = new bool[this->vertices];
            memset(visited, false,this->vertices*sizeof(bool)); // iniciando array com valor 'false'
        
            //Visitar todas as vertices
            for (int v = 0; v < this->vertices; v++) {
                if (visited[v] == false) {

                    // Fazer um 'depth first search', retornando vertices atravessados
                    dfs(v, visited);

                    // aumentar numero de componentes
                    num++;
                }
            }

            // deletar array da memoria
            delete[] visited;

            return num;
        }

        // Funcao de 'depth first search'
        void dfs(int v, bool* visited) {

            // Marcar vertice como visitado
            visited[v] = true;

            // Pegar vizinhos de 'v'
            auto curr_vertex_adj = this->adj.at(v); 

            // Atravesar os vizinhos de 'v'
            for (int i = 0 ; i < curr_vertex_adj.size(); i++) {

                // Se o vizinho de 'v' nao tiver sido visitado
                // visita-lo
                if (!visited[curr_vertex_adj.at(i).first]) {
                    dfs(curr_vertex_adj.at(i).first, visited);
                }
            }
        }

        weight time_necessary(int num_teleports) {

            int num_components = this->num_components();
            
            //Os teletransportes servem para contabilizar o usuário atravessar pelos componentes conexos,
            //se o numero de teletransportes for menor que o numero de componentes, pois não será possível
            //ir para todos os componentes
            if(++num_teleports < num_components) {
                return -1;
            }
            
            int total_weight = 0;

            // Variavel para marcar vertices visitadas
            bool* visited = new bool[this->vertices];
            memset(visited, false,this->vertices*sizeof(bool)); // iniciando array com valor 'false'
        
            //Visitar todas as vertices
            for (int v = 0; v < this->vertices; v++) {
                if (visited[v] == false) {

                    // Fazer um 'depth first search', retornando vertices atravessados
                    total_weight += dfs_weights(v, visited,-1);
                }
            }

            // deletar array da memoria
            delete[] visited;

            return total_weight;
        }

        // Funcao de 'depth first search'
        int dfs_weights(int v, bool* visited, int previous_weight) {

            // Marcar vertice como visitado
            visited[v] = true;

            int value = 0;
            int previous_value =  previous_weight;

            // Pegar vizinhos de 'v'
            auto curr_vertex_adj = this->adj.at(v); 

            // Fazer ordenação do vetor, caso ele tenha mais que 1 elemento
            if(curr_vertex_adj.size() > 1)
                sort(&curr_vertex_adj);

            // Atravesar os vizinhos de 'v'
            for (int i = 0 ; i < curr_vertex_adj.size(); i++) {
                
                // Se o vizinho de 'v' nao tiver sido visitado
                // visita-lo
                if (!visited[curr_vertex_adj.at(i).first]) {
                    value += curr_vertex_adj.at(i).second;
                    previous_value = curr_vertex_adj.at(i).second; //armazenar o valor do peso, caso o vertice precisa voltar
                    value += dfs_weights(curr_vertex_adj.at(i).first, visited, previous_value);
                }
            }

            if(!all_have_been_visited(visited)) {
                value += previous_value;
            }

            return value;
        }

        // Verificar se todas as posicoes do array de booleano
        // é igual a true
        bool all_have_been_visited(bool* visited) {
            bool response = true;
            for(int i =0 ; i < this->vertices; i++) {
                if(visited[i] == false) {
                    response = false;
                }
            }

            return response;
        }

        //Fazer sort dos vertices
        void sort(std::vector<std::pair<counter,weight>>* adjs) {
            int i, j, min_idx;
            
            // One by one move boundary of unsorted subarray
            for (i = 0; i < adjs->size() - 1; i++) {
                // Find the minimum element in unsorted array
                min_idx = i;
                for (j = i+1; j < adjs->size(); j++)
                if (adjs->at(j).second < adjs->at(min_idx).second)
                    min_idx = j;


                std::pair<counter,weight> tmp = adjs->at(i);
                adjs->at(i) = adjs->at(min_idx);
                adjs->at(min_idx) = tmp;
                
            }
        } 
};      

int main() {

    // Numero de casos testes
    int t;

    std::cin >> t;

    for(int i = 0 ; i < t; i++) {

        // Numero de vertices, arestas e numero maximo de teletransportes
        int n,m,k;

        // leitura dados e criando grafo
        std::cin >> n >> m >> k;
        Graph* g = new Graph(n);

        // Criando arestas dos grafos
        for(int j = 0 ; j < m; j++) {

            // vertice 1 e 2, e o peso da aresta
            int v1,v2,w;
            std::cin >> v1 >> v2 >> w;
            g->add_edge(--v1,--v2,w);
            
        }

        std::cout << g->time_necessary(k) << std::endl;
        // Deletar grafo da memoria
        delete g;

    }
}
