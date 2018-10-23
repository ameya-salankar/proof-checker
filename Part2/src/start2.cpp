#include <iostream>
#include <vector>
#include "helpers.h"

using namespace std;
/**
 * \brief main file
 * input - string
 * output- valid proof/invalid proof
 * 
*/
void start_part2 (void)
{
	int length;
	string str;
	vector<string> v;
	
	cin >> length;

	for (int i = 0; i < length; ++i)
	{
		cin >> str;
		v.push_back(str);
	}
	
	if (check(v))
		cout << "Valid Proof" << endl;
	else
		cout << "Invalid Proof" << endl;
}