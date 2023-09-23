#include <stdio.h>

void bubble_sort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        for (int k = 0; k < n - i; k++)
        {
            if (A[k] > A[k + 1])
            {
                int temp = A[k];
                A[k] = A[k + 1];
                A[k + 1] = temp;

                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
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
    bubble_sort(A, n);
    print_array(A, n);

    return 0;
}