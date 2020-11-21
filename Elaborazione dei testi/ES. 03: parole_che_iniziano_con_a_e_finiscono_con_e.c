/*Sviluppare una function C che, data come parametro di input una stringa che rappresenta un testo in italiano, 
  determina e restituisce come parametro di output il numero di parole che iniziano con a e terminano con e contenute 
  nel testo. Nel testo le parole sono separate da un unico spazio.*/
#include <stdio.h>
#include <string.h>

int contatore(char[]);

int main(int argc, const char * argv[])
{
    char testo[100];
    
    printf("Inserisci il testo.\n");
    gets(testo);
    printf("Il numero di parole che inizia con 'a' e finisce con 'e' e': %d\n", contatore(testo));
    
    return 0;
}

int contatore(char testo[])
{
    int contatore = 0;
    char *token;
    token = strtok(testo, " ");
    
    while(token != NULL)
    {
        int len = strlen(token);
        if(token[0] == 'a' && token[len-1] == 'e')
            ++contatore;
        token = strtok(NULL, " ");
    }
    
    return contatore;
}
