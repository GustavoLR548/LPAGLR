#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>

// Estrutura para guardar as arestas
typedef struct Edge{

    //Arestas de ponto de partida e destino
	std::string i, j;
    int w; // Peso

    //Criar aresta
	Edge( std::string I, std::string J, int W ) {
        this->i = I;
        this->j = J;
        this->w = W;
    }

    //Comparador de arestas para a priority queue
    bool operator < ( const Edge& e ) const {
		return w > e.w;
	}
}Edge;

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
        int vertices;
        int edges;

        // Armazenar arestas e seus respectivos pesos
        std::priority_queue<Edge> edges_weights;

        // Todas as vertices e os seus index
        std::map<std::string,int> all_vertices;

    public:

        Graph() {
            this->vertices = 0;
        }

        int vertices_num() {
            return this->vertices;
        }

        int edges_num() {
            return this->edges;
        }

        //Adicionar a vertice no grafo
        void add_vertex(std::string vertex_name) {

            this->all_vertices[vertex_name] = this->vertices++;
        }

        /** Adicionar aresta ao grafo
         */ 
        void add_edge(std::string first, std::string last, int value) {

            this->edges++;
            this->edges_weights.push(Edge(first, last, value));
        }

        // Algoritmo de kruskal, modificado para 
        // calcular o peso da MST
        int kruskal() {

            if(this->vertices <= 1) {
                return 0;
            }

            int total_weight = 0;

            // Comecar o DisjointSet com o número de vertices 
            // de grafos
            DisjoinSets ds(this->vertices);
        
            while (!edges_weights.empty()) {
                
                auto it = edges_weights.top();

                // Armazenar os vertices da aresta atual
                std::string source      = it.i;
                std::string destination = it.j;
        
                // Resgatar o pai das vertices
                int parent_source      = ds.find(this->all_vertices[source]);
                int parent_destination = ds.find(this->all_vertices[destination]);

                // Se os pais das vertices nao sao os mesmos, significa
                // que junta-los nao formara um ciclo, logo, podemos
                // fazer o merge
                if (parent_source != parent_destination) {
                    ds.merge(parent_source, parent_destination);
                    total_weight += it.w;

                    if(--this->vertices <=1)
                        return total_weight;
                }

                edges_weights.pop();
            }

            // Neste caso, o numero de vertices e diferente do numero de arestas
            // logo, impossivel atravessar o grafo
            return -1;
        }
};      

int main() {

    int num_stations;
    int num_connections;

    std::cin >> num_stations >> num_connections;

    while (num_stations != 0 && num_connections != 0) {

        Graph g;
        std::string station_name;

        // Adicionar vertices
        for(int i = 0; i < num_stations; i++) {

            std::cin >> station_name;
            g.add_vertex(station_name);
        }

        // Leitura das arestas
        for(int i =0; i < num_connections ; i++) {

            std::string source, destination;
            int weight;

            std::cin >> source >> destination >> weight;

            g.add_edge(source,destination,weight);
        }

        std::string start;

        std::cin >> start;
    
        int minimal_weight = g.kruskal();
        
        // -1 = eh impossivel atravessar o grafo
        if(minimal_weight == -1) 
            std::cout << "Impossible" << std::endl;
        else 
            std::cout << minimal_weight << std::endl;

        std::cin >> num_stations >> num_connections;
    }
}