#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: the root node of the tree to count the number of leaves
 * Return: numbers of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_leaves = 0;

	if (tree)
	{
		if (tree->left ==  NULL && tree->right == NULL)
		{
			count_leaves++;
		}
		count_leaves += binary_tree_leaves(tree->left);
		count_leaves += binary_tree_leaves(tree->right);
	}
	return (count_leaves);
}
