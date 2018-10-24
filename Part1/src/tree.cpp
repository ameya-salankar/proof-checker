#include "tree.h"

using namespace std;

/**
 * \brief Takes a postfix string and implements it in its parse tree form
 * \param s a postfix string
 * \param index the position of the current character in s
 */

void tree :: constr_pt(string s, int& index)
{
	root = s[index];

	if ((s[index] >= 'a' && s[index] <= 'z') || index == 0)
	{
		left = NULL;
		right = NULL;
		return;
	}

	else if (s[index] == '~' || s[index] == 'V' || s[index] == '^' || s[index] == '>')
	{
		right = new tree[sizeof(tree)];
		right->setprev(this);
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

/**
 * \brief Sets the prev member of the object to pos (which is a parent of the node)
 * \param pos a pointer to a parent
 */
void tree :: setprev(tree* pos)
{
	prev = pos;
}

/**
 * \brief Generates an infix notation of the tree
 * Generates infix by inorder traversal of the tree
 * \param out a string to store the infix notation
 */
void tree :: infix_tr(string& out)
{
	if (!check_root())
		out.push_back('(');
	
	if (left != NULL)
		left->infix_tr(out);

	out.push_back(root);

	
	if (right != NULL)
	{
		right->infix_tr(out);
		if (!check_root())
			out.push_back(')');
	}
}

/**
 * \brief Generates an infix notation of the tree
 * Generates postfix by postorder traversal of the tree
 * \param out a string to store the postfix notation
 */
void tree :: postfix_tr(string& out)
{
	if (left != NULL)
		left->postfix_tr(out);

	if (right != NULL)
		right->postfix_tr(out);

	out.push_back(root);
}

/**
 * \brief Checks whether the root is a propositional atom
 * \return a boolean value corresponding to the case
 */

bool tree :: check_root(void)
{
	if (root >='a' && root <='z')
		return true;
	else
		return false;
}

/**
 * \brief Frees the tree from the memory
 * Traverses in the order : left right root
 */
void tree :: dels(void)
{
	if (left != NULL)
		left->dels();

	if (right != NULL)
		right->dels();

	if (left != NULL)
		delete left;
	if (right != NULL)
		delete right;
}