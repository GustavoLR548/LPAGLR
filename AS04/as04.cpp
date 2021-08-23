#include <vector>
#include <stdint.h>
#include <array> 
#include<bits/stdc++.h>

#define EMPTY -1

using weight  = int;
using counter = uint16_t;


typedef struct DisjoinSets {

    private: 
        
        //Group of parent nodes and their ranks
        std::vector<std::pair<int,int>> nodes;

    public: 

        //Start the disjoinSets with a size of 'n'
        DisjoinSets(int n) {
            
            //start all nodes
            for(int i = 0; i < n ; i++) 
                this->nodes.push_back({0,i});
        
        }

        //Find the parent of 'index'
        int find(int index) {

            if(index != this->nodes.at(index).second)

                this->nodes.at(index).second = find(this->nodes.at(index).second);
            
            return this->nodes.at(index).second;
        }

        //Merge set x with y
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


class Graph {

    private: 

        //Attributes
        counter vertices;
        counter edges;

        std::vector<std::pair<weight,std::pair<counter,counter>>> edges_weights;

    public:
        
        //Constructors

        //Start the Graph with 'vertices' number of vertices
        // Start the graph matrix with a set size
        Graph(counter v) {

            //Starting the matrix with EMPTY value##
            weight default_value = EMPTY;
            
            this->edges    = 0;
            this->vertices = 0;

            for(int i =0 ; i < v; i++) 
                add_vertex();
        }

        //Return the number of vertices the graph has
        counter vertices_num() {
            return this->vertices;
        }

        //Return the number of edges the graph has
        counter edges_num() {
            return this->edges;
        }

        //Basic graph operations
        
        /** Add a new Edge, by giving the coordenates of the first and last vertex
         *  (Obs: There is also the option of adding a weight to the 
         *  Edge, but if not specified, the 'weight' will be 0 )
         */ 
        bool add_edge(counter first, counter last, weight value) {
            bool result = false;

            if(first < this->vertices_num() && last < this->vertices_num()) {
                this->edges++;

                auto edges_pair        = std::make_pair(first,last);
                auto weight_edges_pair = std::make_pair(value,edges_pair);

                this->edges_weights.push_back(weight_edges_pair);
                result = true;
            }

            return result;
        }

        counter add_vertex() {
            counter result = -1;
            counter pos    = this->vertices;

            result = this->vertices;
            this->vertices++;

            std::vector<counter> it;

            return result;
        }

        // Kruskal's Algorythm, with a method to count cycles
        counter kruskal() {

            //sort the edges by their weights
            std::sort(edges_weights.begin(), edges_weights.end());

            counter total_weight = 0;

            //Start the disjointSets with the number of vertices
            DisjoinSets ds(this->vertices);
        
            for (auto it=edges_weights.begin(); it!=edges_weights.end(); it++) {

                //in the current iteration of the array
                //store the first, and last vertex
                int source      = it->second.first;
                int destination = it->second.second;
        
                //get the parent of said vertexes
                int parent_source      = ds.find(source);
                int parent_destination = ds.find(destination);

                //If the parents aren't the same, merge
                //these two in the array
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

    std::cin >> num_roteadores >> quant_cabos;

    Graph* g = new Graph(num_roteadores);

    for(int i = 0; i < quant_cabos; i++) {
        
        uint16_t comeco;
        uint16_t fim;
        uint16_t peso;

        std::cin >> comeco >> fim >> peso;

        g->add_edge(--comeco,--fim,peso);
    }

    std::cout << g->kruskal() << std::endl;

    return 0;
}