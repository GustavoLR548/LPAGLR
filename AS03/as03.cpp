#include<iostream>
#include<string>

bool is_inside_input(std::string input, std::string query);

int main() {
    int n;
    
    std::string input;

    std::cin >> n;

    for(int i = 0; i < n; i++) {

        int nQueries;

        std::cin >> input;
        std::cin >> nQueries;
        for(int j = 0; j < nQueries; j++) {

            std::string query;

            std::cin >> query;
            bool result = is_inside_input(input,query);

            if(result) 
                std::cout << "Yes" << std::endl;
            
            else 
                std::cout << "No" << std::endl;


        }


    }

    return 0;
}

bool is_inside_input(std::string input, std::string query) {
    return input.find(query) != -1;
}