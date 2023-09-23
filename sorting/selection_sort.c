#include <stdio.h>

void selection_sort(int *A, int n)
{
    
    for (int i = 0; i < n - 1; i++)
    {
        int min = A[i];
        int min_pos = i;

        for (int k = i + 1; k < n; k++)
        {
            if (A[k] < min)
            {
                min = A[k];
                min_pos = k;
            }
        }

        int temp = A[i];
        A[i] = min;
        A[min_pos] = temp;
    }
}


void print_array(int *A, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
        else
        {
            printf("]\n");
        }
    }
}


int main() 
{   
    int n = 6;
    int A[] = {1, 7, 4, 2, 5, 3};

    print_array(A, n);
    selection_sort(A, n);
    print_array(A, n);

    return 0;
}