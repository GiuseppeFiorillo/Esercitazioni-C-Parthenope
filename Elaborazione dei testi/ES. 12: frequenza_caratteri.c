/*Sviluppare una function C che, dati come parametri di input un array di char e il suo size,
determina e restituisce come parametri di output il carattere più frequente e il carattere
meno frequente.*/
#include <stdio.h>
#include <string.h>

void ricerca_occorrenze(char[], int, int[]);
void frequenza_caratteri(char[], int, char*, char*);

int main()
{
    char testo[100], meno_frequente, piu_frequente;
    int n; 

    printf("Inserisci un testo.\n");
    gets(testo);
    n = strlen(testo);

    frequenza_caratteri(testo, n, &piu_frequente, &meno_frequente);

    printf("Il carattere meno frequente e': %c\n", meno_frequente);
    printf("Il carattere piu' frequente e': %c\n", piu_frequente);

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

void frequenza_caratteri(char testo[], int size, char* piu_frequente, char* meno_frequente)
{
    int occorrenze[256] = {0}, min, max, i;
    ricerca_occorrenze(testo, size, occorrenze);
    *piu_frequente = testo[0];
    *meno_frequente = testo[0];
    min = max = occorrenze[testo[0]];

    for(i = 1; i < size; ++i)
    {
        if(occorrenze[testo[i]] > max)
        {
            max = occorrenze[testo[i]];
            *piu_frequente = testo[i];
        }
        if(min > occorrenze[testo[i]])
        {
            min = occorrenze[testo[i]];
            *meno_frequente = testo[i];
        }
    }
}
