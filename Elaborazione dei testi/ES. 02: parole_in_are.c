/*Sviluppare una function C che, data come parametro di input una stringa che rappresenta un testo in italiano,
  determina e restituisce come parametro di output il numero di parole che terminano in are contenute nel testo.
  Nel testo le parole sono separate da un unico spazio.*/
#include <stdio.h>
#include <string.h>

int parole_in_are(char*);

int main(int argc, const char * argv[])
{
    char testo[100];
    printf("Inserire il testo:\n");
    gets(testo);
    
    printf("Il numero di parole in are e': %d\n", parole_in_are(testo));
    return 0;
}

int parole_in_are(char *testo)
{
    char separatori[] = {' ', '\n', '\t', '\0'}, *token = NULL;
    int cont = 0;
    token = strtok(testo, separatori);
     
    while(token != NULL)
    {
        printf("%s", token);
        getchar();
        if (strncmp((&token[strlen(token) - 3]), "are", 3) == 0)
            ++cont;
        token = strtok(NULL, separatori);
    }
    return cont;
}
