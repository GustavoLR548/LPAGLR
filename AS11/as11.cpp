#include <iostream>
#include <vector>

#define PAWN 'P'
#define HORSE 'C'
#define EMPTY '-1'

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

        std::vector<coordinates> pawns;

    public: 

        Chessboard(int width, int height) {
            this->width  = width;
            this->height = height;

            matrix tmp(width, std::vector<char>(height, EMPTY));
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
                        pawns.push_back(std::make_pair(i,j));
                    
                }
            }
        }

        int find_min_movements_for_pawns() {
            return calculate(this->horse,0);
        }

        int calculate(coordinates curr,int pawns_eaten) {

            
            
        }

        bool is_valid_movement(int x,int y) {
            auto curr = this->board[x][y];
            return x >= 0 && x < width && y >= 0 && y < height && curr != '#' && curr != '-1';
        }
};

int main() {
    
    int n,m,k;

    while(std::cin >> n >> m >> k) {
        if(n == 0 && m == 0 && k == 0) 
            break;

        Chessboard cb(n,m);

        cb.read_chessboard();
    }

    
}