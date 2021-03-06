# [Penalização](https://www.beecrowd.com.br/judge/pt/problems/view/2225)

No jogo Pomekon, um dos objetivos é visitar lugares reais para conseguir novos itens e experiência. Como Fulyane não gosta muito de sair de casa, ela fez um programa que simula sua localização, fornecendo falsas coordenadas de sua localização para o jogo. Ela também fez um controle, que faz com que ela possa se movimentar nas coordenadas falsas, simulando como se estivesse realmente caminhando, porém sem sair de casa.

Pesquisando em fóruns, viu que para não ser banida do jogo, teria que se mover utilizando apenas as rotas reais, porém, também viu que podia se mover instantaneamente de um lugar para outro, sem utilizar as rotas reais, no máximo K vezes por dia, pois caso ela se teletransportar além de K vezes, poderia ser banida do jogo para sempre.

Fulyane começa sempre no lugar identificado pelo índice 1, e quer visitar todos os demais o mais rápido possível, se teletransportando no máximo K vezes.

# Entrada

A entrada é composta por diversas instâncias. A primeira linha da entrada contém um inteiro T indicando o número de instâncias. A primeira linha de cada instância contém três inteiros N (1 ≤ N ≤ 15), M (1 ≤ M ≤ N2) e (0 ≤ K ≤ 5), representando, respectivamente, a quantidade de lugares, quantidade de  rotas e a quantidade máximo permitida de teletransportes. Então seguiram M linhas, cada uma contendo três inteiros A, B e C (1 ≤ C ≤ 30000), representando que uma rua conecta os lugares A e B, e Fulyane demora C minutos para ir de A até B utilizando esta rua.

# Saída

Para cada instância, imprima a quantidade mínima de minutos para Fulyane visitar todos os N lugares utilizando, no máximo, K teletransportes. Caso não seja possível visitar os N lugares, imprima -1.

Exemplo de Entrada | Exemplo de Saída
------------ | -------------
2            | 7
3 2 0        | -1
1 2 3        |
1 3 2        |
5 4 0        |
4 3 16       |
3 3 13       |
5 2 15       |
2 4 20       |

