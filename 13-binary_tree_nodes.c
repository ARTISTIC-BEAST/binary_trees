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
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	/*check if subtrees have at least a child*/
	if (tree->left || tree->right)
		return (left + right + 1);

	/*add right and left subtrees belonging to root*/
	return (right + left);
}
