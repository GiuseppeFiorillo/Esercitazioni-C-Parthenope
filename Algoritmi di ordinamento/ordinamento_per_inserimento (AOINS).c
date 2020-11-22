#include <stdio.h>

void scan_array_int(int[], int);
void stampa_array_int(int[], int);
void ordinamento_per_inserimento(int[], int);

int main(int argc, const char * argv[])
{
    int arr[100], num;
    
    printf("Quanti elementi vuoi inserire nell'array?\n");
    scanf("%d", &num);
    
    scan_array_int(arr, num);
    ordinamento_per_inserimento(arr, num);
    putchar('\n');
    stampa_array_int(arr, num);
    
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

void stampa_array_int(int array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
        printf("%d elemento: %d\n", i + 1, array[i]);
}

void ordinamento_per_inserimento(int array[], int size)
{
    int i, j, elementoDaInserire;
    
    for(i = 1; i < size; ++i)
    {
        elementoDaInserire = array[i];
        j = i - 1;
        while (j >= 0 && elementoDaInserire < array[j])
        {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = elementoDaInserire;
    }
}

/*L'AOINS è un algoritmo di complessità quadratica, la sua complessità è quindi al più O(n^2) (confronti), dove n è la dimensione dell'array di input.
  Per capire l'algoritmo possiamo immaginare di ordinare in maniera crescente le carte da gioco. A ogni passo, dobbiamo inserire una nuova carta facendo
  eventualmente slittare le carte fino a trovare il posto giusto per la nuova carta.*/
