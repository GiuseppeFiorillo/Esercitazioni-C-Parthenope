#include <stdio.h>

void scan_array_int(int*, int);
void sottrazione(int*, int, int*, int, int*, int*);

int main(int argc, const char * argv[])
{
    int n_a, n_b, n_c = 0, i;
    
    printf("Inserire la dimensione del primo array: ");
    scanf("%d", &n_a);
    printf("Inserire la dimensione del secondo array: ");
    scanf("%d", &n_b);
    
    int A[n_a], B[n_b], C[n_a];
    printf("\nPrimo array:\n");
    scan_array_int(A, n_a);
    printf("\nSecondo array:\n");
    scan_array_int(B, n_b);
    
    printf("\nPrimo array dopo la sottrazione:\n");
    sottrazione(A, n_a, B, n_b, C, &n_c);
    for(i = 0; i < n_c; ++i)
    {
        printf("%d\n", C[i]);
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

void sottrazione(int* array, int size_1, int* array2, int size_2, int* array3, int* size_3)
{
    int i, j, flag;
    for(i = 0; i < size_1; ++i)
    {
        flag = 0;
        for(j = 0; j < size_2; ++j)
        {
            if(array[i] == array2[j])
                flag = 1;
        }
        
        if(flag == 0)
        {
            array3[*size_3] = array[i];
            ++(*size_3);
        }
    }
}
