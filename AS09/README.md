# [Maçãs](https://www.beecrowd.com.br/judge/pt/problems/view/1517)

Rafael resolveu passar o final de semana na fazenda de seu tio, Antônio, e quando percebeu que havia lá uma árvore carregada de maçãs, decidiu fazer uma torta de maçã.

Para fazer a torta, porém, Rafael precisaria pegar o maior número de maçãs possíveis, e para isso pediu ajuda a seu primo. O combinado era: Seu primo subiria na árvore e chacoalharia diversos galhos contendo as maçãs, fazendo com que elas caissem. A medida que as maçãs iam caindo, Rafael estaria no chão com uma cesta e iria pegá-las no meio do caminho entre a árvore e o chão. Como as maçãs caiam com muita velocidade, o impacto com o chão fazia com que elas rachassem, e Rafael decidiu que iria ignorar todas as maçãs que não conseguisse pegar com a cesta.

Podemos representar a situação da seguinte maneira: Rafael está posicionado em uma área de N linhas e M colunas abaixo da árvore, e pode se mover uma posição horizontalmente, verticalmente ou diagonalmente por segundo. Cada maçã cai em uma determinada posição dessa área, digamos [i, j] (linha i, coluna j), e o momento exato em que Rafael deve estar nessa posição para que ela caia dentro de sua cesta é um determinado tempo t.

Dada a posição inicial de Rafael, diga quantas maçãs ele consegue pegar com sua cesta, dentre todas as K maçãs derrubadas por seu primo.

# Entrada

Haverá diversos casos de teste. Cada caso de teste inicia com três inteiros, N, M e K (3 ≤ N, M ≤ 20, 1 ≤ K ≤ 1000), representando, respectivamente, a quantidade de linhas e colunas da área abaixo da árvore, e o número de maçãs derrubadas por seu primo.

A seguir haverá K linhas, contendo três inteiros cada, Xi, Yi e Ti (1 ≤ Xi ≤ N, 1 ≤ Yi ≤ M, 1 ≤ Ti ≤ 2*K), representando, respectivamente, a linha e coluna em que a maçã i caiu, e o tempo exato em que Rafael deve estar em tal posição para que ela caia em sua cesta.

A sequência de valores Ti dada na entrada é não-decrescente, ou seja, Ti-1 ≤ Ti, para todo 2 ≤ i ≤ K. Não há duas maçãs que caiam no mesmo lugar ao mesmo tempo.

A seguir haverá dois inteiros X e Y (1 ≤ X ≤ N, 1 ≤ Y ≤ M), indicando a linha e a coluna em que Rafael estará no tempo 0.

O último caso de teste é indicado quando N = M = K = 0, o qual não deverá ser processado.

# Saída 

Para cada caso de teste, imprima uma linha contendo um inteiro, representando qual o número máximo de maçãs que Rafael consegue pegar com sua cesta.

Exemplo de Entrada | Exemplo de Saída
------------ | -------------
5 5 3        | 3
2 2 1        | 3
3 3 2 |
2 4 3 |
1 1 | 
5 5 4 |
3 2 1 |
3 5 2 |
2 5 3 |
1 5 4 |
3 3 |
0 0 0 |
