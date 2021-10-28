# Cavalo

Rafael gosta tanto de jogar xadrez que resolveu inventar novas maneiras de se desafiar. Dessa vez ele resolveu jogar com a peça do cavalo, pois a forma como ela se movimenta pareceu adicionar um pouco de dificuldade ao jogo, segundo Rafael.

O desafio é o seguinte: Há um cavalo e K peões no tabuleiro. Dada uma posição inicial do cavalo e dos peões, qual a menor quantidade de movimentos necessários para capturar os K peões e voltar à posição inicial?

Lembre que a peça do cavalo pode mover-se usando saltos de formato L, ou seja, duas posições para a vertical e uma posição para a horizontal, ou duas posições para a horizontal e uma posição para a vertical. Para capturar um peão, basta ocupar a mesma posição que ele no tabuleiro.

# Entrada

Haverá diversos casos de teste. Cada caso de teste inicia com três inteiro N, M e K (5 ≤ N, M ≤ 100, 2 ≤ K ≤ 15), representando, respectivamente, a quantidade de linhas e de colunas do tabuleiro, e a quantidade de peões a serem capturados.

As próximas N linhas irão conter M caracteres cada, onde o caractere na linha i e coluna j indica que na posição [i, j] do tabuleiro há:

  * '.' uma posição válida onde o cavalo pode pular.
  * '#' uma posição inválida onde o cavalo não pode pular.
  * 'C' a posição inicial do cavalo de Rafael.
  * 'P' a posição de um dos K peões o qual Rafael deve capturar.

O último caso de teste é indicado quando N = M = K = 0, o qual não deve ser processado.

# Saída

Para cada caso de teste, imprima um inteiro, representando a quantidade mínima de saltos que o cavalo de Rafael deve fazer para capturar os K peões e retornar à posição inicial.

É garantido que sempre haverá ao menos uma maneira de capturar todos os peões.

Exemplo de Entrada | Exemplo de Saída
------------ | -------------
5 5 2        | 4
.....        | 8
.P...        |
...P.        |
.....        |
..C..        |
4 6 2        |
.P##.P       |
..##..       |
..##..       |
..C...       |
0 0 0        |
