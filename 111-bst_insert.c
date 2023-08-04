#include "binary_trees.h"

int helper_loop(int value, bst_t *current, bst_t **temp);

/**
 * bst_insert - insert operation for binary search @tree.
 * @tree: root node of binary tree.
 * @value: value to be inserted.
 * Return: NULL on failure and the newly created node on success.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *current;
	int ret;

	if (!tree)
		return (NULL);
	temp = malloc(sizeof(bst_t));
	if (!temp)
		return (NULL);
	temp->n = value;
	temp->right = NULL;
	temp->left = NULL;
	temp->parent = NULL;
	if (!*tree)
	{
		*tree = temp;
		return (temp);
	}
	current = *tree;
	ret = helper_loop(value, current, &temp);
	if (ret == 1)
		return (temp);
	return (NULL);
}

/**
 * helper_loop - loop for traversing and inserting.
 * @value: value to be inserted.
 * @current: ptr to current node.
 * @temp: ptr to the newly created node.
 * Return: -1 on failure. 1 on success.
 */
int helper_loop(int value, bst_t *current, bst_t **temp)
{
	while (1)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = *temp;
				(*temp)->parent = current;
				break;
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				current->right = *temp;
				(*temp)->parent = current;
				break;
			}
			current = current->right;
		}
		else
		{
			free(*temp);
			return (-1);
		}
	}
	return (1);
}
