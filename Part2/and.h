#ifndef AND_H
#define AND_H

#include <string>
#include <vector>

using namespace std;

bool and_introduction_check(vector<string> &tr, string in, int pos);
bool and_elimination_check(vector<string> &tr, string in, int pos, vector<string>& v);

#endif