#include "binary_trees.h"
bst_t *get_successor(bst_t *node);

/**
 * bst_remove - removes a node from a binary tree.
 * @root: root of tree.
 * @value: value of node to remove.
 * Return: NULL on failure and updated pointer on success.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		successor = get_successor(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}

/**
 * get_successor - gets the replacement of the removed node.
 * @node: the node to be removed.
 * Return: the successor.
 */
bst_t *get_successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}
