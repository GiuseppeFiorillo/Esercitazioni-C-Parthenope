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
    size_t i;
    partecipante elenco[3];
    id nominativi[3];

    nominativi[0].nome = "Mario";
    nominativi[0].cognome = "Rossi";
    elenco[0].utente = &nominativi[0];
    elenco[0].codice = rand()%1000;
    
    nominativi[1].nome = "Giuseppe";
    nominativi[1].cognome = "Fiorillo";
    elenco[1].utente = &nominativi[1];
    elenco[1].codice = rand()%1000;
    
    
    nominativi[2].nome = "Luigi";
    nominativi[2].cognome = "Verdi";
    elenco[2].utente = &nominativi[2];
    elenco[2].codice = rand()%1000;
    
    ord_sel_min(elenco, 3);

    putchar('\n');
    for(i = 0; i < 3; i++)
    {
        printf("Nome: %s\nCognome: %s\nCodice: %hu\n", elenco[i].utente -> nome, elenco[i].utente -> cognome, elenco[i].codice);
        putchar('\n');
    }
    
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
