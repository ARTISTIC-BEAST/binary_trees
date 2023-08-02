#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: parent of the new left-child to be inserted.
 * @value: value of the left-child.
 * Return: the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *temp;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->right = NULL;
	new->left = NULL;
	new->parent = parent;
	if (parent->left)
	{
		temp = parent->left;
		new->left = temp;
	}
	parent->left = new;
}
