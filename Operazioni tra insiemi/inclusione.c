#include <stdio.h>

int appartiene_aF(float, float*, int);
int inclusione_aF(float*, int, float*, int);

int main(int argc, const char * argv[])
{
    float a[] = {1, 8, 3};
    float b[] = {1, 2, 3, 4, 5};
    if(inclusione_aF(a, 3, b, 5))
    {
        printf("L'array I e' incluso nell'array II.\n");
    }
    else
        printf("L'array I NON e' incluso nell'array II.\n");
    return 0;
}

int appartiene_aF(float chiave, float* array, int size)
{
    int i;
    for(i = 0; i < size; ++i)
        if(array[i] == chiave)
            return 1;
    return 0;
}

int inclusione_aF(float* array, int size_1, float* array2, int size_2)
{
    int i = 0, incluso;
    do {
        incluso = appartiene_aF(array[i], array2, size_2);
        ++i;
    } while(incluso && i < size_1);
    
    return incluso;
}
