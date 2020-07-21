#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: parent is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: return a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *son = NULL;

	son = malloc(sizeof(binary_tree_t));

	if (!son)
	{
		return (NULL);
	}
	son->n = value;
	son->parent = parent;
	son->left = NULL;
	son->right = NULL;

	return (son);
}

