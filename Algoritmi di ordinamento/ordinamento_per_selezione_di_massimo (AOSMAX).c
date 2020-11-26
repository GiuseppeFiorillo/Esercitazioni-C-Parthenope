#include <stdio.h>

void max_val_ind(char*, size_t, char*, size_t*);
void scambiare_C(char*, char*);
void ord_sel_max(char*, size_t);
size_t max_ind(char*, size_t);

int main(int argc, const char * argv[])
{
    char array[] = {'f', 'd', 'z', 'a', 'b'};
    ord_sel_max(array, 5);
    for(int i = 0; i < 5; ++i)
        printf("%c\n", array[i]);
    
    return 0;
}

void max_val_ind(char* array, size_t size, char* max, size_t* i_max)
{
    size_t i;
    *max = array[0];
    *i_max = 0;
    for(i = 0; i < size; ++i)
    {
        if(*max < array[i])
        {
            *max = array[i];
            *i_max = i;
        }
    }
}

void scambiare_C(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void ord_sel_max(char* array, size_t size)
{
    size_t i, i_max;
    char max;
    for(i = size - 1; i > 0; --i)
    {
//        max_val_ind(&array[0], i + 1, &max, &i_max);
//        scambiare_C(&array[i], &array[i_max]);
        scambiare_C(&array[i], &array[max_ind(&array[0], i+1)]);
    }
}

size_t max_ind(char* a, size_t n)
{
    size_t i, i_max = 0;
    for(i = 1; i < n; ++i)
    {
        if(a[i] > a[i_max])
            i_max = i;
    }
    return i_max;
}
