//AS06: Gustavo Lopes
#include<vector>
#include<stdint.h>
#include<array> 
#include<bits/stdc++.h>
#include<iostream>

#define INF INT_MAX

//criando o tipo 'peso' e 'contador'
using weight  = int;
using counter = uint16_t;

typedef std::vector<std::vector<weight>> matrix;
typedef std::vector<matrix> space3d;

/* Complexidade: O(v^2) -> pois o codigo irá fazer o algoritmo DFS
e depois uma versão modificada do DFS, que irá ordenar os vertices a serem visitados a
cada iteração, logo, o maior preço será para ordenar os vertices, que no caso mais
caro, irá custar O(v^2)
*/

// Classe de grafos
class Graph {

    private: 

        // Num de vertices
        counter vertices;

        // matrix de adjacencia
        matrix adj;

    public:

        // Iniciar grafo com 'v' numero de vertices
        Graph(counter v) {
            this->vertices = v;

            // Criar a matrix de adjacencia
            matrix tmp(v,std::vector<weight>(v,INF));
            adj = tmp;
        }
        
        /** Adicionar aresta ao grafo
         */ 
        void add_edge(counter first, counter last, weight value) {

            adj[first][last] = value;
            adj[last][first] = value;              
        }

        weight time_necessary(int num_teleports) {
            matrix floydWarshall = findAllPairShortestPath();

            space3d tmp(this->vertices, matrix((1 << this->vertices) + 1, std::vector<weight>(this->vertices,-1)));

            print(floydWarshall);
            return (weight)-1;
            //return find_minimum_weight_path(tmp, 0, 1, num_teleports , num_teleports);
        }

        matrix findAllPairShortestPath() {
            matrix dist = this->adj;
        
            for (int k = 0; k < this->vertices; k++) 
                for (int i = 0; i < this->vertices; i++) 
                    for (int j = 0; j < this->vertices; j++) 
                        dist[i][j] = std::min(dist[i][j],dist[i][k] + dist[k][j]);
        
            return dist;
        }

        int find_minimum_weight_path(space3d pd, int u, int mask, int num_teleports, int total_teleports){

            if( mask == ( 1 << this->vertices ) -1 ) 
                return 0;

            int &p = pd[u][mask][num_teleports]; 
            //std::cout << "p: " << p << std::endl;

            if(p != -1) 
                return p;

            std::cout << "k = " << num_teleports << " K = " << total_teleports << std::endl;
            for(int i = num_teleports+1 ; i < total_teleports; i++ )
                if(pd[u][mask][i] < p) 
                    return INF;
            
            int ret = INF;
            
            for (int i = 0 ; i < this->vertices; i++) {
                std::cout << "entrei no for" << std::endl;
                std::cout << "\t u = " << u << " i " << i << std::endl;
                std::cout << "\t\t mat[u][i] = " << this->adj[u][i] << std::endl;
                if( mask & (1<<i) )   
                    continue;

                if( num_teleports =! 0 ) 
                    ret= std::min(ret, find_minimum_weight_path(pd,i, mask | (1<<i), num_teleports-1,total_teleports));

                if( this->adj[u][i] < INF) {
                    ret= std::min(ret, find_minimum_weight_path(pd,i, mask | (1<<i), num_teleports,total_teleports) + this->adj[u][i]);	
                }
            }
            std::cout << "--------------------" <<  std::endl;
            return ret;	
        }	

        void print(matrix m) {
            for(int i = 0; i < this->vertices; i++) {
                for(int j = 0; j < this->vertices; j++) {
                    std::cout << m[i][j] << " ";
                }
                std::cout << std::endl;
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
