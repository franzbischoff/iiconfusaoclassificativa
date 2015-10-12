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

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

bool fncomp(pair<uint32_t, string> lhs, pair<uint32_t, string> rhs);
void print_help();

/*
 *
 */
int main(int argc, char** argv)
{
    uint32_t i, j, k;
    uint32_t competitors;
    uint32_t problems;
    string name(20, ' ');
    uint32_t score;
    char arg;
    bool interactive = false;
    bool dups = false;
    bool(*fn_pt)(pair<uint32_t, string>, pair<uint32_t, string>) = fncomp;

    /**
     * Create a set (or multiset for duplicated keys) of a paired value, score - name.
     * This allow us to use a personalized function to define how the data is sorted
     *
     * Why use set? Set uses a binary three implementation. This method is fast for inserting
     * ordered elements, but is not optimized for retrieving random elements.
     *
     * Since we won't use random access to output the results, this is the best approach.
     *
     * We could think in using map or multimap for this purpose as we need a "key" (the score)
     * and a "value" the name. It indeed also uses a binary three implementation and sorts the
     * elements by "key", but does not allow to set a proper rule for sorting the values.
     * Most implementations keep the values in the inserted order. So to achieve the purpose
     * of this exercise, we would have to sort the grouped (by key) values during the output time.
     *
     */

    set < pair<uint32_t, string>, bool(*)(pair<uint32_t, string>, pair<uint32_t, string>) > scoreset(fn_pt);
    multiset < pair<uint32_t, string>, bool(*)(pair<uint32_t, string>, pair<uint32_t, string>) > scoremultiset(fn_pt);


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
                case 'd':
                    dups = true;
                    break;
                case 'h':
                    print_help();
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

        for (j = 0, score = 0; j < problems; j++)
        {
            string t;
            cin >> t;

            score += atoi(t.c_str());
        }

        // use multiset to allow duplicated keys
        if (dups)
        {
            scoremultiset.insert(pair<uint32_t, string>(score, name));
        }
        else
        {
            scoreset.insert(pair<uint32_t, string>(score, name));
        }

    }

    if (dups)
    {
        for (multiset< pair<uint32_t, string> >::reverse_iterator it = scoremultiset.rbegin(); it != scoremultiset.rend(); ++it)
            cout << (*it).second << " " << (*it).first << '\n';
    }
    else
    {
        for (set< pair<uint32_t, string> >::reverse_iterator it = scoreset.rbegin(); it != scoreset.rend(); ++it)
            cout << (*it).second << " " << (*it).first << '\n';
    }

    return 0;
}

/**
 * This function defines how data is sorted.
 *
 * First we check if the score (first) is equal. If so, we order the name (second) by alphabetical order.
 *
 * As the final output is in inverse order (first the larger score) we need to sort the name by reverse order.
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool fncomp(pair<uint32_t, string> lhs, pair<uint32_t, string> rhs)
{
    if (lhs.first == rhs.first)
    {
        // sort in reverse alphabetical order
        return rhs.second.compare(lhs.second) < 0;
    }
    else
    {
        // is the left smaller than the right?
        return lhs.first < rhs.first;
    }
}

void print_help()
{
    cout << "CONFUSAO CLASSIFICATIVA - Introducao a informatica" << endl << endl;
    cout << "SYNOPSIS" << endl << endl;
    cout << "\tPrints the scores of several competitors, inversely ordered by score, followed by alphabetical order." << endl << endl;

    cout << "DESCRIPTION" << endl << endl;
    cout << "\tINPUT:" << endl << "\t\tThis program uses the stdin. Type 'program < input.txt' for file input or use the -i argument for interactive mode." << endl << endl;

    cout << "\tFORMAT:" << endl << "\t\tThe first line holds an integer 'N' with the number of competitors and an integer 'P' with the number of problems. These numbers must be 1 <= N <= 50,000 and 1 <= P <= 10." << endl;
    cout << "\t\tThe following 'N' lines are composed of an unique string with the first name of the competitor, followed by 'P' integers with the score of each test from 0 to 100." << endl << endl;

    cout << "\tOUTPUT:" << endl << "\t\tThe output is composed of N lines. The first column is the name of the competitor and the second column is the score." << endl << endl;

    cout << "OPTIONS" << endl << endl;
    cout << "\t-h This help." << endl << endl;
    cout << "\t-i Interactive mode." << endl << endl;
    cout << "\t-d Allow duplicated names." << endl << endl;

    cout << "AUTHOR" << endl << endl;
    cout << "\tFrancisco Bischoff." << endl << endl;
}
