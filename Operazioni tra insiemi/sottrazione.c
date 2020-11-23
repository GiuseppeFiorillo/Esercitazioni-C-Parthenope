//N.B.: In questo file sono presenti le funzioni sia per quanto riguarda gli array di int che quelli di float.
#include <stdio.h>

void scan_array_int(int*, int);
void scan_array_float(float*, int);
int appartiene_aF(float, float array[], int size);
int appartiene(int, int*, int);
void sottrazione(int*, int, int*, int, int*, int*);
void sottrazione_aF(float*, int, float*, int, float*, int*);

int main(int argc, const char * argv[])
{
    int n_a, n_b, n_c = 0, i;
    
    printf("Inserire la dimensione del primo array: ");
    scanf("%d", &n_a);
    printf("Inserire la dimensione del secondo array: ");
    scanf("%d", &n_b);
    
    float A[n_a], B[n_b], C[n_a];
    printf("\nPrimo array:\n");
    scan_array_float(A, n_a);
    printf("\nSecondo array:\n");
    scan_array_float(B, n_b);
    
    printf("\nPrimo array dopo la sottrazione:\n");
    sottrazione_aF(A, n_a, B, n_b, C, &n_c);
    for(i = 0; i < n_c; ++i)
    {
        printf("%f\n", C[i]);
    }
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

void sottrazione(int* array, int size_1, int* array2, int size_2, int* array3, int* size_3)
{
    int i, i_c;
    i_c = 0;
    for(i = 0; i < size_1; ++i)
    {
        if(!appartiene(array[i], array2, size_2))
            array3[i_c++] = array[i];
    }
    *size_3 = i_c;
}

void sottrazione_aF(float* array, int size_1, float* array2, int size_2, float* array3, int* size_3)
{
    int i, i_c;
    i_c = 0;
    for(i = 0; i < size_1; ++i)
    {
        if(!appartiene_aF(array[i], array2, size_2))
        {
            array3[i_c] = array[i];
            ++i_c;
        }
    }
    *size_3 = i_c;
}
