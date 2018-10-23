#ifndef IMPL_H
#define IMPL_H

#include <string>
#include <vector>

using namespace std;

bool impl_elimination_check(vector<string> &tr, string in, int l1, int l2);/**< check statement for implication elimination*/
bool mt_check(vector<string> &tr, string in, int l1, int l2);              /**< check statement for modus tollens*/

#endif