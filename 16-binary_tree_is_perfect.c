#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 is full binary tree, else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!(tree->left) && !(tree->right))
			return (1);
		if (tree->left && tree->right)
			if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
				return (1);
	}
	return (0);
}

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
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 is perfect or 0 is not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (tree)
	{
		if (binary_tree_is_full(tree->left) == binary_tree_is_full(tree->right))
		{
			if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}
