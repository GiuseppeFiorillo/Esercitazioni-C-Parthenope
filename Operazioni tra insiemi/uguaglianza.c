#include <stdio.h>

int appartiene_aF(float, float*, int);
int uguaglianza_aF(float*, float*, int);

int main(int argc, const char * argv[])
{
    float A[3] = {1, 2, 3};
    float B[3] = {1, 3, 5};
    if(uguaglianza_aF(A, B, 3))
        printf("I due array sono uguali.\n");
    else
        printf("I due array non sono uguali.\n");
    return 0;
}

int appartiene_aF(float chiave, float* array, int size)
{
    int i;
    for(i = 0; i < size; ++i)
        if(chiave == array[i])
            return 1;
    
    return 0;
}

int uguaglianza_aF(float* array, float* array2, int size)
{
    int i;
    for(i = 0; i < size; ++i)
        if(!appartiene_aF(array[i], array2, size))
            return 0;
    
    return 1;
}
