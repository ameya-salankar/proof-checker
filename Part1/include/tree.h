#ifndef TREE_H
#define TREE_H

#include <string>

using namespace std;

/// tree.h defines the tree class for the parse tree

/** constr_pt - construct parse tree
 *      A recursive function for loading the parse tree into
 * 		the memory from a postfix notation
 */

/** setprev - set prev pointer
 *		Sets the prev member of the object. Reqd by constr_ptr
 */

/** infix_tr - infix traverse
 * 		Inorder traversal of the tree
 */

/** postfix_tr - postfix traverse
 * 		Postorder traversal of the tree
 */

/** check_root function
 * 		Returns true if the root is a propositional atom (i.e. an alphabet)
 */

class tree
{
private:
	char root; 		/**< the node member in a tree */
	tree* left; 	/**< pointer to the left child/subtree */
	tree *right; 	/**< pointer to the right child/subtree */
	tree *prev;  	/**< pointer to the parent */

  public:
	tree() /**< default constructor - set all the pointers to NULL */
	{
		prev = NULL;
		right = NULL;
		left = NULL;
	}

	void constr_pt(string s, int &index); /**< construct parse tree */
	bool check_root(void);				  /**< check if the root is an alphabet */
	void setprev(tree *pos);			  /**< set the previous member */
	void infix_tr(string &out);			  /**< inorder traversal of the parse tree */
	void postfix_tr(string &out);		  /**< postorder traversal of the parse tree */
};

#endif