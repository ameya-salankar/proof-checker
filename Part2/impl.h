#ifndef IMPL_H
#define IMPL_H

#include <string>
#include <vector>

using namespace std;

bool impl_elimination_check(vector<string> &tr, string in, int pos);
bool mt_check(vector<string> &tr, string in, int pos);
bool check_impl_left(string part, string whole);
bool check_impl_right(string part, string whole, int start);

#endif