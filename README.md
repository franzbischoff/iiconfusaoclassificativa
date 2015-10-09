# iiconfusaoclassificativa
Olimpíadas Nacionais de Informática

http://www.dcc.fc.up.pt/oni/problemas/2015/qualificacao/probA.html

Problema A - Confusão Classificativa

Está a decorrer o mais importante concurso de programação do país. Os N concorrentes têm de resolver um conjunto de P problemas e em cada um deles obtêm uma pontuação que vai de 0 a 100. A pontuação total de um concorrente é a soma das suas pontuações em cada problema.

O sistema de avaliação automática usado funcionou na perfeição para obter os pontos cada problema, mas o júri esqueceu-se de implementar o módulo que produzia a classificação... Será que podes ajudar?

O Problema

Dado um conjunto de N concorrentes, com os seus respectivos nomes e pontuações em P problemas, a tua tarefa é produzir uma classificação ordenada por ordem decrescente dos pontos. Em caso de empate os concorrentes devem vir por ordem alfabética crescente do seu nome.

Input

Na primeira linha vêm dois inteiros N e P, representando respectivamente o número de concorrentes e o número de problemas. Seguem-se exactamente N linhas, cada uma contendo primeiro o nome de um concorrente (uma palavra de tamanho inferior a 20 constituída unicamente por letras minúsculas), seguido de um espaço, seguido de exactamente P números inteiros (entre 0 e 100) indicando a pontuação em cada um dos problemas.

Output

O output deve conter exactamente N linhas contendo a classificação dos concorrentes ordenada por ordem descendente da sua pontuação. Em caso de empate deves ordenar por ordem alfabética crescente. Cada uma das linhas deve conter primeiro o nome do concorrente, seguido de um espaço e finalmente da sua respectiva pontuação total.

Restrições

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:

1 ≤ N ≤ 50 000	     	Número de Concorrentes
1 ≤ P ≤ 10	     	Número de Problemas
Nota sobre a avaliação

Para um conjunto de casos de teste valendo 35% dos pontos, não existem empates e N ≤ 100.

Para um conjunto de casos de teste valendo 65% dos pontos, N ≤ 5 000.

Exemplo de Input 1

4 3
manuel 10 50 20
joao 20 30 20
rita 20 100 0
ana 0 0 10
Exemplo de Output 1

rita 120
manuel 80
joao 70
ana 10
Exemplo de Input 2

5 2
pedro 10 20
joao 20 10
miguel 0 30
joana 100 100
cristina 5 5
Exemplo de Output 2

joana 200
joao 30
miguel 30
pedro 30
cristina 10
Qualificação para a final das ONI'2015
(15/03 a 17/03 de 2015)
