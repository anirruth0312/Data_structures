#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
    int data;
    struct bst *lchild;
    struct bst *rchild;
} t_node;

t_node *createnode(int ele)
{
    t_node *newnode;
    newnode = malloc(sizeof(t_node));
    newnode->data = ele;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

void insert(t_node **proot, int ele)
{

    t_node *newnode = createnode(ele);
    t_node *current, *prev; // for traversing
    current = *proot;
    if (*proot == NULL) // if root is empty
    {
        (*proot) = newnode;
    }
    else
    {
        while (current != NULL)
        {
            prev = current;
            if (ele > current->data)
            {
                current = current->rchild;
            }
            else // lesser than or equal to same case
            {
                current = current->lchild;
            }
        }
        if (ele > prev->data)
        {
            prev->rchild = newnode;
        }
        else
        {
            prev->lchild = newnode;
        }
    }
}

void inorder(t_node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}

void delete (t_node **proot, int dele)
{
    t_node *prev, *current, *replacement; // replacement holds the data that should be attached
    current = *proot;
    prev = NULL;
    int flag = 0; // flag denotes if element is found
    while (current != NULL)
    {
        if (dele > current->data)
        {
            prev = current;
            current = current->rchild;
        }
        else if (dele < current->data)
        {
            prev = current;
            current = current->lchild;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    // four cases
    if (flag)
    {
        if (current->lchild == NULL && current->rchild == NULL) // only leaf node
        {
            replacement = NULL;
        }
        else if (current->lchild != NULL && current->rchild == NULL) // lchild present
        {
            replacement = current->lchild;
        }
        else if (current->lchild == NULL && current->rchild != NULL) // rchild present
        {
            replacement = current->rchild;
        }
        else if (current->lchild != NULL && current->rchild != NULL)
        {
            replacement = current->rchild;
            // four choices for replacement
            // first choice replacing successor
            t_node *insucc;
            insucc = current->rchild;
            while (insucc->lchild != NULL)
            {
                insucc = insucc->lchild;
            }
            current->data = insucc->data;
            delete (proot, insucc->data);
            // second choice replacing predecessor
            /*
            t_node *predess;
            predess = current->lchild;
            while (predess->rchild != NULL)
            {
                predess = predess->rchild;
            }
            current->data = predess->data;
            */

            // data replacement case
            /*
            t_node*insucc,*psucc;
            insucc=current->rchild;
            while(insucc->lchild!=NULL)
            {
                psucc=insucc;
                insucc=insucc->lchild;
            }
            current->data=insucc->data;//assigning successor to current->data
            free(insucc);
            psucc->lchild=NULL;
            */
            /*4th method
             t_node *presucc, *psucc;
             presucc = current->lchild;
             while (presucc->rchild != NULL)
             {
                psucc = presucc;
                presucc = presucc->rchild;
             }
             current->data = presucc->data;
             free(presucc);
             psucc->rchild = NULL;*/
        }
    }

    if (prev)
    {
        if (prev->rchild == current)
        {
            prev->rchild = replacement;
        }
        else
        {
            prev->lchild = replacement;
        }
    }
    else
    {
        *proot = replacement;
    }
    free(current);
}

int main()
{
    t_node *root;
    int dele;
    int ele;
    root = NULL;
    while (1)
    {
        int ch = 0;

        printf("\nEnter your choice \n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element you want to insert :");
            scanf("%d", &ele);
            insert(&root, ele);
            break;
        case 2:
            printf("\nEnter the element you want to delete :");
            scanf("%d", &dele);
            delete (&root, dele);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            exit(0);
        }
    }
}