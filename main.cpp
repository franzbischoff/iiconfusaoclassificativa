/*
 * File:   main.cpp
 * Author: Francisco
 *
 * Created on 9 de Outubro de 2015, 18:44
 */

/*
 * O Problema
 * Dado um conjunto de N concorrentes, com os seus respectivos nomes e pontuações em P problemas, a tua
 * tarefa é produzir uma classificação ordenada por ordem decrescente dos pontos. Em caso de empate os
 * concorrentes devem vir por ordem alfabética crescente do seu nome.
 *
 * Input
 * Na primeira linha vêm dois inteiros N e P, representando respectivamente o número de concorrentes e o
 * número de problemas. Seguem-se exactamente N linhas, cada uma contendo primeiro o nome de um concorrente
 * (uma palavra de tamanho inferior a 20 constituída unicamente por letras minúsculas), seguido de um espaço,
 * seguido de exactamente P números inteiros (entre 0 e 100) indicando a pontuação em cada um dos problemas.
 *
 * Output
 * O output deve conter exactamente N linhas contendo a classificação dos concorrentes ordenada por ordem
 * descendente da sua pontuação. Em caso de empate deves ordenar por ordem alfabética crescente. Cada uma
 * das linhas deve conter primeiro o nome do concorrente, seguido de um espaço e finalmente da sua
 * respectiva pontuação total.
 *
 * Restrições
 * São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:
 * 1 ≤ N ≤ 50 000       Número de Concorrentes
 * 1 ≤ P ≤ 10           Número de Problemas
 *
 */

/**
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
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

/*
 *
 */
int main(int argc, char** argv)
{
    uint32_t i, j, k;
    uint32_t competitors;
    uint32_t problems;
    string name(20, ' ');
    uint8_t score[10];
    char arg;
    bool interactive = true;

    for (i = 1; i < argc; i++)
    {
        if (*(argv + i)[0] == '-')
        {
            k = strlen(*(argv + i) + 1);

            for (j = 0; j < k; j++)
            {
                arg = *(*(argv + i) + 1 + j);

                switch (arg)
                {
                case 'i':
                    interactive = true;
                    break;
                case 'h':
                    //print_help();
                    return 0;
                    break;
                default:
                    break;
                }
            }
        }
    }

    if (interactive)
        cout << "Insert the number of competitors and problems [e.g.: 4 3] : " << endl;
    cin >> competitors >> problems;

    for (i = 0; i < competitors; i++)
    {
        if (interactive)
            cout << "Insert the competitor's name and the scores [e.g.: joao 1 2 3]: " << endl;

        cin >> name;

        for (j = 0; j < problems; j++)
        {
            cin >> score[j];
        }

        //        calc_freq(a, b);
        //
        //        print_most_frequent();
    }

    cout << name << " " << score[0] << " " << score[1] << " " << score[2] << endl;

    return 0;
}

void print_help()
{
    cout << "CONFUSAO CLASSIFICATIVA - Introducao a informatica" << endl << endl;
    cout << "SYNOPSIS" << endl << endl;
    cout << "\tPrints the most frequent digits in a given interval." << endl << endl;

    cout << "DESCRIPTION" << endl << endl;
    cout << "\tINPUT:" << endl << "\t\tThis program uses the stdin. Type 'program < input.txt' for file input or use the -i argument for interactive mode." << endl << endl;

    cout << "\tFORMAT:" << endl << "\t\tThe first line holds an integer 'N' with the number of intervals do consider. This number must be 1 <= N <= 1,000." << endl;
    cout << "\t\tThe following lines are composed by two integers 'A' and 'B'. These numbers must be 1 <= A <= B <= 1,000,000,000." << endl << endl;

    cout << "\tOUTPUT:" << endl << "\t\tThe output is composed of N lines. The first number tells the frequency and the following numbers the digits that are most frequent." << endl << endl;

    cout << "OPTIONS" << endl << endl;
    cout << "\t-h This help." << endl << endl;
    cout << "\t-i Interactive mode." << endl << endl;

    cout << "AUTHOR" << endl << endl;
    cout << "\tFrancisco Bischoff." << endl << endl;
}
