#include <stdio.h>
#include <string.h>

size_t max_ind(char**, size_t);
void scambiare(char**, char**);
void ord_sel_max(char**, size_t);

int main(int argc, const char * argv[])
{
    char* elenco[] = {
        "Giuseppe",
        "Anna",
        "Samuele",
        "Antonio"
    };
    
    ord_sel_max(elenco, 4);
    for(int i = 0; i < 4; ++i)
        puts(elenco[i]);

    return 0;
}

size_t max_ind(char** elenco, size_t size)
{
    size_t i, i_max = 0;
    for(i = 1; i < size; ++i)
        if(strcmp(elenco[i], elenco[i_max]) > 0)
            i_max = i;
    
    return i_max;
}
void scambiare(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void ord_sel_max(char** elenco, size_t size)
{
    size_t i;
    for(i = size - 1; i > 0; --i)
        scambiare(&elenco[i], &elenco[max_ind(&elenco[0], i+1)]);
}
