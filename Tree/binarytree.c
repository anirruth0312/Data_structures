#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree
{
	int data;
	struct binary_tree *rchild;
	struct binary_tree *lchild;
} tnode;

tnode *createnode()
{
	int ele;
	printf("Enter a element :");
	scanf("%d", &ele);
	if (ele == -1)
		return NULL;
	else
	{
		tnode *p = malloc(sizeof(tnode));
		p->data = ele;
		p->lchild = createnode();
		p->rchild = createnode();
		return p;
	}
}

void inorder(tnode *root) // left root right
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

int traverse(tnode *root)
{
	if (root == NULL)
		return -1;
	else
	{
		traverse(root->lchild);
		return root->data;
		traverse(root->rchild);
	}
}
int max(tnode *root)
{
	if (root == NULL)
		return -99999999;
	int res = root->data;
	int lres = max(root->lchild);
	int rres = max(root->rchild);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}

int min(tnode *root)
{
	if (root == NULL)
		return 100000000;
	int res = root->data;
	int lres = min(root->lchild);
	int rres = min(root->rchild);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return res;
}

void preorder(tnode *root) // root left right
{
	if (root == NULL)
		return;
	else
	{
		printf("%d", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(tnode *root) // left right root
{
	if (root == NULL)
		return;
	else
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d", root->data);
	}
}

// counting number of leaf nodes
int leafcount(tnode *root)
{
	if (root == NULL)
		return 0;
	if ((root->lchild == NULL) && (root->rchild == NULL))
		return 1;
	int l = leafcount(root->lchild);
	int r = leafcount(root->rchild);
	return (l + r);
}

// Height of the tree
int height(tnode *root)
{
	if (root == NULL)
		return -1;
	if (root->lchild == NULL && root->rchild == NULL)
		return 0;
	if (height(root->lchild) > height(root->rchild))
	{
		int ans = height(root->lchild);
		return (1 + ans);
	}
	return (1 + height(root->rchild));
}

int main()
{
	tnode *root;
	root = NULL;
	root = createnode();
	inorder(root);
	int maxele = max(root);
	int minele = min(root);
	printf("\nThe maximum value is :%d", maxele);
	printf("\nThe minimum value is :%d", minele);
}