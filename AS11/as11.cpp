#include <iostream>
#include <vector>
#include <set>

const char PAWN  = 'P';
const char HORSE = 'C';
const char EMPTY = '!';

const int dx[8] = {2, 1, -1, -2, -2,  -1,  1,  2};
const int dy[8] = {1, 2,  2,  1, -1,  -2, -2, -1};

typedef std::vector<std::vector<char>> matrix;
typedef std::pair<int,int> coordinates;

class Chessboard {

    private: 

        int width;
        int height;

        matrix board;
        coordinates horse;

        std::set<coordinates> pawns;

    public: 

        int solution;

        Chessboard(int width, int height) {
            this->width  = width;
            this->height = height;

            this->board = matrix(width, std::vector<char>(height, EMPTY));
        }

        void read_chessboard() {

            for(int i = 0 ; i < this->width; i++) {
                for (int j = 0; j < this->height; j++) {
                    
                    std::cin >> this->board[i][j];
                    if(this->board[i][j] == HORSE) {
                        horse.first  = i;
                        horse.second = j;
                    }
                    else if(this->board[i][j] == PAWN) 
                        pawns.insert(std::make_pair(i,j));
                    
                }
            }
        }

        void find_min_movements_for_pawns() {
            
            coordinates first = this->horse;
            solution = this->width*this->height;
            solve(first);
        }

        void solve(coordinates c,int pawns_captured = 0, int moves = 0) {

            if (moves >= (this->width*this->height)/2) 
                return;

            if(pawns.count(c)) {
                pawns_captured++;
                if(pawns_captured == this->pawns.size()) {
                    solution = std::min(solution,moves);
                    return;
                }
            }

            std::vector<coordinates> possible_movements;

            for(int i = 0; i < 8; i++) {

                coordinates tmp = c;

                tmp.first  += dy[i];
                tmp.second += dx[i];

                if(is_valid_movement(tmp)) {
                    possible_movements.push_back(tmp);
                }
                
            }

            std::vector<coordinates> not_visited;

            for(int i = 0; i < possible_movements.size(); i++) {
                if(pawns.count(possible_movements[i])) {
                    solve(possible_movements[i],pawns_captured,moves + 1);
                } else {
                    not_visited.push_back(possible_movements[i]);
                }
            }

            if(!not_visited.empty()) {
                for (int i = 0 ; i < not_visited.size(); i++) {
                    solve(not_visited[i],pawns_captured,moves + 1);
                }
            }
                

        }


        bool is_valid_movement(coordinates c) {
            return c.first >= 0 && c.first < width && c.second >= 0 && c.second < height && this->board[c.first][c.second] != '#';
        }

        void print() {
            for(int i = 0 ; i < width; i++) {
                for(int j = 0 ; j < height; j++) {
                    std::cout << this->board[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};

int main() {
    
    int n,m,k;

    while(std::cin >> n >> m >> k) {
        if(n == 0 && m == 0 && k == 0) 
            break;

        Chessboard cb(n,m);

        cb.read_chessboard();

        cb.find_min_movements_for_pawns();

        std::cout << cb.solution * 2 << std::endl;
    }

    
}