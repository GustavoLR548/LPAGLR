#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

typedef std::pair<std::pair<int, int>, int> apples_and_fall_time;

// Classe de grafos
class Tree {

    private: 

        // Num de vertices e arestas
        int num_l;
        int num_c;

        // Todas as vertices e os seus index
        std::set<apples_and_fall_time> apples;

        int max_time;

        std::map<std::string,int> memo;

    public:

        Tree(int l,int c) {
            this->num_l = l;
            this->num_c = c;
            this->max_time = 0;
        }
    
        /** Adicionar aresta ao grafo
         */ 
        void add_apple(int first, int last, int value) {

            apples.insert(std::make_pair(std::make_pair(first, last), value));
            max_time = std::max(max_time, value + 1);
        }

        int get_num_apples(int x, int y) {
            
            return calculate(x,y,0);
        }

        int calculate(int x, int y, int time) {
            
            if(time == max_time) 
                return 0;
            
            std::string key = generate_memo_key(x,y,time);

            if(memo.find(key) != memo.end()) {
                return memo.at(key);
            }
            
            int num_apples = apples.count(std::make_pair(std::make_pair(x,y), time));
            int future_apples = calculate(x,y,time+1);

            for(int i = 0; i < 8; i++) {

                int next_x,next_y;

                next_x = x+dx[i];
                next_y = y+dy[i];
                
                if(is_inside_matrix(next_x,next_y)) 
                    future_apples = std::max(future_apples, calculate(next_x,next_y,time+1));
            }

            memo.insert({key, num_apples + future_apples});

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