#include "binary_trees.h"

/**
 * binary_tree_sibling - returns sibling of a @node.
 * @node: node to be checked.
 * Return: pointer to sibling or null on failure.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->right && node->parent->left)
		return (node->parent->left);
	else if (node == node->parent->left && node->parent->right)
		return (node->parent->right);
	return (NULL);
}
