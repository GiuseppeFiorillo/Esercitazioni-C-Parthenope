/*Scrivere una funzione che dati in input due array di strutture del seguente tipo
struct prodotto {char *nome; int codice; double prezzo;};
restituisce in output 1 se i due array di struct sono uguali, 0 se non lo sono. Si noti
che due dati struct sono uguali se sono uguali tutti i loro campi.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int codice;
    double prezzo;
} prodotto;

int uguale(prodotto*, size_t, prodotto*, size_t);
int uguaglianza(prodotto, prodotto);

int main() 
{
    prodotto *lista1 = NULL, *lista2 = NULL;   //Dichiarazione a puntatori di due array del tipo prodotto (struct)
    size_t size1, size2;    //Dichiarazione dei size delle due strutture
    
    //Scanf dei size
    printf("Quanti elementi vuoi inserire nella prima lista?\nNumero elementi: ");
    scanf("%zu", &size1);
    printf("Quanti elementi vuoi inserire nella seconda lista?\nNumero elementi: ");
    scanf("%zu%*c", &size2);    //utilizziamo %*c perché scanf dopo aver preso in input il secondo size ci
    // restituirà una newline, la cosa entrerà in conflitto col primo fgets successivo. Con %*c noi è come se
    // "prendessimo" questo newline ma senza assegnarlo a nessuna variabile.
    
    //Allocazione delle strutture in memoria
    lista1 = malloc(size1 * (sizeof(prodotto)));
    if(lista1 == NULL) 
    {
        printf("Non riesco ad allocare sufficiente memoria.\n");
        return 0;
    }
    
    lista2 = malloc(size2 * (sizeof(prodotto)));
    if(lista2 == NULL) 
    {
        printf("Non riesco ad allocare sufficiente memoria.\n");
        return 0;
    }
        
    printf("\n\nPRIMA LISTA:\n");
    for(size_t i = 0; i < size1; i++) 
    {
        lista1[i].nome = malloc(40 * sizeof(char));
        
        if(lista1[i].nome == NULL) 
        {
            printf("Non riesco ad allocare sufficiente memoria.\n");
            return 0;
        }
        
        printf("Inserire il %zu elemento: ", i+1);
        fgets(lista1[i].nome, 40, stdin);
        lista1[i].nome[strcspn(lista1[i].nome, "\n")] = 0;
        
        printf("Inserire il prezzo: ");
        scanf("%lf%*c", &lista1[i].prezzo);
        
        lista1[i].codice = i;
    }
    
    printf("\n\nSECONDA LISTA\n");
    for(size_t i = 0; i < size2; i++) 
    {
        lista2[i].nome = malloc(40 * sizeof(char));
        
        if(lista2[i].nome == NULL) 
        {
            printf("Non riesco ad allocare sufficiente memoria.\n");
            return 0;
        }
        
        printf("Inserire il %zu elemento: ", i+1);
        fgets(lista2[i].nome, 40, stdin);
        lista2[i].nome[strcspn(lista2[i].nome, "\n")] = 0;
        
        printf("Inserire il prezzo: ");
        scanf("%lf%*c", &lista2[i].prezzo);
        
        lista2[i].codice = i;
    }


    if(uguale(lista1, size1, lista2, size2))
        printf("\nLe liste sono uguali.\n");
    else
        printf("\nLe liste non sono uguali.\n");
    
    //Deallocazione di tutte le strutture dati.
    for(size_t i = 0; i < size1; i++)
        free(lista1[i].nome);
    for(size_t i = 0; i < size2; i++)
        free(lista2[i].nome);
    
    free(lista1);
    free(lista2);
    
    return 0;
}

int uguale(prodotto *lista1, size_t n, prodotto *lista2, size_t m) 
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

int uguaglianza(prodotto prodotto1, prodotto prodotto2) 
{
    if((strcmp(prodotto1.nome, prodotto2.nome) == 0) &&
       prodotto1.codice == prodotto2.codice &&
       prodotto1.prezzo == prodotto2.prezzo)
        return 1;

    return 0;
}
