#include<stdio.h>
#include<iostream>
#include"testTree.h"

/*Description: This function takes root and prints preorder tree.
 **Parameters: root node.
 **Return: void.
 *************************************************/
void printPreorder(struct Node_t* root)
{
	if(root != NULL)
	{
		cout << root->label << " \n";
		printPreorder(root->left_child);
		printPreorder(root->right_child);
	}
}

