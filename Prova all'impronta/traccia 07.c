/*Scrivere una funzione che dati in input due array di strutture del seguente tipo
struct prodotto {char *nome; int codice; double prezzo;};
restituisce in output 1 se i due array di struct sono uguali, 0 se non lo sono. Si noti
che due dati struct sono uguali se sono uguali tutti i loro campi.*/
#include <stdio.h>

typedef struct {
    char *nome;
    int codice;
    double prezzo;
} prodotto;

int uguale(prodotto[], size_t, prodotto[], size_t);
int uguaglianza(prodotto, prodotto);

int main() 
{
    prodotto lista1[2] = {
            {"Nintendo DS", 100, 250},
            {"Sony PSP", 101, 300}
    }, lista2[2] = {
            {"Nintendo DS", 100, 250},
            {"Sony PSP", 101, 300}
    };
    if(uguale(lista1, 2, lista2, 2))
        printf("Le struct sono uguali.\n");
    else
        printf("Le struct sono diverse.\n");
    
    return 0;
}

int uguale(prodotto lista1[], size_t n, prodotto lista2[], size_t m) 
{
    size_t i;
    if(n != m)
        return 0;
    for(i = 0; i < n; i++) 
    {
        if(!(uguaglianza(lista1[i], lista2[i])))
            return 0;
    }
    return 1;
}

int uguaglianza(prodotto prodotto1, prodotto prodotto2) {
    if(prodotto1.nome == prodotto2.nome &&
       prodotto1.codice == prodotto2.codice &&
       prodotto1.prezzo == prodotto2.prezzo)
        return 1;

    return 0;
}
