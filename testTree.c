#include"testTree.h"

/*Description: This function inserts nodes into the tree that was built.
 **Parameters: A node_t struct and string.
 **Return: A node_t struct.
 *****************************************************/
/*struct node_t* insert(struct node_t* node, string data)
{
	//Checks if node is empty.
	if(node == NULL) 
	{
		return newNode(data);
	}

	//Conditionals to decide where the node should be placed - left or right.
	if(data < node->data)
	{
		node->left = insert(node->left, data);
	}
	else if(data > node->data)
	{
		node->right = insert(node->right, data);
	}

	return node;
}*/

/*Description: This function takes root and prints preorder tree.
 **Parameters: root node.
 **Return: void.
 *************************************************/
/*void printPreorder(struct node_t* root)
{
	if(root != NULL)
	{
		cout << root->data << " \n";
		printPreorder(root->left);
		printPreorder(root->right);
	}
}*/

