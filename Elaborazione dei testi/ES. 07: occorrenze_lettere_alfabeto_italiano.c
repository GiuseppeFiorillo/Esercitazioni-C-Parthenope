/*Sviluppare una function C che, dati come parametri di input un array di char e il suo size,
 determina e restituisce come parametro di output l'array (di size 21) del numero delle
 occorrenze delle 21 lettere dell'alfabeto italiano.*/
#include <stdio.h>
#include <string.h>

void occorrenzeLettereAlfabeto(char[], int, char[]);

int main(int argc, const char * argv[])
{
    char testo[100];
    char occorrenze[21] = {0};
    int n;
    
    printf("Inserire un testo.\n");
    gets(testo);
    n = strlen(testo);
    
    occorrenzeLettereAlfabeto(testo, n, occorrenze);
    printf("A\tB\tC\tD\tE\tF\tG\tH\tI\tL\tM\tN\tO\tP\tQ\tR\tS\tT\tU\tV\tZ\n");
    for(int i = 0; i < 21; ++i)
        printf("%d\t", occorrenze[i]);
    putchar('\n');
    
    return 0;
}

void occorrenzeLettereAlfabeto(char testo[], int size, char occorrenze[21])
{
    int i;
    for(i = 0; i < size; ++i)
    {
        if(testo[i] >= 'a' && testo[i] <= 'i')
            ++occorrenze[testo[i] - 'a'];
        else if(testo[i] >= 'l' && testo[i] <= 'v')
            ++occorrenze[testo[i] - 'a' - 2];
        else if(testo[i] == 'z' || testo[i] == 'Z')
            ++occorrenze[20];
        else if(testo[i] >= 'A' && testo[i] <= 'I')
            ++occorrenze[testo[i] - 'A'];
        else if(testo[i] >= 'L' && testo[i] <= 'V')
            ++occorrenze[testo[i] - 'A' - 2];
    }
}
