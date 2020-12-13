/*Scrivere un programma per simulare l'inserimento di un PIN per il telefonino.
  Nella prima fase viene costruito il PIN di riferimento, che deve essere di lunghezza 5 e deve essere
  costruito in modo casuale. Nella seconda fase l’utente inserisce il codice di tentativo e ha al
  massimo 3 tentativi per indovinarlo.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    srand(time(NULL));
    unsigned int pin = 10000 + rand() % 90000, tentativo, i = 0;
    printf("Inserire il PIN (5 cifre): ");
    scanf("%u", &tentativo);
    
    if(tentativo == pin)
        printf("Accesso consentito.\n");
    
    while(i < 2 && tentativo != pin)
    {
        printf("Riprova: ");
        scanf("%u", &tentativo);
        i++;
        if(tentativo == pin)
            printf("Accesso consentito.\n");
        else if(i == 2)
            printf("Hai esaurito i tentativi.\n");
    }
    
    return 0;
}
