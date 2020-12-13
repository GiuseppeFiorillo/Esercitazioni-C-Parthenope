// NOTA BENE: Questa versione è stata realizzata solo per soddisfare gli utenti più curiosi. Non sarà necessario fare un programma simile durante la prova
// all'impronta, in quanto l'allocazione dinamica non è argomento del corso di Programmazione I. Se sei interessato alla versione "base" di questo programma
// puoi consultare il file "traccia 20.c".

/*TRACCIA 20
 Dato un elenco (array) di persone partecipanti a un concorso, ordinare l’elenco in ordine alfabetico in
 base al campo cognome. La struttura che identifica il partecipante è
 struct persona {char *nome; char *cognome;};
 typedef struct persona id;
 struct partecipante {id *utente; unsigned short codice;};*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

////////////////STRUCT/////////////
struct persona {
    char* nome;
    char* cognome;
};
typedef struct persona id;

struct partecipante {
    id* utente;
    unsigned short codice;
};
typedef struct partecipante partecipante;

////////////////////FUNZIONI///////////////////////
void scambiare(partecipante*, partecipante*);
size_t min_ind(partecipante*, size_t);
void ord_sel_min(partecipante*, size_t);

int main(int argc, const char * argv[]) 
{
    srand(time(NULL));
    size_t n, i;
    partecipante* elenco;
    id* nominativi;
    printf("Quanti partecipanti vuoi inserire?\n");
    scanf("%zu%*c", &n);
    
    elenco = malloc(n * sizeof(partecipante));
    nominativi = malloc(n * sizeof(partecipante));
    
    if(!elenco || !nominativi) 
    {
        printf("Non riesco ad allocare memoria.\n");
        return 0;
    }
    
    putchar('\n');
    for(i = 0; i < n; i++) 
    {
        nominativi[i].nome = malloc(40 * sizeof(char));
        if(nominativi[i].nome != NULL) 
        {
            printf("Inserisci il nome del %zu partecipante: ", i+1);
            if(fgets(nominativi[i].nome, 40, stdin))
                nominativi[i].nome[strcspn(nominativi[i].nome, "\n")] = 0;
        } 
        else 
        {
            printf("Non riesco ad alloccare memoria per il [%zu] nome.\n", i);
            return 0;
        }
        
        nominativi[i].cognome = malloc(40*sizeof(char));
        if(nominativi[i].cognome != NULL) 
        {
            printf("Inserisci il cognome del %zu partecipante: ", i+1);
            if(fgets(nominativi[i].cognome, 40, stdin))
                nominativi[i].cognome[strcspn(nominativi[i].cognome, "\n")] = 0;
        } 
        else 
        {
            printf("Non riesco ad alloccare memoria per il [%zu] nome.\n", i);
            return 0;
        }
        
        elenco[i].utente = &nominativi[i];
        elenco[i].codice = rand()%1000;
    }
    
    ord_sel_min(elenco, n);

    putchar('\n');
    for(i = 0; i < n; i++) 
    {
        printf("Nome: %s\nCognome: %s\nCodice: %hu\n", elenco[i].utente -> nome, elenco[i].utente -> cognome, elenco[i].codice);
        putchar('\n');
    }
    
    for(i = 0; i < n; i++) 
    {
        free(elenco[i].utente->nome);
        free(elenco[i].utente->cognome);
    }
    
    free(elenco);
    free(nominativi);
    
    return 0;
}

void scambiare(partecipante* partecipante1, partecipante* partecipante2) 
{
    partecipante temp = *partecipante1;
    *partecipante1 = *partecipante2;
    *partecipante2 = temp;
}

size_t min_ind(partecipante* elenco, size_t n) 
{
    size_t i, i_min = 0;
    for(i = 1; i < n; i++)
        if((strcmp(elenco[i_min].utente -> cognome, elenco[i].utente -> cognome)) > 0)
            i_min = i;
    
    return i_min;
}

void ord_sel_min(partecipante* elenco, size_t n) 
{
    size_t i;
    for(i = 0; i < n-1; i++)
        scambiare(&elenco[i], &elenco[min_ind(&elenco[i], n-i) + i]);
}
