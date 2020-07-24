#include "binary_trees.h"
/**
 * binary_tree_rotate_left - that performs a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: return a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree && tree->right)
	{
		tree->parent = tree->right;
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;
		if (tree->right)
		{
			tree->right->parent = tree;
		}
		tree = tree->parent;
		return (tree);
	}
	return (NULL);
}
