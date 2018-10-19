#include <string>

using namespace std;

/*
 * tree.h
 * defines the tree class for the parse tree
 *
 * constr_pt - construct parse tree
 *      A recursive function for loading the parse tree into
 * 		the memory from a postfix notation
 * 	 arguments - postfix notation string s
 * 				 index variable for keeping track of the location in s	
 *
 * setprev - set prev pointer
 *		Sets the prev member of the object. Reqd by constr_ptr
 * 	 arguments - a pointer variable of type tree
 *
 * infix_tr - infix traverse
 * 		Inorder traversal of the tree
 * 	 arguments - an out string to store the infix notation
 *
 * postfix_tr - postfix traverse
 * 		Postorder traversal of the tree
 * 	 arguments - an out string to store the postfix notation
 *
 * check_root function
 * 		Returns true if the root is a propositional atom (i.e. an alphabet)
 */

class tree
{
private:
	char root;
	tree* left;
	tree* right;
	tree* prev;

public:
	tree()
	{
		prev = NULL;
		right = NULL;
		left = NULL;
	}
	
	void constr_pt(string s, int& index);
	bool check_root(void);
	void setprev(tree* pos);
	void infix_tr(string& out);
	void postfix_tr(string& out);
};