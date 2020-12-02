/*Sviluppare una function C che, dati come parametri di input un array di int e il suo size,
  determina e restituisce come parametro di output il secondo più grande elemento dell’array (N.B.:
  non bisogna seguire l’idea di ordinare prima l’array).*/
#include <stdio.h>

int secondMax(int[], int);

int main(int argc, const char * argv[]) {
    int array[5] = {100, 0, 10, 90, 4};
    printf("Il secondo elemento piu' grande e': %d.\n", secondMax(array, 5));
    
    return 0;
}

int secondMax(int array[], int size) {
    int max, max2, i;
    
    if(array[0] > array[1]) {
        max = array[0];
        max2 = array[1];
    }
    else {
        max = array[1];
        max2 = array[0];
    }
    
    for(i = 2; i < size; ++i) {
        if(max < array[i]) {
            max2 = max;
            max = array[i];
        }
        else if(max2 < array[i])
            max2 = array[i];
    }
    
    return max2;
}
