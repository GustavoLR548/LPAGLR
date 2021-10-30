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
                        horse.first  = j;
                        horse.second = i;
                    }
                    else if(this->board[i][j] == PAWN) 
                        pawns.insert(std::make_pair(i,j));
                    
                }
            }
        }

        int find_min_movements_for_pawns() {
            
            int min_movements = INT32_MAX;
            int num_movements = 0;
            int pawns_captured = 0;
            
            for(int i = 0; i < 8; i++) {

                coordinates curr = this->horse;
                curr.first  += dx[i];
                curr.second += dy[i];

                if (!is_valid_movement(curr)) {
                     continue;
                }
                
                num_movements++;

                std::vector<coordinates> previous_movements;
                previous_movements.push_back(curr);
                while(pawns_captured != pawns.size() && !previous_movements.empty()) {

                    coordinates tmp = curr;
                    bool valid_movement_found = false;

                    if(pawns.count(tmp)) 
                        pawns_captured++;
                    
                    if(pawns_captured == pawns.size())
                        continue;

                    num_movements++;

                    for(int j = 0; j < 8; j++) {

                        tmp.first  += dx[i];
                        tmp.second += dy[i];
                    
                        if (!is_valid_movement(tmp)) {
                            continue;
                        } else {
                            previous_movements.push_back(tmp);
                            valid_movement_found = true;
                            break;
                        }
                    }

                    if(valid_movement_found) {
                        curr = tmp;
                    } else {
                        curr = previous_movements[previous_movements.size()-1];
                        previous_movements.pop_back();
                    } 

                }

                min_movements = std::min(min_movements*2,num_movements);
                num_movements = 0;
                pawns_captured = 0;
            }

            return std::abs(min_movements/4);
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
        }
};

int main() {
    
    int n,m,k;

    while(std::cin >> n >> m >> k) {
        if(n == 0 && m == 0 && k == 0) 
            break;

        Chessboard cb(n,m);

        cb.read_chessboard();

        std::cout << cb.find_min_movements_for_pawns() << std::endl;
    }

    
}