#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
} node;

typedef struct stack
{
    node *s[MAX];
    int size;
    int top;
    int capacity;
} stack;

node *init(char data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->lchild = temp->rchild = NULL;
    temp->data = data;
    return temp;
}
void push(stack *pst, node *ele)
{
    (pst->top)++;
    (pst->s)[pst->top] = ele;
    (pst->size)++;
}
node *pop(stack *pst)
{
    node *ele;
    ele = (pst->s)[pst->top];
    (pst->top)--;
    (pst->size)--;
    return ele;
}

int isoper(char data)
{
    if (data == '+' || data == '-' || data == '*' || data == '/')
        return 1;
    else
        return 0;
}

node *create_exptree(char *exp)
{
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    st->size = 0;
    st->capacity = MAX;
    char token = exp[0];
    int flag = 1;
    while (token != '\0')
    {
        node *temp = (node *)malloc(sizeof(node));
        temp = init(token);
        if (isoper(token))
        {
            temp->rchild = pop(st);
            temp->lchild = pop(st);
        }
        push(st, temp);
        token = exp[flag++];
    }
    node *x = pop(st);
    return x;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->lchild);
        printf("%c", root->data);
        inorder(root->rchild);
    }
}

float eval_exptree(node *root)
{
    if (isoper(root->data))
    {
        float op1, op2;
        op1 = eval_exptree(root->lchild);
        op2 = eval_exptree(root->rchild);
        switch (root->data)
        {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        }
    }
    else
    {
        float op;
        printf("Enter the value of variable %c: ", root->data);
        scanf("%f", &op);
        return op;
    }
}

int main()
{
    node *root = NULL;
    char exp[MAX];
    scanf("%s", exp);
    root = create_exptree(exp);
    inorder(root);
    printf("\n");
    printf("%.2f", eval_exptree(root));
    return 0;
}
