#include <stdio.h>
#include <string.h>

int punteggioMatching(char*, char*, size_t);
int bestMatching(char*, char*);

int main() {
    char testo[] = "Questa e' una prova";
    char chiave[] = "provo";
    int indice = bestMatching(chiave, testo);
    for(int i = 0; i < strlen(chiave); ++i)
        putchar(testo[indice+i]);
    putchar('\n');
    return 0;
}

int punteggioMatching(char* chiave, char* testo, size_t size)
{
    size_t i;
    int caratteriUguali;
    for(i = 0; i < size; ++i)
        if(chiave[i] == testo[i])
            ++caratteriUguali;

    return caratteriUguali;
}

int bestMatching(char* chiave, char* testo)
{
    size_t i, n = strlen(chiave), m = strlen(testo);
    int indice = -1, punteggio = 0, punteggioMax = 0;
    for(i = 0; i <= m-n; ++i)
    {
        punteggio = punteggioMatching(chiave, testo + i, n);
        if(punteggio > punteggioMax)
        {
            punteggioMax = punteggio;
            indice = i;
        }
    }
    return indice;
}

/*La complessità di spazio è m+n (l'algoritmo opera in place). La complessità di tempo è T(m,n) = (m-n+1)*n = O(m*n) confronti al più*/
