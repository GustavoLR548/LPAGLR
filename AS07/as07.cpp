//AS07: Gustavo Lopes
#include<iostream>
#include<stdio.h>
#include<vector>
#include <cmath>

// Estrutura para armazenar coordenadas de um ponto
typedef struct Point{
    int x;
    int y;
}Point;

// Funções usadas pelo programa
std::vector<Point> create_points(int n);
double find_shortest_point(std::vector<Point> points);
double calculateDistance(int x1, int x2, int y1, int y2);


int main() {

    int n;                         // numero de casos testes
    double shortest_distance;      // menor distancia entre os pontos
    std::vector<Point> points;     // todos os pontos lidos pelo programa

    std::cin >> n;

    // Fazer leitura dos casos de teste
    while(n > 0) {
        points = create_points(n);

        shortest_distance = find_shortest_point(points);

        if(shortest_distance > 10000) 
            std::cout << "INFINITY" << std::endl;
        else 
            printf("%.4f\n", shortest_distance); // formatar para 4 decimais

        std::cin >> n;
    }
}

// Criar os pontos
std::vector<Point> create_points(int n) {

    int x = 0;
    int y = 0;

    std::vector<Point> points;

    for(int i =0 ; i < n; i++) {

        // Leituras das coordenadas x e y
        std::cin >> x >> y;

        // Criar ponto e adicionar ao vector
        Point p;
        p.x = x;
        p.y = y;

        points.push_back(p);

    }

    return points;
}

// Algoritmo de forca bruta para calcular a menor
// distancia entre todos os pontos
double find_shortest_point(std::vector<Point> points) {

    double shortest = 99999999999999999;

    for(int i = 0; i < points.size(); i++) {

        Point pI = points.at(i);
        for(int j = 0; j < points.size(); j++) {

            // Impedir programa de analisar o mesmo ponto
            // com ele mesmo
            if(i == j) 
                continue;

            Point pJ = points.at(j);

            // Calcular distancia atual entre os dois pontos
            double distance = calculateDistance(pI.x,pJ.x,pI.y,pJ.y);

            // Atualizar menor distancia 
            if(distance < shortest) 
                shortest = distance;
        }
    }

    return shortest;
}

// Calcular a distância entre dois pontos
double calculateDistance(int x1, int x2, int y1, int y2) {
    return sqrt(pow(x2 - x1,2) + pow(y2-y1,2));
}
