/*Sviluppare una function C che, data come parametro di input una stringa che rappresenta un testo
  in italinao, determina e restituisce come parametri di output la parola di lunghezza massima
  contenuta nel testo e la sua lunghezza. Nel testo le parole sono separate da un unico spazio.*/
#include <stdio.h>
#include <string.h>

void parolaPiuLunga(char*, char*, int*);

int main(int argc, const char * argv[])
{
    char testo[100], parola[50];
    int len;
    
    printf("Inserisci un testo.\n");
    gets(testo);
    
    parolaPiuLunga(testo, parola, &len);
    printf("%s\n%d\n", parola, len);
    return 0;
}

void parolaPiuLunga(char* testo, char* parola, int* lunghezza)
{
    char *token;
    token = strtok(testo, " ");
    while(token != NULL)
    {
        int len = strlen(token);
        if(len > *lunghezza)
        {
            *lunghezza = len;
            strcpy(parola, token);
        }
        token = strtok(NULL, " ");
    }
}
