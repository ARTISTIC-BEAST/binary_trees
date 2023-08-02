#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary @tree using in-order traversal.
 * @tree: the tree.
 * @func: function pointer, to a func that takes an int as arg and doesnt ret.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func(tree->n));
	func(tree->n);
	binary_tree_inorder(tree->right, func(tree->n));
}
