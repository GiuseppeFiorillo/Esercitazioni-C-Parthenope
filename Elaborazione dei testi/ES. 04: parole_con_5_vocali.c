/*Sviluppare una function C che, dato come parametro di input una stringa che rappresenta
  un testo in italiano, determina e restituisce come parametri di output il numero delle
  parole contenute nel testo che hanno almeno 5 vocali. Nel testo le parole sono separate
  da un unico spazio.*/

#include <stdio.h>
#include <string.h>

int contaParoleCon5Vocali(char[]);

int main(int argc, const char * argv[])
{
    char testo[100];
    int n;
    
    printf("Inserisci un testo.\n");
    gets(testo);
    n = strlen(testo);
    
    printf("%d\n", contaParoleCon5Vocali(testo));
    
    return 0;
}

int contaParoleCon5Vocali(char testo[])
{
    char *token;
    int cont = 0, contatoreVocali = 0;
    token = strtok(testo, " ");
    
    while(token != NULL)
    {
        for(int i = 0; token[i] != '\0'; ++i)
        {
            if(token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u')
                ++contatoreVocali;
        }
        if(contatoreVocali >= 5)
            ++cont;
        contatoreVocali = 0;
        
        token = strtok(NULL, " ");
    }
    
    return cont;
}
