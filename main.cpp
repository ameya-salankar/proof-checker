#include <iostream>
#include <stack>
#include <string>
#include "tree.h"

using namespace std;

/*
 * main.cpp
 * performs i/o and stuff
 */

int main(void)
{
	stack < int > s;
	string in, out1, out2;

	getline(cin, in);

	int l = in.length()-1;

	//Debugging print statement. DO NOT use in final code
	cout << in << endl << l << endl;

	tree my_tree;
	my_tree.constr_pt(in, l);
	my_tree.infix_tr(out1);
	my_tree.postfix_tr(out2);

	cout << "Infix: " << out1 << endl << "Postfix: " << out2 << endl;

	return 0;
}