#include "binary_trees.h"

/**
 * binary_tree_balance -  function that measures the balance 
 * factor of a binary tree
 * @tree: root node of the tree to measure the balance factor 
 * Return: 2 for balance, -1 for not balnce, otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->left && tree->right)
		{
			return (2);
		}
		else if (tree->left || tree->right)
		{
			return (-1);
		}
	}
	return (0);
}
