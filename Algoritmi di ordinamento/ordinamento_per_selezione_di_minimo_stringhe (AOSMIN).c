#include <stdio.h>
#include <string.h>

size_t min_ind_sP(char**, int);
void scambiare_sP(char**, char**);
void ord_sel_min_sP(char**, size_t);

int main(int argc, const char * argv[])
{
    char *elenco[] = {
        "Ivan",
        "Angelo",
        "Raffaele"
    };
    
    ord_sel_min_sP(elenco, 3);
    for(int i = 0; i < 3; ++i)
        printf("%s\n", elenco[i]);
    
    return 0;
}

size_t min_ind(char** elenco, int n)
{
    size_t i, i_min = 0;
    for(i = 0; i < n; ++i)
    {
        if(strcmp(elenco[i], elenco[i_min]) < 0)
            i_min = i;
    }
    return i_min;
}

void scambiare_sP(char** a, char** b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void ord_sel_min_sP(char** elenco, size_t n)
{
    size_t i;
    for(i = 0; i < n - 1; ++i)
        scambiare_sP(&elenco[i], &elenco[min_ind(&elenco[i], n - i) + i]);
}
