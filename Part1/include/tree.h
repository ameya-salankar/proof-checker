#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

using namespace std;

/** 
 * \brief defines the class for the parse tree's node object.
 * 
 * \detailed This class contains the blueprint for creating a node object in a tree
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
	/**
	 * \brief The default constructor
	 * 
	 * sets all the pointers to NULL 
	 */
	tree()
	{
		prev = NULL;
		right = NULL;
		left = NULL;
	}

	void constr_pt(string s, int &index);
	bool check_root(void);
	void setprev(tree *pos);
	void infix_tr(string &out);
	void postfix_tr(string &out);
	void dels(void);
};

#endif