#include "binary_trees.h"

/**
 * binary_tree_rotate_right - that performs a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree && tree->left)
	{
		tree->left->parent = tree->parent; /*parent of new parent*/
		tree->parent = tree->left; /*new parent of old parent*/
		tree->left = tree->left->right; /*left node of new root->left*/
		tree->parent->right = tree; /*right node of new parent */
		if (tree->left)/* parent of new root->right->left */
			tree->left->parent = tree;
		tree = tree->parent; /**/
		return (tree);
	}
	return (NULL);
}
