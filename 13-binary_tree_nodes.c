#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a @tree.
 * @tree: a pointer to the root node of the tree to count the number of nodes.
 * Return: no. of nodes in @tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (!tree)
		return (0);
	left = tree->left->left ? 1 + binary_tree_nodes(tree->left) : 0;
	right = tree->right->right ? 1 + binary_tree_nodes(tree->right) : 0;
	return (left + right);
}
