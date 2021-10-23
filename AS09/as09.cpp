#include <iostream>
#include <string>
#include <vector>
#include <map>

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

typedef std::vector<std::vector<int>> matrix;

// Classe de grafos
class Tree {

    private: 

        // Num de vertices e arestas
        int num_l;
        int num_c;

        // Todas as vertices e os seus index
        matrix tree_area;

        int max_time;

        std::map<std::string,int> memo;

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
            max_time = std::max(max_time, value + 1);
        }

        int get_num_apples(int x, int y) {
            
            return calculate(x,y,0);
        }

        int calculate(int x, int y, int time) {
            
            if(time == max_time) 
                return 0;

            std::string key = generate_memo_key(x,y,time);

            if(memo.count(key))
                return memo.at(key);

            int num_apples = (this->tree_area[x][y] == time ? 1 : 0);
            int future_apples = calculate(x,y,time+1);

            for(int i = 0; i < 8; i++) {

                int next_x,next_y;

                next_x = x+dx[i];
                next_y = y+dy[i];
                
                if(is_inside_matrix(next_x,next_y))
                    future_apples = std::max(future_apples, calculate(next_x,next_y,time+1));
            }

            return num_apples + future_apples;
        }

        bool is_inside_matrix(int x,int y) {
            return !( x < 0 || x >= num_l || y < 0 || y >= num_c );
        }

        std::string generate_memo_key(int x,int y, int time) {
            return std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(time);
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

        int cost = t.get_num_apples(--x,--y);

        std::cout << cost << std::endl;

        std::cin >> n >> m >> k;
    }
}