/*Sviluppare una function C che, data come parametro di input una stringa che rappresenta un
  testo in italiano, determina e restituisce come parametro di output il numero di parole di tre
  lettere contenute nel testo. Nel testo le parole sono separate da un unico spazio.*/

#include <stdio.h>
#include <ctype.h>

#define OUT 0
#define IN 1

int occorrenzeTreLettere(char[]);

int main(int argc, const char * argv[])
{
    char *frase = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer non lacus dictum, tincidunt ligula vel, lacinia mi. In eu felis erat. Nulla scelerisque odio et lacus euismod, vel eleifend dui tincidunt. Nulla auctor viverra sem ut imperdiet. In nisl justo, luctus vel varius sed, ultricies sit amet mauris. Maecenas non gravida lorem. Praesent egestas id erat ut aliquam.";
    
    printf("%d.\n", occorrenzeTreLettere(frase));
    return 0;
}

int occorrenzeTreLettere(char testo[])
{
    int occorrenze, state, nc, i;
    state = OUT;
    nc = occorrenze = 0;
    
    for(i = 0; testo[i] != '\0'; ++i)
    {
        if(!isalpha(testo[i]))
            state = OUT;
        
        else if(state == OUT)
            state = IN;
    /*-----------------------------------------------------------------------------*/
        if (state == IN)
            ++nc;
    /*-----------------------------------------------------------------------------*/
        else
        {
            if(nc == 3)
                ++occorrenze;
            
            nc = 0;
        }
    }   //fine del ciclo
    
    if(state == IN)
        if(nc == 3)
            ++occorrenze;
    
    return occorrenze;
}
