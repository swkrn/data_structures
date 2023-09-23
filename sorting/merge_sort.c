#include <stdio.h>

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


void merge_sort(int *A, int n)
{
    if (n <= 1)
    {
        return;
    }
    
    int mid = n / 2;

    int nL = mid;
    int nR = n - mid;

    int L[nL];
    int R[nR];

    for (int i = 0; i < nL; i++)
    {
        L[i] = A[i];
    }
    for (int i = 0; i < nR; i++)
    {
        R[i] = A[mid + i];
    }

    merge_sort(L, nL);
    merge_sort(R, nR);

    int pt_l = 0, pt_r = 0, pt_a = 0;
    
    while (pt_l < nL && pt_r < nR)
    {
        if (L[pt_l] < R[pt_r])
        {
            A[pt_a] = L[pt_l];
            pt_l ++;
        }
        else
        {
            A[pt_a] = R[pt_r];
            pt_r ++;
        }
        pt_a ++;
    }

    while (pt_l < nL)
    {
        A[pt_a] = L[pt_l];
        pt_l ++;
        pt_a ++;
    }

    while (pt_r < nR)
    {
        A[pt_a] = R[pt_r];
        pt_r ++;
        pt_a ++;
    }
}


int main() 
{   
    int n = 6;
    int A[] = {1, 7, 4, 2, 5, 3};

    print_array(A, n);
    merge_sort(A, n);
    print_array(A, n);

    return 0;
}