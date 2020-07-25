#include "binary_trees.h"
#include <limits.h>

/**
 * aux_is_bst - goes through a binary tree and check if each subtree is
 * BST tree
 * @tree: A pointer to the root node of the tree to traverse
 * @min: Min value of left side is negative, and right side is tree->n + 1
 * @max: Max value of right side is a big number, and left side is tree->n - 1
 * Return: 1 is BST tree, else 0
 */

int aux_is_bst(const binary_tree_t *tree, int min, int max)
{
	/*        .-------(098)--.*/
	/*   .--(012)--.       (128)--.*/
	/* (010)     (054)          (402)*/
	/* In this case, left side max value is 097 (98 - 1) and, */
	/* right side min value is 99 (98 + 1). Only for the first entry */

	int bst_left = 0, bst_right = 0;

	if (!tree) /*node at last level, NULL*/
		return (1);

	if (tree->n < min || tree->n > max) /*invalid node*/
		return (0);

	/*Change max = tree->n - 1, left side*/
	/*printf("Max = tree->n - 1 = %d\n", tree->n - 1);*/
	bst_left = aux_is_bst(tree->left, min, tree->n - 1);

	/*Change min = tree->n + 1, right side*/
	/*printf("Min = tree->n + 1 = %d\n", tree->n + 1);*/
	bst_right = aux_is_bst(tree->right, tree->n + 1, max);

	return (bst_left * bst_right);
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a
 * valid Binary Search Tree
 * Properties of a Binary Search Tree:
 *   The left subtree of a node contains only nodes with values less than
 *   the nodes value
 *   The right subtree of a node contains only nodes with values greater than
 *   the nodes value
 *   The left and right subtree each must also be a binary search tree
 *   There must be no duplicate values
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 is BST tree, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int bst_left = 0, bst_right = 0;

	if (tree)
	{
		/* INT_MIN = -2147483648, INT_MAX = 2147483647 */
		bst_left = aux_is_bst(tree->left, INT_MIN, tree->n - 1);
		bst_right = aux_is_bst(tree->right, tree->n + 1, INT_MAX);
	}
	return (bst_left * bst_right);/* true{1*1}, false{1*0, 0*1, 0*0} */
}
