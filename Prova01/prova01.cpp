#include<iostream> 
#include<stdint.h>
#include<vector>

uint64_t bacteria_growth(int n, int a1, int a2, int a3, int a4);

int main() {
    
    uint64_t n;
    uint16_t a1, a2, a3, a4;

    std::cin >> n;
    while (n != 0) {

        std::cin >> a1 >> a2 >> a3 >> a4;

        int num_bacteria = bacteria_growth(n,a1,a2,a3,a4);
        std::cout << num_bacteria << std::endl;

        std::cin >> n;
    }
}

uint64_t bacteria_growth(int n, int a1, int a2, int a3, int a4) {

    uint64_t growth = a1 + a2 + a3 + a4;

    std::vector<int> growths = { a1, a2, a3 ,a4};

    for(int i = n - 5 ; i >= 0; i--) {

        uint64_t new_growth = growth * 2;
        growths.push_back(new_growth - growth);

        growth = new_growth;

        int growth_to_lose = growths.at(0);
        growths.erase(growths.begin());

        growth -= growth_to_lose;
    }

    return growth;

}