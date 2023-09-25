#include <stdio.h>
#include <string.h>


void FindDuplicate(char *A)
{
    int H = 0, x = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1 << (A[i] - 97);
        if (x & H)
        {
            printf("%c is duplicate\n", A[i]);
        }
        H = H | x;
    }
}


int IsAnagram(char *A, char *B)
{
    int j = 0;

    while (1)
    {
        if ((A[j] == '\0' && B[j] != '\0') || (A[j] != '\0' && B[j] == '\0'))
        {
            return 0;
        }
        if (A[j] == '\0' && B[j] == '\0')
        {
            break;
        }
        j ++;
    }

    int hashA = 0, hashB = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        hashA = hashA | (1 << (A[i] - 97));
        hashB = hashB | (1 << (B[i] - 97));
    }

    return hashA == hashB;
}


void CopyString(char *from, char *to)
{
    int i;
    for (i = 0; from[i] != '\0'; i++)
    {
        to[i] = from[i];
    }
    to[i + 1] = '\0';
}


void Permutation(char *A, int order)
{
    static char res[100];

    int has_letter_left = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] != '-')
        {
            has_letter_left = 1;
            break;
        }
    }
    if (!has_letter_left)
    {
        printf("%s\n", res);
        return;
    }

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] != '-')
        {
            char X[100] = { 0 };
            CopyString(A, X);
            X[i] = '-';

            res[order] = A[i];

            Permutation(X, order + 1);
        }
    }
}


int main()
{
    char A[] = "findduplicates";
    FindDuplicate(A);

    char B[] = "three";
    char C[] = "four";
    printf("%d\n", IsAnagram(B, C));

    char D[] = "funny";
    char E[] = "bunny";
    printf("%d\n", IsAnagram(D, E));

    char F[] = "decimal";
    char G[] = "medical";
    printf("%d\n", IsAnagram(F, G));

    char H[] = "hello";
    char I[10];
    CopyString(H, I);
    printf("%s\n", I);

    char J[] = "ABCD";
    Permutation(J, 0);
}