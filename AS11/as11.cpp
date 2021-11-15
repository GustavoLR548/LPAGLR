//AS11: Gustavo Lopes Rodrigues
#include<iostream>
#include<vector>
#include<map>
#include<queue>

/*
Complexidade: O(P*M*N) sendo P o número de peoes, M*N as dimensões do tabuleiro. O Algoritmo tambem 
trabalha com um BFS(Breadth First Search), porém, entre as duas operacoes esta e a funcao "calculate",
a ultima acaba sendo a mais custosa.
*/

// Definindo um numero para ser o infinito
#define INF 0x3f3f3f3f

// Definindo principais pecas do tabuleiro
const char PAWN  = 'P';
const char HORSE = 'C';
const char BLOCK = '#';

// Definindo estruturas padroes que sao usadas pelo programa
typedef std::pair<int,int> coordinates;
typedef std::vector<std::vector<int>> matrix;

// Definindo variaveis que guardam os principais movimentos do cavalo, sempre
// em formato de 'L'
int const dx[] = {2, 2,-2,-2,1, 1,-1,-1};
int const dy[] = {1,-1, 1,-1,2,-2, 2,-2};

// Classe do tabuleiro de xadrez
class Chessboard {

  private:

    // Dimensoes do tabuleiro
    int n,m;

    // Coordenadas do cavalo
    coordinates horse_position;

    // Caminho dos peos calculado pelo BFS
    matrix pawn_path;
    matrix memo;  

    // Peoes e seus indices(aqui estamos considerando os peos como os nos de um grafo)
    std::map<coordinates,int> pawns_and_indexes;

    // Estrutura do tabuleiro
    std::vector<std::string> grid;

  public:

    //Construtor, definindo as dimensoes do tabuleiro
    Chessboard(int n, int m) {
      this->n = n;
      this->m = m;

      grid.resize(n);
    }

    // Fazendo a leitura do tabuleiro 
    void read_chessboard() {

      // Variavel para ajudar a organizar os indices dos peos
      int index_pawn = 0;

      for(int i = 0; i < n ; ++i){

          // Ler uma linha do tabuleiro
          std::cin >> grid[i];

          for(int j = 0; j < m ; ++j) {

              if(grid[i][j] == HORSE) // Marcando a posicao do cavalo
                this->horse_position = coordinates({i,j});

              if(grid[i][j] == PAWN) // Marcando a posicao do peao, e colocando seu indice
                pawns_and_indexes[{i,j}] = index_pawn++;
          }
      }
    }

    /*
       Fazendo pesquisa em largura(Breadth first search): fazemos isso pois para 
       evitar fazer pesquisas desnecessarias durante a pesquisa
       do caminho com menor custo.
    */
    void breadth_first_search(int pawn_x, int pawn_y){

      // Iniciando matrix de distancias e iniciando todos valores como -1
      matrix distance(n, std::vector<int>(m, -1));
      std::queue<coordinates> pawn_queue; // Queue de pesquisa

      // Adicionar primeiro peao(no) a se pesquisar
      pawn_queue.push({pawn_x, pawn_y});
      distance[pawn_x][pawn_y] = 0;

      while(!pawn_queue.empty()){

        //Pegar o primeiro peao
        coordinates x = pawn_queue.front();
        pawn_queue.pop();

        // Visitar a vizinha do cavalo(lembrando que o
        // cavalo anda em "L")
        for(int i = 0; i < 8 ; ++i){

          int new_x = x.first + dx[i];
          int new_y = x.second + dy[i];

          // Verificando se esta eh uma posicao valida, e se nada foi preenchido
          // na matrix de distancias
          if(is_position_valid(new_x,new_y) || distance[new_x][new_y] != -1) 
            continue;

          // Adiciona valor valido
          distance[new_x][new_y] = distance[x.first][x.second] + 1;
          pawn_queue.push({new_x, new_y}); // Adicionar proximo peao para pesquisa
        }
      }

      // Pegar indice do peao que foi usado para atravessar grafo
      // ip_index = initial_pawn_index
      int ip_index = pawns_and_indexes[{pawn_x,pawn_y}];
      for(auto it : pawns_and_indexes){

        // Pegar o proximo peao e suas coordenadas
        // current_pawn_index
        int cp_index = it.second;
        int x = it.first.first, y = it.first.second;

        // Registrar distancia entre os peos ip e cp
        pawn_path[ip_index][cp_index ] = pawn_path[cp_index ][ip_index] = distance[x][y];
      }

    }

    // Verificar se as coordenadas providas sao validos dentro do tabuleiro e
    // nao existe bloqueio
    inline bool is_position_valid(int x,int y) const {
      return x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == BLOCK;
    }

    // Funcao inicial para o problema
    int find_all_pawns_minumum_cost_path() {

        // Armazenar o numero de peoes
        int num_pawns = pawns_and_indexes.size();

        // Iniciar processo de fazer o grafo do caminho dos peoes
        pawns_and_indexes[horse_position] = num_pawns;
        pawn_path.assign(num_pawns+1, std::vector<int>(num_pawns+1, 0));
        
        // Calcular o caminho para todos os peos do tabuleiro
        for(auto x : pawns_and_indexes)
            breadth_first_search(x.first.first, x.first.second);

        // Iniciar memo
        int arr_depth = 1<<num_pawns;
        memo = matrix(num_pawns+1,std::vector<int>(arr_depth,-1));
        
        return calculate(num_pawns, arr_depth-1);
    }

    int calculate(int pawn, int mask){

      if(mask == 0) 
        return pawn_path[pawn][pawns_and_indexes.size() - 1];

      // Pegar valor no memo
      int& time = memo[pawn][mask];

      // Esta solucao ja foi feita anteriormente
      // e pode ser resgatada do memo
      if(time != -1) 
        return time;

      // Colocar tempo como infinito para nao resultar 
      time = INF;

      // Navegar por todos os peoes, exceto o atual
      for(int i = 0; i < pawns_and_indexes.size() - 1 ; ++i){
        if(i == pawn || !(mask & (1<<i))) 
          continue;

        // Achar o tempo minimo entre todos os peoes
        time = std::min(time, pawn_path[pawn][i] + calculate(i, mask-(1<<i)));
      }

      return time;
    }

};

int main(){

    // Dimensoes do tabuleiro e
    // numero de peoes
    int n, m, k;

    while(std::cin >> n >> m >> k){

        // Fim do programa
        if(n == 0 && m == 0 && k == 0) 
          break;

        // Iniciar tabuleiro
        Chessboard cb(n,m);
        cb.read_chessboard();

        // Resolver problema
        std::cout << cb.find_all_pawns_minumum_cost_path() << std::endl;
    }

    return 0;
}
