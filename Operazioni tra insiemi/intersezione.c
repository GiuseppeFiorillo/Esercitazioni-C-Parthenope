#include <stdio.h>

void intersezione_aF(float*, int, float*, int, float*, int*);
int appartiene_aF(float chiave, float array[], int size);

int main(int argc, const char * argv[]) 
{
    float a[] = {0.0, 1.2, 1.3, 1.5, 1.6};
    float b[] = {0.0, 1.2, 1.5, 1.6};
    float c[9];
    int n_c;
    intersezione_aF(a, 5, b, 4, c, &n_c);
    for(int i = 0; i < n_c; ++i)
        printf("%f\n", c[i]);
    return 0;
}

int appartiene_aF(float chiave, float array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
        if(chiave == array[i])
            return 1;
    return 0;
}

void intersezione_aF(float* a, int n_a, float* b, int n_b, float* c, int* n_c)
{
    int i, i_c;
    i_c = 0;
    for(i = 0; i < n_a; ++i)
    {
        if(appartiene_aF(a[i], b, n_b))
        {
            c[i_c] = a[i];
            ++i_c;
        }
    }
    *n_c = i_c;
}
