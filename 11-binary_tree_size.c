#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the size.
 * Return:  Size of a binary tree, else 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->left)
			count += binary_tree_size(tree->left);
		if (tree->right)
			count += binary_tree_size(tree->right);
		count++; /* count root node */
	}
	return (count);
}
