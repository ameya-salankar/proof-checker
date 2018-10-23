#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

/**
 * main.cpp
 * performs i/o and stuff
 */

int main(void)
{
	string in, out1, out2;

	getline(cin, in);

	int l = in.length()-1;

	tree my_tree;
	my_tree.constr_pt(in, l);
	my_tree.infix_tr(out1);
	my_tree.postfix_tr(out2);

	cout << "Infix: " << out1 << endl << "Postfix: " << out2 << endl;

	return 0;
}