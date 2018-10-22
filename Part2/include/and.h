#ifndef AND_H
#define AND_H

#include <string>
#include <vector>

using namespace std;

bool and_introduction_check(vector<string> &tr, string in, int l1, int l2);
bool and_elimination_check(vector<string> &tr, string in, int l1, int l2, vector<string>& v);

#endif