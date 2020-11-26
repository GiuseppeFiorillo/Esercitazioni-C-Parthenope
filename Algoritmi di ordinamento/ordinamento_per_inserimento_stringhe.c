#include <stdio.h>
#include <string.h>

void ord_ins_sP(char**, size_t);

int main(int argc, const char * argv[])
{
    char* elenco[] = {
        "Giuseppe",
        "Anna",
        "Raffaele"
    };
    size_t i;
    
    ord_ins_sP(elenco, 3);
    for(i = 0; i < 3; ++i)
        printf("%s\n", elenco[i]);
    
    return 0;
}

void ord_ins_sP(char** elenco, size_t size)
{
    size_t i;
    int j;
    char* el_da_ins;
    for(i = 1; i < size; ++i)
    {
        el_da_ins = elenco[i];
        j = i-1;
        while(j >= 0 && strcmp(el_da_ins, elenco[j]) < 0 )
        {
            elenco[j+1] = elenco[j];
            --j;
        }
        elenco[j+1] = el_da_ins;
    }
}
