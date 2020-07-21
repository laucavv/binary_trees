#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: parent is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: return a pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *son = NULL, *help = NULL;


	if (parent)
	{
		son = binary_tree_node(parent, value);
		if (!son)
			return (NULL);
		if (parent->left == NULL)
			parent->left = son;
		else
		{
			help = parent->left;
			parent->left = son;
			help->parent = son;
			son->left = help;
		}
	}
	return (son);
}
