#include <iostream>
#include "tree.h"

using namespace std;

/*
 * tree.cpp
 * implementation of the tree class
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
	 *	  make a new right node
	 *	  set its prev member to the current node in the tree
	 *	  recursively call the right node's constr_pt function on a decremented index
	 *	  
	 *	  if root is a ~ symbol,
	 *	  	no left node exists, so return
	 *
	 *	  repeat the same with the left node
	 */

	else if (s[index] == '~' || s[index] == 'V' || s[index] == '^' || s[index] == '>')
	{
		right = new tree[sizeof(tree)];
		right->setprev(prev);
		index--;
		right->constr_pt(s, index);

		if (root == '~')
		{
			left = NULL;
			return;
		}

		if (index != 0)
		{
			left = new tree[sizeof(tree)];	
			left->setprev(this);
			index--;
			left->constr_pt(s, index);
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
	static int x = 0;

	//Safeguard against printing an extra bracket
	if (x == 0)
		x = 1;
	else if (!check_root())
		out.push_back('(');
	
	if (left != NULL)
		left->infix_tr(out);


	out.push_back(root);

	
	if (right != NULL)
	{
		right->infix_tr(out);
		if (right->check_root())
			out.push_back(')');
	}
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


/*
	check_root function
	returns true if the root is a propositional atom (i.e. an alphabet)
*/
bool tree :: check_root(void)
{
	if (root >='a' && root <='z')
		return true;
	else
		return false;
}