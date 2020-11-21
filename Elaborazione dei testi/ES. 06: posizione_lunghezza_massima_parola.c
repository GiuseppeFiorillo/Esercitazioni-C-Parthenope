/*Sviluppare una function C che, dato come parametro di input una stringa che
  rappresenta un testo in italiano, determina e restituisce come parametri di
  output la parola di lunghezza massima contenuta nel testo e la posizione di inizio
  della parola nella stringa. Nel testo le parole sono separate da un unico spazio.*/
#include <stdio.h>
#include <string.h>

void parolaPiuLunga(char*, char*, int*);

int main(int argc, const char * argv[])
{
    char testo[100];
    char parola[100];
    int posizione;
    
    printf("Inserisci il testo.\n";
    gets(testo);
    
    parolaPiuLunga(testo, parola, &posizione);
    printf("%s\n%d\n", parola, posizione);
    
    return 0;
}

void parolaPiuLunga(char* testo, char* parolaLunga, int* posizione)
{
    char *token;
    int max = 0, sum = -1;
    token = strtok(testo, " ");
    
    while(token != NULL)
    {
        int len = strlen(token);
        sum += len + 1;
        if(len > max)
        {
            max = len;
            strcpy(parolaLunga, token);
            *posizione = sum - len;
        }
        token = strtok(NULL, " ");
    }
}
