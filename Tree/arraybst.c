#include <stdio.h>
#include <stdlib.h>
void inorder(int *bstarr, int i)
{
    if (bstarr[i] != -1)
    {
        inorder(bstarr, 2 * i + 1);
        printf("%d\t", bstarr[i]);
        inorder(bstarr, 2 * i + 2);
    }
}

void preorder(int *bstarr, int i)
{
    if (bstarr[i] != -1)
    {
        printf("%d\t", bstarr[i]);
        preorder(bstarr, 2 * i + 1);
        preorder(bstarr, 2 * i + 2);
    }
}

void postorder(int *bstarr, int i)
{
    if (bstarr[i] != -1)
    {
        postorder(bstarr, 2 * i + 1);
        postorder(bstarr, 2 * i + 2);
        printf("%d\t", bstarr[i]);
    }
}

int min(int *bstarr)
{
    int i = 0;
    while (bstarr[2 * i + 1] != -1)
    {
        i = 2 * i + 1; // moving left
    }
    return bstarr[i];
}

int max(int *bstarr)
{
    int i = 0;
    while (bstarr[2 * i + 2] != -1)
    {
        i = 2 * i + 2; // moving right
    }
    return bstarr[i];
}

void insert(int *bstarr, int ele)
{
    int i = 0;
    while (bstarr[i] != -1)
    {
        if (ele > bstarr[i])
        {
            i = 2 * i + 2; // moving right
        }
        else
        {
            i = 2 * i + 1; // moving left
        }
    }
    bstarr[i] = ele;
}

void delete (int *bstarr, int delele)
{
    int i = 0;
    while (bstarr[i] != -1)
    {
        if (delele > bstarr[i])
        {
            i = 2 * i + 2; // moving right
        }
        else if (delele < bstarr[i])
        {
            i = 2 * i + 1; // moving left
        }
        else
        {
            bstarr[i] = -1;
            return;
        }
    }
    printf("Element not present :");
}

int main()
{
    int bstarr[50];
    int ch, num, i, delele, maxele, minele;
    for (int i = 0; i < 50; i++)
    {
        bstarr[i] = -1; // making all elements null
    }
    printf("1.Insertion\n2.Deletion\n3.Inorder\n4.Preorder\n5.Postorder\n6.Max\n7.Min\n8.Exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element you want to insert :");
            scanf("%d", &num);
            insert(bstarr, num);
            break;
        case 2:
            printf("Enter the element you want to delete :");
            scanf("%d", &delele);
            delete (bstarr, delele);
            break;
        case 3:
            inorder(bstarr, 0);
            break;
        case 4:
            preorder(bstarr, 0);
            break;
        case 5:
            postorder(bstarr, 0);
            break;
        case 6:
            maxele = max(bstarr);
            printf("The maximum element is  : %d", maxele);
            break;
        case 7:
            minele = min(bstarr);
            printf("The minimum element is  : %d", minele);
            break;
        case 8:
            exit(0);
        default:
            break;
        }
    }
}
