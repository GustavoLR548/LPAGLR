# [Bactérias](https://www.beecrowd.com.br/judge/pt/problems/view/1422)

Pietro Demazio é um terrorista italiano condenado que fugiu para o Brasil, onde conseguiu um disfarce trabalhando como programador de jogos.  Em seu novo plano de destruição do planeta, Pietro desenvolveu um novo tipo de bactéria mortal, capaz de dizimar toda a população terrestre.

Durante 4 dias, Demazio criou colônias desses micro-organismos, mas ao fim do quarto dia, descobriu que o código genético das mesmas possuía um grave erro, que fazia com que as bactérias morressem depois de 4 dias de vida. Como a primeira colônia fora criada 3 dias atrás, ele rapidamente modificou o código genético delas (através de radiação), de modo que elas se reproduzissem todas os dias. Tal reprodução é assexuada, e é feita por bipartição (ou seja, uma bactéria gera exatamente outra bactéria por dia).

Assim, se Pietro criou 3 bactérias no dia 1, 4 no dia 2, 2 no dia 3 e 5 no dia 4, terá no total 14 bactérias ao final do quarto dia, quanto ele faz a mutação. Logo após tal mutação, elas se reproduzem, e aí teremos 28 bactérias. Como a primeira colônia (com 3 bactérias) morre ao final desse quarto dia, o número de bactérias no início do quinto dia é 25. Ao final do quinto dia, essas 25 se reproduzem, resultando em 50 bactérias. Mas como a segunda colônia (com 4 bactérias) morre ao final desse dia, no início do sexto dia tem-se 46 bactérias.

Demazio observa com atenção tal crescimento da população de bactérias, e já está planejando quando vai liberá-las para fazer o serviço. Para tal, ele precisa saber quantas bactérias existirão depois de um determinado número de dias. Ele pede a você que faça um programa que determine a quantidade de bactérias existentes depois de N dias, dadas as populações das 4 primeiras colônias.

# Entrada

A entrada contém várias instâncias. Cada instância possui duas linhas. A primeira linha possui um inteiro N (5 ≤ N ≤ 1.000.000.000), representando o dia para o qual Pietro deseja saber a população de bactérias que ele terá. A segunda linha contém quatro inteiros a1, a2, a3, a4 (1 ≤ a1, a2, a3, a4 ≤ 1.000), onde ak representa a quantidade de bactérias criadas no dia k.

A entrada termina quando N = 0.

# Saída

Para cada instância na entrada, imprima uma linha contendo a quantidade de bactérias que Pietro terá no início do dia N. A resposta dada deve ser módulo 13371337.

Exemplo de Entrada | Exemplo de Saída
------------ | -------------
5 | 19
1 2 3 4 | 101
7 |
9 2 3 4 |
0 |
