/*Sviluppare una function C che, dati come parametri di input un array di char e il
  suo size, determina e restituisce come parametro di output il carattere piu`
  frequente.*/
#include <stdio.h>
#include <string.h>

void ricerca_occorrenze(char[], int, int[]);
char carattere_piu_frequente(char[], int);

int main(int argc, const char * argv[])
{
    char testo[200];
    int n;
    
    printf("Inserire un testo.\n");
    gets(testo);
    n = strlen(testo);
    
    printf("Il carattere piu' frequente e': %c\n", carattere_piu_frequente(testo, n));
    return 0;
}

void ricerca_occorrenze(char testo[], int size, int occorrenze[])
{
    int i;
    for(i = 0; i < size; ++i)
        ++occorrenze[testo[i]];
}

char carattere_piu_frequente(char testo[], int size)
{
    char carattere = testo[0];
    int max, occorrenze[256] = {0}, i;
    ricerca_occorrenze(testo, size, occorrenze);
    max = occorrenze[testo[0]];

    for(i = 1; i < size; ++i)
    {
        if(occorrenze[testo[i]] > max)
        {
            max = occorrenze[testo[i]];
            carattere = testo[i];
        }
    }
    return carattere;
}
