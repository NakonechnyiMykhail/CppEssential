#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Максимальное количество избирателей и кандидатов
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Предпочтения [i] [j] - это j-е предпочтение для избирателя i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

//У кандидатов есть имя, подсчет голосов, исключенный статус
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Массив кандидатов
candidate candidates[MAX_CANDIDATES];

// Количество избирателей и кандидатов
int voter_count;
int candidate_count;

// Функциональные прототипы
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Проверить на недопустимое использование
    if (argc & lt; 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Заполните массив кандидатов
    candidate_count = argc - 1;
    if (candidate_count & gt; MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i & lt; candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count & gt; MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Продолжайте запрашивать голоса
    for (int i = 0; i & lt; voter_count; i++)
    {

        // Запрос для каждого тура
        for (int j = 0; j & lt; candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Записать голосование, если оно не недействительно
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Продолжайте проводить второй тур, пока не определится победитель
    while (true)
    {
        // Подсчитайте количество голосов с учетом оставшихся кандидатов
        tabulate();

        // Проверить, выиграны ли выборы
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Исключить кандидатов, занявших последнее место
        int min = find_min();
        bool tie = is_tie(min);

        // Если ничья, все выигрывают
        if (tie)
        {
            for (int i = 0; i & lt; candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Устранение любого с минимальным количеством голосов
        eliminate(min);

        // Сбросить счетчик голосов до нуля
        for (int i = 0; i & lt; candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Записать предпочтение, если голосование действительное
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i & lt; candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Подсчитайте количество голосов за неотбывших кандидатов
void tabulate(void)
{
    int i = 0;

    for (int k = 0; k & lt; voter_count; k++) // для учета предпочтений всех избирателей
    {
        i = preferences[k][0];

        if (candidates[i].eliminated == false)
        {
            candidates[i].votes++;
            continue;
        }

        for (int l = 0; l & lt; 2; l++) // если исключен кандидат в качестве первого предпочтения
        {
            i = preferences[k][l];

            if (candidates[i].eliminated == true)
            {
                int j = 0;
                j = preferences[k][l + 1];
                candidates[j].votes++;
            }
        }
    }

    return;
}
// Выведите победителя выборов, если он есть
bool print_winner(void)
{
    for (int i = 0; i & lt; candidate_count; i++)
    {
        if (candidates[i].votes & gt; (voter_count / 2))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Вернуть минимальное количество голосов, которое имеет оставшийся кандидат.
int find_min(void)
{
    int minvotes = voter_count;
    for (int i = 0; i & lt; candidate_count; i++)
    {
        if (candidates[i].eliminated == false & amp; &amp; candidates[i].votes &lt; = minvotes)
        {
            minvotes = candidates[i].votes;
        }
    }
    return minvotes;
    return 0;
}

// Вернуть true, если выборы равны между всеми кандидатами, иначе false.
bool is_tie(int min)
{
    for (int i = 0; i & lt; candidate_count; i++)
    {
        if (candidates[i].eliminated == false & amp; &amp; candidates[i].votes == min)
        {
        }
        else if (candidates[i].eliminated == true)
        {
            continue;
        }
        else if (candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Исключить кандидата (или кандидатов) на последнем месте
void eliminate(int min)
{
    for (int i = 0; i & lt; candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}