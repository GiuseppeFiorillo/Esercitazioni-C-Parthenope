/*Due giocatori si sfidano lanciando un “dado truccato”. Il dado ha dei valori interi nell’intervallo
  [5, 15]. A ogni turno vince il giocatore che ottiene un punteggio maggiore. In caso di parità il punto
  viene assegnato a entrambi. Simulare 10 sfide e visualizzare il giocatore che vince più volte.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    srand(time(NULL));
    unsigned short dado1, dado2, p1 = 0, p2 = 0, i;
    
    for(i = 0; i < 10; i++)
    {
        printf("Giocatore1: premi invio per lanciare il dado.");
        getchar();
        dado1 = 5 + rand() % 11;
        printf("Giocatore2: premi invio per lanciare il dado.");
        getchar();
        dado2 = 5 + rand() % 11;
        if(dado1 > dado2)
        {
            p1++;
            printf("Punteggio G1: %hu\tPunteggio G2: %hu\n", p1, p2);
        }
        else if(dado1 < dado2)
        {
            p2++;
            printf("Punteggio G1: %hu\tPunteggio G2: %hu\n", p1, p2);
        }
        else
        {
            p1++; p2++;
            printf("Punteggio G1: %hu\tPunteggio G2: %hu\n", p1, p2);
        }
        putchar('\n');
    }
    
    if(p1 > p2)
        printf("\nIl vincitore e' il Giocatore 1!\n\n");
    else if(p1 < p2)
        printf("\nIl vincitore e' il Giocatore 2!\n\n");
    else
        printf("\nPareggio!\n\n");
    
    return 0;
}
