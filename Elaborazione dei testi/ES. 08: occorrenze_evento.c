/*Sviluppare una function C che, dati come parametri di input un array di char e il suo
  size, determina e restituisce come parametro di output l'array (di size 21) del numero
  delle occerrenze dell'evento a precede ognuna delle 21 lettere dell'alfabeto italiano
  (cioè il numero delle volte in cui accade che a precede a, il numero di volte in cui
  accade che a precede b, il numero di volte in cui accade che a precede c, ...).*/

#include <stdio.h>
#include <string.h>

void stampaArray(char[], int);
void occorrenzeEvento(char[], int, char[]);

int main(int argc, const char * argv[])
{
    char testo[100];
    char occorrenze[21] = {0};
    int n;
    printf("Inserisci il testo.\n");
    gets(testo);
    n = strlen(testo);
    occorrenzeEvento(testo, n, occorrenze);
    
    printf("A\tB\tC\tD\tE\tF\tG\tH\tI\tL\tM\tN\tO\tP\tQ\tR\tS\tT\tU\tV\tZ\n");
    stampaArray(occorrenze, 21);
    putchar('\n');
    
    return 0;
}

void stampaArray(char testo[], int size)
{
    for(int i = 0; i < size; ++i)
        printf("%d\t", testo[i]);
}

void occorrenzeEvento(char testo[], int size, char occorrenze[21])
{
    for(int i = 1; i < size; ++i)
    {
        if(testo[i-1] == 'a' || testo[i-1] == 'A')
        {
            if(testo[i] >= 'a' && testo[i] <= 'i')
                ++occorrenze[testo[i] - 'a'];
            else if(testo[i] >= 'A' && testo[i] <= 'i')
                ++occorrenze[testo[i] - 'A'];
            else if(testo[i] >= 'l' && testo[i] <= 'v')
                ++occorrenze[testo[i] - 'a' - 2];
            else if(testo[i] >= 'L' && testo[i] <= 'V')
                ++occorrenze[testo[i] - 'A' - 2];
            else if(testo[i] == 'z' || testo[i] == 'Z')
                ++occorrenze[20];
        }
    }
}
