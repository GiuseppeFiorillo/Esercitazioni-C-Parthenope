/*Sviluppare una function C che, dati come parametri di input un array di char e il
  suo size, determina e restituisce come parametro di output il carattere piu`
  frequente.*/
#include <stdio.h>
#include <string.h>

char occorrenza_piu_frequente(char[], int);

int main(int argc, const char * argv[])
{
    char testo[200];
    int n;
    
    printf("Inserire un testo.\n");
    gets(testo);
    n = strlen(testo);
    
    printf("Il carattere piu' frequente e': %c\n", occorrenza_piu_frequente(testo, n));
    return 0;
}

char occorrenza_piu_frequente(char testo[], int size)
{
    int cont = 0, max = 0, i, j;
    char carattere = ' ';
    
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(array[i] == array[j] && array[i])
                ++cont;
        }
        if(cont >= max)
        {
            max = cont;
            carattere = array[i];
        }
        cont = 0;
    }
    return carattere;
}
