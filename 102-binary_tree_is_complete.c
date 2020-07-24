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
/**
 * incre_index - function that increase the index of left and right sub-trees
 * @tree:  a pointer to the root node of the tree to check
 * @index: index of root node
 * @nuno: number of nodes of binary tree
 * Return: 1 tree is complete binary tree, else 0.
 */
int incre_index(const binary_tree_t *tree, size_t index, size_t nuno)
{
	int in_left = 0, in_right = 0; /* index left and right */

	if (!tree)
		return (1);
	if (index >= nuno)
		return (0);

	in_left = incre_index(tree->left, 2 * index + 1, nuno);
	in_right = incre_index(tree->right, 2 * index + 2, nuno);

	return (in_left * in_right);
}

/**
 * binary_tree_is_complete - function that measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree to check
 * Return: else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nuno = 0; /* number of nodes */
	int iscomplete = 0; /*  */

	if (!tree)
		return (0);

	nuno = binary_tree_size(tree);

	/* Aux function to increase the index */
	iscomplete = incre_index(tree, 0, nuno);

	return (iscomplete);
}
