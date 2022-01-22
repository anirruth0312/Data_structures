#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int *s;
    int capacity;
    int top;
    int size;
};
typedef struct stack stack;
void init_stack(stack *pst, int c) // pst=pointer to stack
{
    pst->s = NULL;
    pst->capacity = c;
    pst->top = -1;
    pst->size = 0;
}

int isempty(stack *pst)
{
    if (pst->top == -1)
        return 1;
    else
        return 0;
}

int isfull(stack *pst)
{
    if (pst->size == pst->capacity)
        return 1;
    else
        return 0;
}

void createstack(stack *pst)
{
    pst->s = malloc(sizeof(int) * pst->capacity);
}

void double_stack(stack *pst)
{
    pst->s = realloc(pst->s, sizeof(int) * (2 * pst->capacity));
}

void push(stack *pst, int ele)
{
    if (isfull(pst))
    {
        double_stack(pst);
    }
    (pst->top)++;
    pst->s[pst->top] = ele;
    pst->size = (pst->top) + 1;
}

void pop(stack *pst)
{
    if (isempty(pst))
    {
        printf("Stack is empty\n");
    }
    else
    {
        pst->top--;
        pst->size--;
    }
}

void display(stack *pst)
{

    for (int i = pst->top; i >= 0; i--)
    {
        printf("%d\t", pst->s[i]);
    }
}
int main()
{
    stack st;
    int c;
    printf("Enter the size of the stack :");
    scanf("%d", &c);
    init_stack(&st, c);
    createstack(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    printf("The stack after inserting six elements.\n");
    display(&st);
    pop(&st);
    pop(&st);
    pop(&st);
    printf("\n");
    printf("\nThe stack after deleting three elements.\n");
    display(&st);
    printf("\n");
}