/*Sviluppare una function C che, dati come parametri di input un array di char e il suo
size, determina e restituisce come parametro di output il carattere meno frequente.*/
#include <stdio.h>
#include <string.h>

void ricerca_occorrenze(char[], int, int[]);
char carattere_meno_frequente(char[], int);

int main()
{
    char testo[100];
    int n;

    printf("Inserisci un testo.\n");
    gets(testo);
    n = strlen(testo);

    printf("Il carattere meno frequente e': %c\n", carattere_meno_frequente(testo, n));

    return 0;
}

void ricerca_occorrenze(char testo[], int size, int occorrenze[])
{
    int i;
    for (i = 0; i < size; ++i)
    {
        ++occorrenze[testo[i]];
    }
}

char carattere_meno_frequente(char testo[], int size)
{
    char carattere = testo[0];
    int min, occorrenze[256] = {0}, i;
    ricerca_occorrenze(testo, size, occorrenze);
    min = occorrenze[testo[0]];

    for(i = 1; i < size; ++i)
    {
        if(min > occorrenze[testo[i]])
        {
            min = occorrenze[testo[i]];
            carattere = testo[i];
        }
    }
    return carattere;
}
