#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>
#include "postfix.h"
#include <iostream>
using namespace std;

/**
 * Helper functions for checking proof rules.
 * Each function performs different proof rule verification and
 * is called in its respective case by the code in check.cpp
 */

bool check(vector<string> &v);
string string_separate(string in);        /**< separates the line from its justification (i.e. line/rule/num1/num2) */
void tr_input(vector<string> &tr, string in); /**< appends in the universal truth array */
bool is_substring(string sub, string str);


#endif
