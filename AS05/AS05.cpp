//AS05: Gustavo Lopes
#include<vector>
#include<stdint.h>
#include<array> 
#include<bits/stdc++.h>
#include<iostream>

#define EMPTY -1

//criando o tipo 'contador'
using counter = uint16_t;

/* Complexidade: O(V^2), pois é o custo para o algoritmo DFS, mais
* o custo para fazer a insercao dos pares de vertices dentro do dfs. Todo esse processo
* dentro do DFS irá deixá-lo mais custoso do que o normal.
*/

// Classe de grafos
class Graph {

    private: 

        // Num de vertices e arestas
        counter vertices;
        counter edges;

        // Lista de adjacencia 
        std::vector<std::vector<counter>> adj;

    public:

        // Iniciar grafo com 'v' numero de vertices
        Graph(counter v) {    
            this->edges    = 0;
            this->vertices = 0;

            for(int i =0 ; i < v; i++) 
                add_vertex();
        }

        // Retornar numero de vertices
        counter vertices_num() {
            return this->vertices;
        }

        // Adicionar vertice na lista de adjacencia
        void add_adj(counter first, counter last) {
            auto it = &this->adj.at(first); // Resgatar ponteiro para a lista na posicao 'first'

            // Inserir 'last' para a lista resgatada, como a variavel eh um 
             // ponteiro, o elemento sera atualizado na memoria
            it->push_back(last);            
        }

        // Adicionar aresta ao grafo
        bool add_edge(counter first, counter last) {
            bool result = false; // variavel de resultado da operacao

            //Se algum dos vertices nao existir no grafo
            if(first < this->vertices_num() && last < this->vertices_num()) {
                
                // Adicionar ao contador 
                this->edges++;
                
                // Adicionar vertices a lista de adjacencia
                add_adj(first, last);
                add_adj(last, first);

                result = true;
            }

            return result;
        }

        // Adicionar nova vertice
        void add_vertex() {

            this->vertices++;

            //Adicionar nova lista de adjacencia
            std::vector<counter> it;
            this->adj.push_back(it);
        }

        // Funcoes para contar numero de componentes
        int num_components() {

            int num = 0; // variavel de resultado

            // Variavel para marcar vertices visitadas
            bool* visited = new bool[this->vertices];
            memset(visited, false,this->vertices*sizeof(bool)); // iniciando array com valor 'false'
        
            //Visitar todas as vertices
            for (int v = 0; v < this->vertices; v++) {
                if (visited[v] == false) {

                    // Fazer um 'depth first search', retornando vertices atravessados
                    auto vertexes = traverse_component(v, visited);

                    // Ordenar vertices e imprimir na tela
                    std::sort(vertexes.begin(), vertexes.end());
                    for(int j = 0; j < vertexes.size(); j++) 
                        std::cout << vertexes.at(j) << ",";
                    
                    // aumentar numero de componentes
                    num++;
                    std::cout << "\n"; // dar espacamento
                }
            }

            // deletar array da memoria
            delete[] visited;

            return num;
        }

        // Funcao de 'depth first search', adaptada para retornar as vertices
        // visitadas
        std::vector<char> traverse_component(int curr_v, bool* visited) {

            // Marcar vertice como visitado
            visited[curr_v] = true;

            // Criar array de char, iniciando com a vertice
            // que esta sendo visitada
            std::vector<char> resp = { intToChar(curr_v) };

            // Pegar vizinhos de 'v'
            auto curr_vertex_adj = this->adj.at(curr_v); 

            // Atravesar os vizinhos de 'v'
            for (int i = 0 ; i < curr_vertex_adj.size(); i++)

                // Se o vizinho de 'v' nao tiver sido visitado
                // visita-lo
                if (!visited[curr_vertex_adj.at(i)]) {

                    // Pegar vizinhos visitados e armazena-los no resultaod
                    auto tmp = traverse_component(curr_vertex_adj.at(i), visited);
                    for(int j = 0; j < tmp.size(); j++) {
                        char aux = tmp.at(j);
                        resp.push_back(aux);
                    }
                }

            return resp;
        }

        // Converter inteiro para caracetere
        char intToChar(int i) {
            return (char)(i + 97); // 97 = 'a' 
        }
};      

// Funcao utilitaria para conversao de 'char' para 'inteiro'
int charToInt(char c);

int main() {

    // Numero de casos testes
    int n;

    std::cin >> n;

    for(int i = 0 ; i < n; i++) {

        // Numero de vertices e arestas
        int v,e;

        // Criando grafo
        std::cin >> v >> e;
        Graph* g = new Graph(v);

        for(int j = 0 ; j < e; j++) {

            // Fazer leitura da aresta 'j' do grafo
            char v1,v2;
            std::cin >> v1 >> v2;

            // Adicionar vertice ao grafo
            // convertendo o char para um numero inteiro
            g->add_edge(charToInt(v1),charToInt(v2));
            
        }

        // Imprimindo o caso atual
        std::cout << "Case #" << i + 1 << ":" << std::endl;

        int num = g->num_components();

        std::cout << num << " connected components\n" << std::endl;

        // Deletar grafo da memoria
        delete g;

    }
}

// Conversao do char para inteiro
int charToInt(char c) {
    return (int)c - 97; // 97 = 'a' 
}