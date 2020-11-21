/*Sviluppare una function C che, data come parametro di input una stringa che
  rappresenta un testo in italiano, determina e restituisce come parametro di output
  il numero di parole di tre lettere contenute nel testo. Nel testo le parole sono
  separate da un unico spazio.*/
#include <stdio.h>
#include <string.h>

int treLettere(char[]);

int main(int argc, const char * argv[])
{
    char testo[100];
    
    printf("Inserire il testo.\n");
    gets(testo);
    
    printf("%d\n", treLettere(testo));
    return 0;
}

int treLettere(char testo[])
{
    int contatore = 0;
    char *token;
    
    token = strtok(testo, " ");
    while(token != NULL)
    {
        if(strlen(token) == 3)
        {
            if(((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z')) && ((token[1] >= 'a' && token[1] <= 'z') || (token[1] >= 'A' && token[1] <= 'Z')) && ((token[2] >= 'a' && token[2] <= 'z') || (token[2] >= 'A' && token[2] <= 'Z')))
                ++contatore;
        }
            
        token = strtok(NULL, " ");
    }
    
    return contatore;
}
