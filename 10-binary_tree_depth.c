#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth a node binary tree
 * @tree:  is a pointer to the root node of the tree to measure the depth.
 * Return:  depth of a node binary tree, else 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count_depth = 0;

	if (tree)
	{
		if (tree->parent)
			count_depth = 1 + binary_tree_depth(tree->parent);

		return (count_depth);
	}
	return (0);
}
