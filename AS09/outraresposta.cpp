#include <stdio.h>
#include <stdlib.h>

/*
Solução de Problemas Computacionais - 2017/01
Carolina Coimbra Vieira - 2014032941
PROBLEMA: Maçãs (URI1517)
O problema consiste em determinar o número máximo de maçãs que Rafael consegue pegar com sua 
cesta, dado que as maças caem em coordenadas x e y num tempo t. Os casos de teste consistem 
de, na primeira linha, três valores: N, M e K representando, respectivamente, a quantidade 
de linhas e colunas da área abaixo da árvore, e o número de maçãs derrubadas. A seguir haverá 
K linhas, contendo três inteiros cada, Xi, Yi e Ti, representando, respectivamente, a linha 
e coluna em que a maçã i caiu, e o tempo exato em que Rafael deve estar em tal posição para 
que ela caia em sua cesta. Vale lembrar que os tempos estão em ordem crescente e que maçãs 
podem cair no mesmo tempo em locais diferentes. Por fim, haverá dois inteiros X e Y, indicando 
a linha e a coluna em que Rafael estará no tempo 0. Os casos de teste terminam quando o valor 
de N, M e K são iguais a 0, sendo assim, enquanto isso não ocorre, os casos de teste são 
processados. A solução do problema consiste em montar um vetor de K+1 posições na qual cada 
posição representa uma maça. Esse vetor é do tipo maca criado, isso porque ele deve armazenar
as coordenadas x e y onde a maçã cairá, o tempo e a quantidade de maçãs que poderão ser pegas
até aquele tempo. O vetor começa a ser percorrido de trás para frente e, cada posição é preenchida
com a quantidade igual a 1. Após isso, caso seja possível alcançar as maças de tempos posteriores, 
ou seja, posições acima da posição atual, a quantidade atual é atualizada para 1 + maximo, onde
maximo representa a quantidade máxima encontrada no vetor nas posições acima da posição atual.
Dessa forma, no tempo 0 a quantidade será igual ao máximo de maçãs que Rafael consegue pegar.
Vale ressaltar que, para determinar se é possível alcançar alguma posição, basta verificar se
a distância entre os dois pontos é menor ou igual ao tempo que se tem para ir de um ponto a outro,
de forma que a distância é o máximo entre a diferença entre a coordenada x e coordenada y dos 
pontos, já que pode haver deslocamente pela diagonal. Sendo assim, a solução geral é dada por:
M(i) = max { 1 + M(j), se é possivel ir de i até j*.∀jE[i+1,K] 
			 1, caso contrario.
É possível ir de i até j se:
tempo[j] − tempo[i] >= max( abs(coordx[i]−coordx[j]) , abs(coordy[i]−coordy[j]) )
Tags: vetores, programação dinâmica, typedef
*/

typedef struct {
	int coord_x;
	int coord_y;
	int tempo;
	int quantidade;
} maca;

int maximo (int a, int b){
	if (a > b){
		return a;
	}
	
	return b;
}

int alcance (maca vetor[1010], int i, int j){
	int d_x = abs(vetor[i].coord_x - vetor[j].coord_x);
	int d_y = abs(vetor[i].coord_y - vetor[j].coord_y);
	int d = maximo (d_x, d_y);
	int t = vetor[j].tempo - vetor[i].tempo;

	if (d <= t){
		return 1;
	}

	return 0;
}

int main (){
 	int N = 0, M = 0, K = 0, i = 0, j = 0, posicao = 0, maximo = 0;
 	maca vetor[1010];

 	while (1){

 		fscanf (stdin, "%d %d %d", &N, &M, &K);

 		if (N == 0 && M == 0 && K == 0){
 			break;
 		}

		for (i=1; i<=K; i++){
			fscanf (stdin, "%d %d %d", &vetor[i].coord_x, &vetor[i].coord_y, &vetor[i].tempo);
		}

		fscanf(stdin, "%d %d", &vetor[0].coord_x, &vetor[0].coord_y);
		vetor[0].tempo = 0;

		for (i=K; i>=0; i--){
			posicao = i;
			vetor[posicao].quantidade = 1;

			maximo = 0;
			for(j=(posicao+1); j<=K; j++){
				if (alcance(vetor, posicao, j) == 1 && vetor[j].quantidade > maximo){
					maximo = vetor[j].quantidade;
				}
			}

			if (maximo != 0){
				vetor[posicao].quantidade = 1 + maximo;
			}
		}

		printf("%d\n", vetor[0].quantidade - 1);
	}

	return 0;
}