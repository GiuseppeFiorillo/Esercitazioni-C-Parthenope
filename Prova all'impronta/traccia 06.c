/*Scrivere una funzione che dati in input due array ordinati (rispetto al campo matricola) di elementi della seguente struttura
struct studente {char *nome; char *cognome; int matricola;};
restituisca in output l’array fusione dei due array. La fusione deve avvenire in base al campo matricola*/

#include <stdio.h>

typedef struct {
    char* nome;
    char* cognome;
    int matricola;
} studente;

void fusione(studente[], size_t, studente[], size_t, studente[]);

int main() {
    studente lista1[2] = {
                {"Giuseppe", "Fiorillo", 140},
                {"Mario", "Rossi", 160}
            }, lista2[4] = {
                {"Luigi", "Verdi", 110},
                {"Antonio", "Esposito", 130},
                {"Carlo", "Russo", 189},
                {"Anna", "Cancelli", 210}
            }, lista3[6];
    size_t i_a = 2, i_b = 4, i;
    fusione(lista1, 2, lista2, 4, lista3);
    for(i = 0; i < i_a + i_b; i++)
        printf("Nome: %s Cognome: %s Matricola: %d\n", lista3[i].nome, lista3[i].cognome, lista3[i].matricola);

    return 0;
}

void fusione(studente a[], size_t n_a, studente b[], size_t n_b, studente c[]) {
    size_t i_a = 0, i_b = 0, i_c = 0;
    while(i_a < n_a && i_b < n_b) {
        if(a[i_a].matricola < b[i_b].matricola)
            c[i_c++] = a[i_a++];
        else
            c[i_c++] = b[i_b++];
    }
    while(i_a < n_a)
        c[i_c++] = a[i_a++];
    while(i_b < n_b)
        c[i_c++] = b[i_b++];
}
