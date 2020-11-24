/*Sviluppare una function C che, dati come parametri di input un array di int, il suo size e un int k, determina e
  restituisce come parametro di output il k-imo più grande elemento dell'array (N.B.: l'array non deve essere
  ordinato).*/
#include <stdio.h>

int trovareKimoElemento(int[], size_t, int);

int main(int argc, const char * argv[])
{
    int array[] = {10, 235, 521, -21, 0};
    size_t size = sizeof(array) / sizeof(int);
    printf("%d\n", trovareKimoElemento(array, size, 3));
    
    return 0;
}

int trovareKimoElemento(int array[], size_t size, int k)
{
    int kthLargest = 0, largest = 0;
    unsigned int pass;
    size_t i;
    
    for(pass = 0; pass < k; ++pass)
    {
        for(i = 0; i < size; ++i)
        {
            if(array[i] < kthLargest || pass == 0)
                if(largest < array[i] || largest == 0)
                    largest = array[i];
        }
        kthLargest = largest;
        largest = 0;
    }
            
    return kthLargest;
}

