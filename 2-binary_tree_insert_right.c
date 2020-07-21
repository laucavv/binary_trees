#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: parent is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: return a pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *son = NULL, *help = NULL;


	if (parent)
	{
		son = binary_tree_node(parent, value);
		if (!son)
			return (NULL);
		if (parent->right == NULL)
			parent->right = son;
		else
		{
			help = parent->right;
			parent->right = son;
			help->parent = son;
			son->right = help;
		}
	}
	return (son);
}
