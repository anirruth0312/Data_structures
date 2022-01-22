#include <stdio.h>
#include <stdlib.h>
struct node
{
    int c;
    int e;
    struct node *link;
};
typedef struct node poly_node;

poly_node *createnode(int c, int e)
{
    poly_node *newnode = (poly_node *)malloc(sizeof(poly_node));
    if (newnode != NULL)
    {
        newnode->c = c;
        newnode->e = e;
        newnode->link = NULL;
    }
    else
        printf("Memory not allocated\n");
    return newnode;
}

poly_node *attach(poly_node *start, int c, int e)
{
    // adding values to rear end of the list
    poly_node *dstart = start;
    poly_node *newnode;
    newnode = createnode(c, e);
    if (dstart == NULL)
    {
        dstart = newnode;
        dstart->link = NULL;
    }
    else
    {
        while (dstart->link != NULL)
        {
            dstart = dstart->link;
        }
        dstart->link = newnode;
        newnode->link = NULL;
    }
    return dstart;
}

void read_poly(poly_node **dstart)
{
    int ch = 1, c, e;
    poly_node *new;
    printf("Do you want to enter an element.(1/0)\n");
    scanf("%d", &ch);
    while (ch)
    {
        printf("Enter the coefficient and exponent.\n");
        scanf("%d", &c);
        scanf("%d", &e);
        *dstart = attach((*dstart), c, e);
        printf("Do you want to enter an element.(1/0)\n"); // checking continuity of loop
        scanf("%d", &ch);
    }
}

int compare(int a, int b)
{
    if (a > b)
        return 1;
    else if (b > a)
        return 2;
    else
        return 3;
}

poly_node *add_poly(poly_node *start1, poly_node *start2, poly_node *start3)
{
    // Duplicate starts for traversal
    poly_node *dstart1 = start1;
    poly_node *dstart2 = start2;
    poly_node *dstart3 = start3;
    int sums;
    while (dstart1 != NULL && dstart2 != NULL)
    {
        switch (compare(dstart1->e, dstart2->e))
        {
        case 1:
            dstart3 = attach(dstart3, dstart1->c, dstart1->e);
            dstart1 = dstart1->link;
            break;
        case 2:
            dstart3 = attach(dstart3, dstart2->c, dstart2->e);
            dstart2 = dstart2->link;
            break;
        case 3:
            sums = dstart1->c + dstart2->c; // adds coefficient of equal power terms
            if (sums)                       // checks if sum is non zero
            {
                dstart3 = attach(dstart3, sums, dstart1->e);
            }
            dstart1 = dstart1->link;
            dstart2 = dstart2->link;
            break;
        }
    }
    // if list 2 is empty
    while (dstart1 != NULL)
    {
        attach(dstart3, dstart1->c, dstart1->e);
        dstart1 = dstart1->link;
    }
    // if list 1 is empty
    while (dstart2 != NULL)
    {
        attach(dstart3, dstart2->c, dstart2->e);
        dstart2 = dstart2->link;
    }
    return dstart3;
}

void display(poly_node *dstart)
{
    while (dstart->link != NULL)
    {
        printf("%dx^%d\t", dstart->c, dstart->e);
        dstart = dstart->link;
    }
    if (dstart->e == 0)
        printf("%d\n", dstart->c);
    else
        printf("%dx^%d\n", dstart->c, dstart->e);
}

int main()
{
    poly_node *start1;
    start1 = NULL;
    printf("Enter values for first polynomial.\n");
    read_poly(&start1);
    // display(start1);
    poly_node *start2;
    start2 = NULL;
    printf("Enter values for second polynomial.\n");
    read_poly(&start2);
    // display(start2);
    poly_node *start3;
    start3 = NULL;
    start3 = add_poly(start1, start2, start3);
    display(start3);
}