// Prova 3: Gustavo Lopes
#include <iostream>
#include <vector>
#include <set>

/*
Complexidade: O(V^2) :Sendo V o numero de vertices no grafo.
O algoritmo usa djikstra para solucionar o problema proposto, e este
no pior caso irá rodar todas as vértices por todas as vértices
*/

#define INF 0x3f3f3f3f

typedef std::vector<std::vector<int>> matrix;

class Graph {

    private:

        size_t vertices;
        matrix adj_matrix;

    public:

        // Construtor: Iniciando todos os vertices
        Graph(size_t vertices) {
            this->vertices = vertices;
            this->adj_matrix = matrix(this->vertices, std::vector<int>(vertices, INF));
        }

        /**
         * @brief Adicionar uma aresta ao grafo
         * 
         * @param v1 vertice inicial 
         * @param v2 vertice final
         * @param weight peso da aresta
         */
        inline void add_edge(int v1, int v2, int weight) {

            if (this->adj_matrix[v2][v1] != INF) {

                this->adj_matrix[v1][v2] = 0;
                this->adj_matrix[v2][v1] = 0;
            } else {
                this->adj_matrix[v1][v2] = weight;
            }
        } 

        /**
         * @brief Algoritmo de Dijkstra para encontrar o menor caminho entre
         * dois pontos no grafo
         * 
         * @param origin - vertice inicial
         * @param destination - vertice final
         * @return tempo em horas para ir do ponto 'origin' até 'destination'
         */
        int find_cost_of_minimum_path(int origin, int destination) {

            // Vetor para guardar o peso do caminho da vertice origem
            // até o vértice de destino
            std::vector<int> cost(this->vertices,INF);     

            // Vetor para armazenar todos os vertices já
            std::set<int> visited_vertices; 
            
            // Como a viagem comeca da vertice 'origin',
            // o peso desta para chegar la é 0
            cost[origin] = 0;
            
            while(visited_vertices.size() != this->vertices){

                // Guardar o indice e custo do vertice com menor peso
                int min_cost_index;
                int min_cost_weight = INF;

                // Encontrar o peso e o índice do 
                // vertice de menor peso
                for(int i = 0; i < this->vertices; i++){

                    if(visited_vertices.count(i) == 0 && min_cost_weight > cost[i])
                        min_cost_index  = i,
                        min_cost_weight = cost[min_cost_index];
                    
                }

                // Se o custo minimo for infinito , quer dizer que a pesquisa
                // acabou, ou nao tem caminho ate o vertice destino
                if(min_cost_weight == INF) 
                    break;

                // Marcar vertice como visitada
                visited_vertices.insert(min_cost_index);     
                
                for(int i = 0; i < this->vertices; i++){

                    int travel_weight = cost[min_cost_index] + this->adj_matrix[min_cost_index][i];
                    
                    // Verificar se o peso da viagem pelo vertice de menor peso com o seu vizinho
                    // eh menor do que o peso da viagem atualmente registrado
                    if(cost[i] > travel_weight)
                        cost[i] = travel_weight;
                    
                }
            }

            // Retornando o preco da viagem da origem ao destino   
            return cost[destination];
        }

};

int main() {
    
    int vertices, edges;

    while(std::cin >> vertices >> edges) {

        if ( vertices == 0 && edges == 0 )
            break;

        // Iniciando o grafo para fazer a questão

        Graph g(vertices);

        for (int i = 0; i < edges ; i++) {

            int vertice_1,vertice_2, weight;
            std::cin >> vertice_1 >> vertice_2 >> weight;

            g.add_edge(--vertice_1,--vertice_2,weight);

        }

        // Resolvendo o problema proposto

        int inquiries;
        std::cin >> inquiries;

        for (int i = 0 ; i < inquiries; i++) {

            int origin, destination;
            std::cin >> origin >> destination;

            int hours_to_traverse = g.find_cost_of_minimum_path(--origin,--destination);

            if (hours_to_traverse < INF) 
                std::cout << hours_to_traverse << std::endl;
            else 
                std::cout << "Nao e possivel entregar a carta" << std::endl;

        }

        std::cout << std::endl;
    }

	return 0;
}