/*Sviluppare una function C che, dati come parametri di input un array di char e il
  suo size, determina e restituisce come parametro di un dato logico che indica se il
  testo nell’array è un pangramma, ovvero è un testo che contiene, almeno una
  volta, tutte le 21 lettere dell’alfabeto italiano.*/
#include <stdio.h>
#include <string.h>

void ricerca_occorrenze(char[], int, char[]);
int pangramma(char[], int);

int main(int argc, const char * argv[])
{
    char testo[100];
    int n;
    printf("Inserisci una stringa.\n");
    gets(testo);
    n = strlen(testo);
    
    printf("%d\n", pangramma(testo, n));
    return 0;
}

void ricerca_occorrenze(char testo[], int size, char occorrenze[21])
{
    int i;
    
    for(i = 0; i < size; ++i)
    {
        if(testo[i] >= 'a' && testo[i] <= 'i')
            ++occorrenze[testo[i] - 'a'];
        else if(testo[i] >= 'A' && testo[i] <= 'I')
            ++occorrenze[testo[i] - 'A'];
        else if(testo[i] >= 'l' && testo[i] <= 'v')
            ++occorrenze[testo[i] - 'a' - 2];
        else if(testo[i] >= 'L' && testo[i] <= 'V')
            ++occorrenze[testo[i] - 'A' - 2];
        else if(testo[i] >= 'z' || testo[i] <= 'Z')
            ++occorrenze[20];
    }
}

int pangramma(char testo[], int size)
{
    int i;
    char occorrenze[21] = {0};
    
    ricerca_occorrenze(testo, size, occorrenze);
    for(i = 0; i < 21; ++i)
    {
        if(occorrenze[i] == 0)
            return 0;
    }
    return 1;
}
