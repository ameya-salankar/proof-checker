#include <iostream>
#include "tree.h"

using namespace std;

/*
 * tree.cpp
 * implementation of the tree class
 *
 * TODO: print brackets in the infix notation
 */

void tree :: constr_pt(string s, int& index)
{
	//Set the root variable
	root = s[index];

	//If propositional atom, declare it a leaf and return
	if ((s[index] >= 'a' && s[index] <= 'z') || index == 0)
	{
		left = NULL;
		right = NULL;
		return;
	}

	/* If symbol
	 *	if right node is empty
	 *		make a new right node
	 *		set its prev member to the current node in the tree
	 *		recursively call the right node's constr_pt function on a decremented index
	 *		
	 *		if root is a ~ symbol,
	 *			no left node exists, so return
	 *
	 *		repeat the same with the left node
	 *
	 *  TODO: is the right node empty condition seems redundant. Can we do away with it??
	 */

	else if (s[index] == '~' || s[index] == 'V' || s[index] == '^' || s[index] == '>')
	{
		if (right == NULL)
		{
			index--;
			right = new tree[sizeof(tree)];
			right->setprev(prev);
			right->constr_pt(s, index);

			if (root == '~')
			{
				right = NULL;
				return;
			}

			if (index != 0)
			{
				left = new tree[sizeof(tree)];	
				left->setprev(prev);
				index--;
				left->constr_pt(s, index);
			}
		}
	}
}

void tree :: setprev(tree* pos)
{
	prev = pos;
}


/*
	infix_tr function
	traverses in the order : left root right
*/
void tree :: infix_tr(string& out)
{
	if (left != NULL)
		left->infix_tr(out);

	out.push_back(root);

	if (right != NULL)
		right->infix_tr(out);
}


/*
	postfix_tr function
	traverses in the order : left right root
*/
void tree :: postfix_tr(string& out)
{
	if (left != NULL)
		left->postfix_tr(out);

	if (right != NULL)
		right->postfix_tr(out);

	out.push_back(root);
}