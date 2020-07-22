#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least 1 child
 * in a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the size.
 * Return:  Size of a numbers of nodes with at least 1 child, else 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->left || tree->right)
		{
			if (tree->left)
				count += binary_tree_nodes(tree->left);
			if (tree->right)
				count += binary_tree_nodes(tree->right);
			count++; /* count root node */
		}
	}
	return (count);
}
