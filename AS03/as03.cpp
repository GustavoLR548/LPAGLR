//AS03: Gustavo Lopes Rodrigues 
#include<iostream>
#include<string>

bool is_inside_input(std::string input, std::string query);

int main() {

    std::string input; // string entrada para procura de query
    int n;             // numero de 'std::string input' que sera lido

    std::cin >> n;

    for(int i = 0; i < n; i++) {
        
        int nQueries;

        // Inserir o 'input' e fazer a leitura de quantas query
        // sera lido
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

// Funcao para verificar se uma string 'query' encontra-se
// dentro da string 'input' de forma nao sequencial
bool is_inside_input(std::string input, std::string query) {
    
    int query_index =0;

    for(int i = 0; i < input.size(); i++) {

        if(input.at(i) == query.at(query_index)) 
            query_index++;

        //Se o query index for igual ao tamanho dela
        //significa que foi possivel encontrar todos
        //os caracteres da query dentro do input,
        //logo a operacao foi um sucesso
        if(query_index == query.size())
            return true;
    }

    return false;
}