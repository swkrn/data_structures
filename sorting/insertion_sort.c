#include <stdio.h>

void insertion_sort(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int value = A[i];
        for (int k = i; k > 0; k--)
        {
            if (A[k - 1] > value)
            {
                A[k] = A[k - 1];
            }
            else
            {
                A[k] = value;
                break;
            }
        }
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
    insertion_sort(A, n);
    print_array(A, n);

    return 0;
}