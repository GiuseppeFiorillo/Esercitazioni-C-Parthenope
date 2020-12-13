/*Scrivere una function C che ha come input i dati che identificano uno studente (nome, cognome,
  matricola) e che restituisce in output una struttura dati opportuna, che contiene i dati di
  identificazione e il libretto universitario con al massimo 20 esami. Ogni esame è caratterizzato da
  denominazione, cfu e voto.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cognome[100];
    int matricola;
} studente;

typedef struct {
    char materia[40];
    int cfu;
    int voto;
} esame;

typedef struct {
    studente alunno;
    esame libretto[20];
} carriera;

void aggiorna_carriera(char*, char*, int, carriera*, int*);

int main(int argc, const char * argv[])
{
    char nome[100], cognome[100];
    int matricola, num_esami = 0;
    carriera stud;
    
    printf("Inserisci il tuo nome: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    printf("Inserisci il tuo cognome: ");
    fgets(cognome, 100, stdin);
    cognome[strcspn(cognome, "\n")] = 0;
    
    printf("Inserisci la tua matricola: ");
    scanf("%d", &matricola);
    
    aggiorna_carriera(nome, cognome, matricola, &stud, &num_esami);
    printf("\nNome: %s\tCognome: %s\tMatricola: %d\n", stud.alunno.nome, stud.alunno.cognome, stud.alunno.matricola);
    
    if(num_esami > 0)
    {
        for(size_t i = 0; i < num_esami; i++)
            printf("Voto %s (%d CFU): %d\n", stud.libretto[i].materia, stud.libretto[i].cfu, stud.libretto[i].voto);
    }
    else
        printf("Non hai dato alcun esame.\n");
    
    return 0;
}

void aggiorna_carriera(char *nome, char *cognome, int matricola, carriera *stud, int *num_esami)
{
    studente dati;
    size_t i = 0;
    strcpy(dati.nome, nome);
    strcpy(dati.cognome, cognome);
    dati.matricola = matricola;
    
    stud->alunno = dati;
    
    printf("Quanti esami hai dato?\n");
    scanf("%d%*c", num_esami);
    for(i = 0; i < *num_esami; i++)
    {
        printf("Inserire il nome della materia del %zu esame: ", i+1);
        fgets(stud->libretto[i].materia, 40, stdin);
        stud->libretto[i].materia[strcspn(stud->libretto[i].materia, "\n")] = 0;
        
        printf("Inserire il voto di %s: ", stud->libretto[i].materia);
        scanf("%d", &stud->libretto[i].voto);
        
        printf("Inserire il numero di CFU: ");
        scanf("%d%*c", &stud->libretto[i].cfu);
        putchar('\n');
    }
}
