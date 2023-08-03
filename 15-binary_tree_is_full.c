#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a @tree is full.
 * @tree: a pointer to the root node of the tree to count the number of nodes.
 * Return: 0 if @tree is full and 1 if not full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	return (0);
}
