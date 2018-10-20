#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

/**
 * Helper functions for checking proof rules.
 * Each function performs different proof rule verification and
 * is called in its respective case by the code in check.cpp
 */

string string_separate(string in); /**< separates the line from its justification (i.e. line/rule/num1/num2) */
void tr_input(vector<string> &tr, string in); /**< appends in the universal truth array */
bool and_introduction_check(vector<string> &tr, string in, int pos); /**< checks for and introduction rule */
bool and_elimination_check(vector<string> &tr, string in, int pos);
bool or_introduction_check(vector<string> &tr, string in, int pos);
bool impl_elimination_check(vector<string> &tr, string in, int pos);
bool mt_check(vector<string> &tr, string in, int pos);
bool is_substring(string sub, string str);
bool check_impl_left(string part, string whole)
bool check_impl_right(string part, string whole, int start)

#endif
