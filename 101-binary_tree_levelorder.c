#include "binary_trees.h"

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
 * aux_levelorder - aux
 * @level: level tree
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 */
void aux_levelorder(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		aux_levelorder(tree->left, level - 1, func);
		aux_levelorder(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through
 * @tree: is a pointer to the root node of the tree to traverse
 * @func:  is a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 1; i <= height; i++)
	{
		aux_tree_levelorder(tree, i, func);
	}
}
