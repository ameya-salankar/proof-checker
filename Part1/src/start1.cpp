#include <iostream>
#include <stack>
#include "tree.h"
#include "postfix.h"

using namespace std;

/**
 * \brief A function for handling the part 1 of the assignment
 * 
 * Performs its own I/O
 */
void start_part1(void)
{
	string in, in_pf, out1, out2, c;

	getline(cin, c);
	cout << "Postfix generation\n" << "Enter a formula: ";
	getline(cin, in);

	generate(in, in_pf);

	int l = in_pf.length()-1;

	tree* my_tree;
	my_tree = new tree [sizeof(tree)];
	my_tree->constr_pt(in_pf, l);
	my_tree->infix_tr(out1);
	my_tree->postfix_tr(out2);

	cout << "Infix: " << out1 << endl << "Postfix: " << out2 << endl;

	my_tree->dels();
	delete my_tree;
}