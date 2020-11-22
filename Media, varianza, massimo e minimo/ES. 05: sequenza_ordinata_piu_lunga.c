/*Sviluppare una function C che, dati come parametri di input un array di int e il suo size,
  determina e restituisce come parametri di output l’indice di inizio e la lunghezza della più
  lunga sequenza ordinata (senso crescente) contenuta nell’array.*/
#include <stdio.h>

void sequenza_piu_lunga(int*, int, int*, int*);

int main()
{
    int array[] = {0, 1, 4, 18, 12, 14, 16, 18, 43, 10, 21}, n = 11, lunghezza = 0, indice = 0;
    
    sequenza_piu_lunga(array, n, &lunghezza, &indice);
    printf("%d\n", lunghezza);
    printf("%d\n", indice);
    
    return 0;
}

void sequenza_piu_lunga(int *array, int size, int *lunghezza, int *indice)
{
    int cont = 0, inizio = 0, flag = 0, i;
    for(i = 0; i < size; ++i)
    {
        if(array[i] < array[i+1])
        {
            ++cont;
            if(flag == 0)
            {
                flag = 1;
                inizio = i;
            }
        }
        else
            flag = cont = 0;
        
        if(cont > *lunghezza)
        {
            *lunghezza = cont + 1;
            *indice = inizio;
        }
    }
}
