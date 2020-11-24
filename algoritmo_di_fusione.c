#include <stdio.h>

void leggi_da_tastiera_int(int[], size_t);
void stampa_array_int(int[], size_t);
void ordinamento_per_inserimento(int[], size_t);
// void fusione(int[], size_t, int[], size_t, int[]);
void fusioneWhile(int[], size_t, int[], size_t, int[]);

int main()
{
    int A[100], B[100], C[200];
    size_t n_a, n_b, n_c;

    printf("Inserisci la dimensione del primo array: ");
    scanf("%zu", &n_a);
    printf("Inserisci la dimensione del secondo array: ");
    scanf("%zu", &n_b);
    n_c = n_a + n_b;

    printf("\nPrimo Array:\n");
    leggi_da_tastiera_int(A, n_a);
    printf("\nSecondo Array:\n");
    leggi_da_tastiera_int(B, n_b);

    fusioneWhile(A, n_a, B, n_b, C);
    printf("\nArray Fusione (ordinato):\n");
    stampa_array_int(C, n_c);
    putchar('\n')

    return 0;
}

void leggi_da_tastiera_int(int a[], size_t size)
{
    size_t i;
    for(i = 0; i < size; ++i)
    {
        printf("Inserire il %zu elemento: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void stampa_array_int(int a[], size_t size)
{
    size_t i;
    for(i = 0; i < size; ++i)
        printf("Il %zu elemento e': %d\n", i + 1, a[i]);
}

void ordinamento_per_inserimento(int a[], size_t size)
{
    int elementoDaInserire;
    size_t i = 0;
    int j;  //j non può essere un unsigned int o un size_t perché c'è la possibilità che possa avere momentaneamente il valore -1.
    for(i = 1; i < size; ++i)
    {
        elementoDaInserire = a[i];
        j = i - 1;
        while(j >= 0 && elementoDaInserire < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = elementoDaInserire;
    }
}

/* void fusione(int a[], size_t n_a, int b[], size_t n_b, int c[])
{
    int i_a = 0, i_b = 0, i_c;
    for(i_c = 0; i_c < n_a + n_b; ++i_c)
    {
        if(i_a < n_a && i_b < n_b)
        {
            if(a[i_a] < b[i_b])
                c[i_c] = a[i_a++];
                
            else
                c[i_c] = b[i_b++];
        }
        else if(i_a >= n_a)
            c[i_c] = b[i_b++];

        else
            c[i_c] = a[i_a++];

    }
} */


void fusioneWhile(int A[], size_t n_a, int B[], size_t n_b, int C[])
{
    ordinamento_per_inserimento(A, n_a);
    ordinamento_per_inserimento(B, n_b);
    size_t i_a = 0, i_b = 0, i_c = 0;
    while(i_a < n_a && i_b < n_b)
    {
        if(A[i_a] < B[i_b])
            C[i_c++] = A[i_a++];
        else
            C[i_c++] = B[i_b++];
    }
    while(i_a < n_a)
        C[i_c++] = A[i_a++];
    while(i_b < n_b)
        C[i_c++] = B[i_b++];
}

/*Analizziamo la complessità dell'algoritmo di fusione. Considerando che n = n_a + n_b, l'algoritmo avrà complessità di spazio 2n, dato che costruisce un terzo 
  array di size n. Passiamo alla complessità di tempo. L’operazione dominante è l’operazione di confronto tra un elemento dell’array A e un elemento dell’array B.
  L’AFUS effettua n = n_a+n_b passi, cioè quanti sono gli elementi di C che devono essere determinati. A ogni passo si costruisce un elemento dell’array C.
  Se si è nello scenario 1, allora è necessario esattamente un confronto per determinare un elemento di C. Se si è nello scenario 2 o nello scenario 3, 
  allora non si effettua alcun confronto. Quindi si può concludere che il numero totale di confronti è al più n = n_A+n_B. Si noti che si tratta di una
  complessità di caso peggiore. In conclusione la complessità di tempo dell’AFUS è: T(n) = T(n_a+n_b) = n = O(n) confronti al più, con n = n_a + n_b. */
