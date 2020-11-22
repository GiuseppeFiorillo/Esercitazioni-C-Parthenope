/*Sviluppare una function C che, dati come parametri di input un array di int e il suo size, determina e
  restituisce come parametro di output il secondo più grande elemento dell'array (N.B.: l'array non deve essere
  ordinato).*/
#include <stdio.h>

void scan_array_int(int[], int);
int secondoElemento(int[], int);

int main(int argc, const char * argv[])
{
    int arr[100], num;
    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &num);
    scan_array_int(arr, num);

    putchar('\n');
    printf("Il secondo elemento più grande è: %d\n", secondoElemento(arr, 4));
    return 0;
}

void scan_array_int(int array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        printf("Inserire il %d elemento: ", i + 1);
        scanf("%d", &array[i]);
    }
}

int secondoElemento(int arr[], int size)
{
    int max, secondMax, i;
    if(arr[0] > arr[1])
    {
        max = arr[0];
        secondMax = arr[1];
    }
    else
    {
        max = arr[1];
        secondMax = arr[0];
    }

    for(i = 2; i < size; ++i)
    {
        if(max < arr[i])
        {
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax)
        {
            secondMax = arr[i];
        }
    }
    return secondMax;
}
