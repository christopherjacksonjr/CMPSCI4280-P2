#include<stdio.h>
#include<iostream>
#include<iomanip>
#include"testTree.h"

string determineNodeLabel(NodeLabel label);

/*Description: This function takes root and prints preorder tree.
 **Parameters: root node.
 **Return: void.
 *************************************************/
void printPreorder(struct Node_t* root, int level)
{
	string label;	

	if(root != NULL)
	{
		label = determineNodeLabel(root->label);
		
		if (level) {
                        std::cout << std::setw(level) << ' ';
                }
		cout<< label << " ";
                cout << root->token.instance << " ";
                cout << root->token2.instance << "\n";
		if(root->left_child) printPreorder(root->left_child, level+4);
        	if(root->right_child) printPreorder(root->right_child, level+4);
        	//if (level) {
            	//	std::cout << std::setw(level) << ' ';
        	//}
        	//cout<< label << "\n ";
		//cout << root->token.instance;
		//cout << root->token2.instance;		


		/*printf("%*s%d:%-9s ",level*2,' ',level,label.c_str());
		printf("\n");
  		printPreorder(root->left_child,level+1);
  		printPreorder(root->right_child,level+1);*/

		/*cout << label << " \n";
		cout << root->token.instance;
		cout << root->token2.instance;
		level++;
		//printPreorder(root->token.instance, level);
		printPreorder(root->left_child, level);
		printPreorder(root->right_child, level);*/
	}
}

/*string getName(NodeLabel label)
{
	return NodeLabel[label];
}*/

string determineNodeLabel(NodeLabel label)
{
        switch(label)
        {
                case Program:
                        return "program";
                case Block:
                        return "block";
                case Vars:
                        return "vars";
                case Expr:
                        return "expr";
                case PlusExpr:
                        return "+expr";
                case MinusExpr:
                        return "-expr";
                case ALabel:
                        return "A";
                case MultiplicationA:
                        return "*A";
                case NLabel:
                        return "N";
                case DivisionN:
                        return "/N";
                case MLabel:
                        return "M";
                case SubtractionM:
                        return "-M";
                case RLabel:
                        return "R";
                case Stats:
                        return "stats";
                case MStat:
                        return "mStat";
                case Stat:
                        return "stat";
                case In:
                        return "in";
                case Out:
                        return "out";
                case If:
                        return "if";
                case Loop:
                        return "loop";
                case Assign:
                        return "assign";                             
		case ROLabel:
                        return "RO";
		default:
			return "not-defined";

        }
}
 
