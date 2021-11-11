# [Expensive subway](https://onlinejudge.org/external/117/11710.pdf)

Peter mora em "Expensive City", uma das cidades mais caras do mundo. Peter não tem o suficiente dinheiro para comprar um carro, e 
os ônibus na "Expensive City" são muito ruins, então ele usa o metrô para ir para trabalhar. Até agora, o metrô era muito barato:
você podia viajar para qualquer lugar com apenas uma passagem de US $ 2. No último mês, os gerentes decidiram que era muito barato,
então inventaram o STF (Sistema de Tarifas Caras).Com este sistema, os usuários só podem comprar passagens mensais entre estações 
adjacentes, o que lhes permite para se mover entre essas estações qualquer número de vezes. O preço do ingresso mensal varia entre
estações, por isso a decisão de quais bilhetes comprar deve ser tomada com cuidado.

![image](prova2.jpg)


Com o plano de metrô anterior, a maneira mais barata de viajar de Picadilly para Victoria e Queensway
era comprar o bilhete mensal Picadilly-Victoria e Queensway-Victoria, por um custo total de $ 12.
Peter é um vendedor, então ele precisa poder viajar para qualquer parte da cidade. Ele quer gastar
com o mínimo de dinheiro possível, e é aqui que você entra em cena. Ele contratou você para escrever um
programa que, dada a lista de estações, as tarifas dos bilhetes mensais entre pares de estações e
a estação mais próxima da casa de Peter, retorna a quantia mínima de dinheiro que Peter tem que gastar para
para viajar para qualquer outra estação. Este programa também deve retornar valor se não for possível ir de
Estação de casa de Peter para todo o resto, porque neste caso Peter vai começar a considerar o uso de ônibus ...

# Entrada

A entrada consiste em vários casos de teste. Um caso de teste começa com uma linha contendo dois inteiros: 1 ≤
s≤400 (o número de estações) e 0 ≤c≤79800 (o número de conexões) separados por um único
espaço. Isso é seguido por slines, cada um contendo o nome de uma estação de metrô. Esses nomes vão
ser cadeias de caracteres (maiúsculas ou minúsculas) sem sinais de pontuação ou caracteres de espaço em branco,
e com comprimento máximo de 10 caracteres. Após os nomes das estações haverá clines
mostrando as conexões entre as estações. Uma conexão permite que as pessoas viajem de uma estação para
o outro em ambas as direções. Cada conexão é representada como duas strings indicando os nomes dos
estações e um número inteiro positivo indicando o custo do bilhete mensal, todos separados por
espaços únicos. Todos os nomes de estações que aparecem nas conexões terão aparecido anteriormente no
lista de estações. As conexões serão todas diferentes e não haverá nenhuma conexão de um
estação para si mesma. O caso de teste terminará com uma linha contendo o nome da estação de onde Peter
precisa viajar para todas as outras estações.

A entrada termina com o caso de teste fantasma '0 0', que não deve ser processado.

# Saída

Para cada caso de teste, a saída será uma linha contendo um número inteiro, o preço mínimo mensal que
Peter tem que pagar para viajar de uma determinada estação para todas as outras, ou "Impossíble" se não for possível
viajar para todas as estações.


Exemplo de Entrada | Exemplo de Saída
------------ | -------------
3 3                       | 12
Picadilly                 | Impossible
Victoria                  |
Queensway                 |
Picadilly Victoria 2      |
Queensway Victoria 10     |
Queensway Picadilly 20    |
Picadilly                 |
4 2                       |
Picadilly                 |
Victoria                  |
Queensway                 |
Temple                    |
Picadilly Victoria 2      |
Temple Queensway 100      |
Temple                    |
0 0                       |
