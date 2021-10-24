//AS09 - Gustavo Lopes Rodrigues
#include <iostream>
#include <vector>
#include <set>

/*
Complexidade do código: O(n*m*t), sendo nxm as dimensões da matriz(area da arvore) vezes o
tempo t que seria o tempo maximo que o Rafael tem para atravessar a arvore e recuperar as macas
*/

// Definar uma posicao vazia como -1
#define EMPTY -1

// Guardar o calculo dos 8 vizinhos ao redor de Rafael na hora 
// de mover para uma nova posicao
const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// Estrutura que guarda as macas e o tempo que elas devem ser pegas antes de cair no chao
typedef std::pair<std::pair<int, int>, int> apples_and_fall_time;

class Tree {

    private: 

        // Numero de linhas e colunas da matriz da area da arvore
        int num_l;
        int num_c;

        // set -> guardar instancias unicas das macas
        std::set<apples_and_fall_time> apples;

        // estrutura para realizar memoization
        std::vector<int> memo;

        // Tempo maximo para atravessar a arvore
        int max_time;

    public:

        // Construtor: iniciar variaveis
        Tree(int l,int c) {
            this->num_l = l;
            this->num_c = c;
            this->max_time = 0;
        }
    
        // Adicionando maca ao, set, e atualizando o tempo maximo
        void add_apple(int x, int y, int time) {

            apples.insert(std::make_pair(std::make_pair(x, y), time));

            // +1 serve como margem de erro, para que Rafael possa atravesar a maca mais demorada
            max_time = std::max(max_time, time + 1); 
        }

        // Resgatar o numero de macas que podem ser pegas a partir das posicoes
        // dadas
        int get_num_apples(int x, int y) {
            
            /*
            Iniciar vetor para memoization, no caso, este e basicamente um vetor 
            unidimensional tratado como um vetor tridimensional. Basicamente ele
            funciona como um mapa, porem, muito mais facil de acessar e com custo
            mais baixo
            */
            std::vector<int> tmp(this->num_c*this->num_l*this->max_time,EMPTY);
            memo = tmp;
            
            // Iniciar calculo
            return calculate(x,y,0);
        }

        int calculate(int x, int y, int time) {
            
            // Se o tempo tiver acabado, retornar 0
            if(time == max_time) 
                return 0;
            
            int key = calculate_memo_key(x,y,time);

            // Se a solucao para o atual problema da recursao ja tiver 
            // sido calculado, apenas retornar resultado calculado anteriormente
            if(memo[key] != EMPTY) {
                return memo[key];
            }
            
            // Contar numero de macas neste espaco atual(x,y)
            int num_apples = apples.count(std::make_pair(std::make_pair(x,y), time));

            // Calcular quantas macas estaram futuramente disponiveis neste espaco
            int future_apples = calculate(x,y,time+1);

            // Navegar toda a vizinhanca de Rafael
            for(int i = 0; i < 8; i++) {

                int next_x,next_y;

                // Resgatar atual vizinhanca de Rafael
                next_x = x+dx[i];
                next_y = y+dy[i];
                
                if(is_inside_tree_area(next_x,next_y)) 
                    // Resgatar das proximacas iteracoes, qual retornara com o maior
                    // numero de macas
                    future_apples = std::max(future_apples, calculate(next_x,next_y,time+1));
            }

            // Armazenar chave da atual iteracao no memo
            // e retornar-la
            memo[key] = num_apples + future_apples;
            return memo[key];
        }

        // Verifica se as coordenadas indicadas representa um ponto
        // que esta dentro da area da arvore
        bool is_inside_tree_area(int x,int y) {
            return !( x < 0 || x >= num_l || y < 0 || y >= num_c );
        }

        // Calcular a chave do vetor de memoizacao, basicamente, traduzindo a informacao
        // do vetor 1D como se fosse um vetor 3D
        int calculate_memo_key(int x,int y,int time) {
            return x + this->num_l * (y + this->num_c * time);
        }
        
};      

int main() {

    // Ler as dimensoes da arvore e o numero de macas
    int n,m,k;
    std::cin >> n >> m >> k;

    while(n != 0 && m != 0 && k != 0) {

        // Criar a arvore, com uma area nxm
        Tree t(n,m);

        // Ler todas as macase seus tempos
        for (int i = 0; i < k; i++) {

            int maca_x,maca_y,time; 

            // Ler maca e coloca-la na arvore
            std::cin >> maca_x >> maca_y >> time;
            t.add_apple(--maca_x,--maca_y,time); // Obs: -1 para considerar o indexamento no vetor
        }   
        int x,y; 

        // Inserir posicao inicial de rafael e calcular o numero de macas
        std::cin >> x >> y;
        int cost = t.get_num_apples(--x,--y);

        std::cout << cost << std::endl;

        std::cin >> n >> m >> k;
    }
}