#include <stdio.h>
#include <stdlib.h>

int *insHeap(int *H, int n)
{
    int p, c, key; // p is the parent node index
    for (p = (n / 2) - 1; p >= 0; p--)
    {
        key = H[p];    // key is the parent node
        c = p * 2 + 1; // lchild
        while (c < n)
        {
            if (H[c + 1] > H[c] && c < n - 1)
                c = c + 1; // if rchild is greater than lchild

            if (H[c] > key)
            {
                H[p] = H[c];
            }
            else
            {
                break;
            }
            p = c;
            c = p * 2 + 1;
        }
        H[p] = key;
    }
    return H;
}

int *delHeap(int *H, int n) // deleting root and calling ins heap again

{
    H[0] = H[n - 1];
    return insHeap(H, n);
}

void display(int *H, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", H[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {89, 22, 38, 43, 50};
    int *H;
    H = insHeap(&(a[0]), 5);
    display(H, 5);
    H = delHeap(&(a[0]), 5);
    display(H, 4);
    H = insHeap(&(a[0]), 4);
    display(H, 3);
    return 0;
}