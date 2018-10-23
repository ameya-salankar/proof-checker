#ifndef AND_H
#define AND_H

#include <string>
#include <vector>

using namespace std;

bool and_introduction_check(vector<string> &tr, string in, int l1, int l2);                  /**< check statement for and introduction*/
bool and_elimination_check(vector<string> &tr, string in, int l1, int l2, vector<string>& v);/**< check statement for and elimination*/

#endif