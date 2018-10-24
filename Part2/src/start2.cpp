#include <iostream>
#include <vector>
#include "helpers.h"

using namespace std;

/**
 * \brief A function for handling the part 2 of the assignment
 * Performs its own I/O
 */
void start_part2 (void)
{
	int length;
	string str;
	vector<string> v;
	
	cout << "Enter a proof below:\n\n";
	cin >> length;

	for (int i = 0; i < length; ++i)
	{
		cin >> str;
		v.push_back(str);
	}
	
	if (check(v))
		cout << "\nValid Proof\n" << endl;
	else
		cout << "\nInvalid Proof\n" << endl;
}