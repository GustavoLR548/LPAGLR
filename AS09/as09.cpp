#include <iostream>
#include <vector>
#include <map>
#include <queue>


typedef std::vector<std::vector<int>> matrix;

// Estrutura para guardar as arestas
typedef struct Apple{

    //Arestas de ponto de partida e destino
	int x, y;
    int time; // Peso

    //Criar aresta
	Apple( int x, int y, int time ) {
        this->x = x;
        this->y = y;
        this->time = time;
    }

    //Comparador de arestas para a priority queue
    bool operator < ( const Apple& a ) const {
		return time > a.time;
	}
}Apple;

// Classe de grafos
class Tree {

    private: 

        // Num de vertices e arestas
        int num_l;
        int num_c;

        // Armazenar arestas e seus respectivos pesos
        std::priority_queue<Apple> apples;

        // Todas as vertices e os seus index
        matrix tree_area;

        int max_time;

    public:

        Tree(int l,int c) {
            this->num_l = l;
            this->num_c = c;
            this->max_time = 0;

            matrix tmp(l,std::vector<int>(c,-1));
            this->tree_area = tmp;
        }
    
        /** Adicionar aresta ao grafo
         */ 
        void add_apple(int first, int last, int value) {

            this->tree_area[first][last] = value;
            this->apples.push(Apple(first, last, value));
            max_time = std::max(max_time, value);
        }

        void print() {
            for(int i = 0; i < this->num_l; i++) {
                for(int j = 0; j < this->num_c; j++) {
                    std::cout << this->tree_area[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        int calculate(int x, int y, int time = 0) {
            
            int sum = 0;
            
            std::cout << "max_time: " << max_time << std::endl;

            while(time <= this->max_time - 1) {
                Apple a = apples.top();

                if(a.x == x && a.y == y) {
                    std::cout << "pop!" << std::endl;
                    apples.pop();
                    a = apples.top();
                    sum++;
                } 

                int dx = a.x - x;
                int dy = a.y - y;    

                if(dx != 0) 
                    x += dx/std::abs(dx);           
                if (dy != 0) 
                    y += dy/std::abs(dy);
                

                std::cout << "x: " << x << "y: " << y << "\n" << std::endl;
                std::cout << "a.x: " << a.x << "a.y: " << a.y << "\n" << std::endl;
                std::cout << "time: " << time << "\n" << std::endl;

                if(a.x == x && a.y == y) {
                    std::cout << "pop!" << std::endl;
                    apples.pop();
                    a = apples.top();
                    sum++;
                } 

                time++;
            }

            return sum;
        }

        
};      

int main() {

    int n,m,k;

    std::cin >> n >> m >> k;

    while(n != 0 && m != 0 && k != 0) {

        Tree t(n,m);

        for (int i = 0; i < k; i++) {

            int mx,my,time; 

            std::cin >> mx >> my >> time;

            t.add_apple(--mx,--my,time);
        }   
        int x,y; 

        std::cin >> x >> y;

        int cost = t.calculate(--x,--y);

        std::cout << cost << std::endl;

        std::cin >> n >> m >> k;
    }
}