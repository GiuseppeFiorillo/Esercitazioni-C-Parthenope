//L'unione dei due insieme è l'unione dei due array ma senza elementi ripetuti.
//N.B.: In questo file sono presenti le funzioni sia per quanto riguarda gli array di int che gli array di float.

#include <stdio.h>

void scan_array_int(int*, int);
void scan_array_float(float*, int);
int appartiene(int, int[], int);
int appartiene_aF(float, float[], int);
void unione(int*, int, int*, int, int*, int*);
void unione_aF(float*, int, float*, int, float*, int*);

int main(int argc, const char * argv[]) 
{
    int n_a, n_b, n_c, i;
    printf("Inserire la dimensione del primo array: ");
    scanf("%d", &n_a);
    printf("Inserire la dimensione del secondo array: ");
    scanf("%d", &n_b);
    float A[n_a], B[n_b], C[n_a];
    printf("\nInserire gli elementi del primo array.\n");
    scan_array_float(A, n_a);
    printf("\nInserire gli elementi del secondo array.\n");
    scan_array_float(B, n_b);
    putchar('\n');
    unione_aF(A, n_a, B, n_b, C, &n_c);
    for(i = 0; i < n_c; ++i)
    {
        printf("%f\n", C[i]);
    }
    putchar('\n');
    return 0;
}

void scan_array_int(int* array, int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        printf("Inserire il %d elemento: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void scan_array_float(float* array, int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        printf("Inserire il %d elemento: ", i + 1);
        scanf("%f", &array[i]);
    }
}

int appartiene(int chiave, int array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        if(chiave == array[i])
            return 1;
    }
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

void unione(int* array, int size_1, int* array2, int size_2, int* array3, int* size_3)
{
    int i, i_c;
    for(i = 0; i < size_1; ++i)
        array3[i] = array[i];
    i_c = size_1 - 1;
    for(i = 0; i < size_2; ++i)
    {
        if(!appartiene(array2[i], array, size_1))
        {
            array3[++i_c] = array2[i];
        }
    }
    *size_3 = i_c + 1;
}

void unione_aF(float* array, int size_1, float* array2, int size_2, float* array3, int* size_3)
{
    int i, i_c;
    for(i = 0; i < size_1; ++i)
        array3[i] = array[i];
    i_c = size_1 - 1;
    for(i = 0; i < size_2; ++i)
    {
        if(!appartiene_aF(array2[i], array, size_1))
        {
            array3[++i_c] = array2[i];
        }
    }
    *size_3 = i_c + 1;
}
