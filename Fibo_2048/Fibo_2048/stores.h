#include<stdlib.h>

void print_InOrder(struct data*root)
{
	if (root != NULL)
	{
		print_InOrder(root->left);
		printf("%s\t%s\t%d\t%d\n",root->date,root->name,root->size,root->moves);
		print_InOrder(root->right);
	}

}



struct data* new_node(struct data* root, struct data* d)
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->date = d->date;
	node->moves = d->moves;
	node->name = d->name;
	node->size = d->size;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct data* insert(struct data* root,struct data* d)
{
	if (root == NULL)
	{
		return new_node(root, d);
	}
	else if (d->moves < root->moves)
		return insert(root->left, d);
	else
	{
		return insert(root->right, d);
	}
	return root;
}