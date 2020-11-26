#include <stdio.h>

void min_val_ind(char*, size_t, char*, size_t*);
void scambiare_C(char*, char*);
void ord_sel_min(char*, size_t);
size_t min_ind(char*, size_t);

int main(int argc, const char * argv[])
{
    char array[] = {'z', 'o', 'c', 'x', 'a'};
    size_t n = sizeof(array)/sizeof(char);
    ord_sel_min(array, n);
    
    for(size_t i = 0; i < n; ++i)
        printf("%c\n", array[i]);
    
    return 0;
}


void min_val_ind(char* array, size_t size, char* min_array, size_t* i_min)
{
    size_t i;
    *min_array = array[0];
    *i_min = 0;
    
    for(i = 1; i < size; ++i)
    {
        if(array[i] < *min_array)
        {
            *min_array = array[i];
            *i_min = i;
        }
    }
}

void scambiare_C(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void ord_sel_min(char* array, size_t size)
{
    size_t i, i_min;
    char minimo;
    
    for(i = 0; i < size - 1; ++i)
    {
//        min_val_ind(&array[i], size - i, &minimo, &i_min);
//        scambiare_C(&array[i], &array[i_min + i]);
        scambiare_C(&array[i], &array[min_ind(&array[i], size - i) + i]);
    }
}

size_t min_ind(char* array, size_t size)
{
    size_t i, i_min = 0;
    for(i = 1; i < size; ++i)
    {
        if(array[i_min] > array[i])
            i_min = i;
    }
    
    return i_min;
}

/* Analizziamo la complessità dell'AOSMIN. La complessità di spazio è n, perché l'algoritmo opera completamente
   "in place".
   Passiamo alla complessità di tempo. Negli algoritmi di ordinamento si considearno come operazioni dominanti
   l'operazione di confronto tra due elementi dell'array e l'operazione di scambio tra 2 elementi dell'array.
   Analizziamo prima determinando il numero di scambi, il numero di volte in cui la function scambiare_c viene
   chiamata. L'attivazione di scambiare_c avviene ad ogni iterazione del ciclo for, che va da 0 a (n-2), cioè
   per un totale di n-1 iterazioni. Quindi l'AOISM effettua SEMPRE n-1 scambi; è una complessità cosìdetta
   assoluta, perché indipendente dai valori degli array.
   Passiamo ora ad analizzare i confronti. Poiché nelle funzioni ord_sel_min e scambiare_C non compaiono confronti,
   i soli confronti sono quelli contenuti nella function min_val_ind. Ricordiamo che la complessità di tempo
   dell'algoritmo di determinazione del minimo assoluto di un array è data dal size dell'array -1 operazioni di confronto. 
   Tale complessità è assoluta.
   T(n) = (n*(n-1))/2 = 1/2(n^2-n) = O(n^2) confronti,
   T(n) = n = O(n) scambi.
   Poiché la complessità di tempo dell'AOSMIN non dipende dal valore dei dati, l'AOSMIN assume lo stesso costo
   anche nel caso in cui l'array sia già ordinato, il costo è quindi di caso assoluto. */
