// Prova 3: Gustavo Lopes
#include <iostream>
#include <vector>

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

        Graph(size_t vertices) {
            this->vertices = vertices;
            this->adj_matrix = matrix(this->vertices, std::vector<int>(vertices, INF));
        }

        void add_edge(int v1, int v2, int weight) {

            if (this->adj_matrix[v2][v1] != INF) {

                this->adj_matrix[v1][v2] = 0;
                this->adj_matrix[v2][v1] = 0;
            } else {
                this->adj_matrix[v1][v2] = weight;
            }
        } 

        int find_cost_of_minimum_path(int origin, int destination) {

            // Vetor para guardar o peso do caminho da vertice origem
            // até o vértice de destino
            std::vector<int> cost;     

            // Vetor para armazenar todos os vertices jah visitados
            std::vector<bool> visited;

            visited = std::vector<bool>(this->vertices,false); 
            cost    = std::vector<int>(this->vertices,INF);    
            
            cost[origin] = 0;
            
            while(true){

                // Guardar o indice do vertex com menor peso
                int min_weight_vertex;

                // Guardar o custo do vertex com menor peso
                int min_cost = INF;

                for(int i = 0; i < this->vertices; i++){

                    if(visited[i] == false && min_cost > cost[i])
                        min_weight_vertex = i,
                        min_cost          = cost[min_weight_vertex];
                    
                }

                // Se o custo minimo for infinito , quer dizer que a pesquisa
                // acabou, ou nao tem caminho ate o vertice destino
                if(min_cost == INF) 
                    break;

                // Marcar vertice com menor peso como visitada
                visited[min_weight_vertex] = true;     
                
                for(int i = 0; i < this->vertices; i++){

                    int travel_weight = cost[min_weight_vertex] + this->adj_matrix[min_weight_vertex][i];
                    
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

        Graph g(vertices);

        for (int i = 0; i < edges ; i++) {

            int v1,v2, weight;
            std::cin >> v1 >> v2 >> weight;

            g.add_edge(--v1,--v2,weight);

        }

        int inquiries;
        std::cin >> inquiries;

        for (int i = 0 ; i < inquiries; i++) {

            int origin, destination;
            std::cin >> origin >> destination;

            int minimum_cost = g.find_cost_of_minimum_path(--origin,--destination);

            if (minimum_cost < INF) 
                std::cout << minimum_cost << std::endl;
            else 
                std::cout << "Nao e possivel entregar a carta" << std::endl;

        }

        std::cout << std::endl;
    }

	return 0;
}