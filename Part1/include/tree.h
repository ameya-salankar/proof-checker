#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

using namespace std;

/** 
 * \brief defines the class for the parse tree's node object
 * This class contains the blueprint for creating a node object in a tree
 * and all the functions for modifying the tree.
 */

class tree
{
private:
	char root; 		/**< the node member in a tree */
	tree* left; 	/**< pointer to the left child/subtree */
	tree* right; 	/**< pointer to the right child/subtree */
	tree* prev;  	/**< pointer to the parent */

  public:
	tree() 			/**< default constructor - set all the pointers to NULL */
	{
		prev = NULL;
		right = NULL;
		left = NULL;
	}

	void constr_pt(string s, int &index); /**< construct parse tree */
	bool check_root(void);				  /**< checks if the root is an alphabet */
	void setprev(tree *pos);			  /**< set the previous member */
	void infix_tr(string &out);			  /**< infix generation from the parse tree */
	void postfix_tr(string &out);		  /**< postfix generation from the parse tree */
	void dels(void);					  /**< delete the parse tree from the memory */
};

#endif