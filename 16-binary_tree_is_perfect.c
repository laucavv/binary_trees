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
 * binary_tree_height - function that measures the height of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the height.
 * Return:  Height of a binary tree, else 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count_left = 0, count_right = 0;

	if (tree)
	{
		if (tree->left)
			count_left = 1 + binary_tree_height(tree->left);
		if (tree->right)
			count_right = 1 + binary_tree_height(tree->right);

		if (count_left > count_right)
			return (count_left);
		else
			return (count_right);
	}
	return (0);
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
		if (binary_tree_is_full(tree->left) &&  binary_tree_is_full(tree->right))
		{
			if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}
