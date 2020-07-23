#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth a node binary tree
 * @tree:  is a pointer to the root node of the tree to measure the depth.
 * Return:  depth of a node binary tree, else 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count_depth = 0;

	if (tree)
	{
		if (tree->parent)
			count_depth = 1 + binary_tree_depth(tree->parent);
		return (count_depth);
	}
	return (0);
}

/**
 * binary_tree_depth - function that measures the depth a node binary tree
 * @first:  a pointer to the first node
 * @second: a pointer to the second node
 * Return:  a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first = 0, depth_second = 0, i = 0, n = 0;
	const binary_tree_t *up = NULL, *down = NULL;

	depth_first = binary_tree_depth(first); /*depht of first node */
	depth_second = binary_tree_depth(second); /*depht of second node */
	if (!first || !second)
		return (NULL);

	if (depth_second > depth_first)
	{
		i = depth_second;
		n = depth_first;
		down = second;
		up = first;
	}
	else /*Exchange values*/
	{
		i = depth_first;
		n = depth_second;
		down = first;
		up = second;
	}

	for (; i > n ;  i--)
		down = down->parent;

	while (up && down) /* Both same depth */
	{
		if (up == down)
			return ((binary_tree_t *)up);

		up = up->parent;
		down = down->parent;
	}
	return (NULL);
}
