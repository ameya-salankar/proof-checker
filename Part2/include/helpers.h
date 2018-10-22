#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>
#include "postfix.h"

using namespace std;

/**
 * General helper functions for checking proof rules.
 * Each function is called by different proof rule verification functions
 */

bool check(vector<string> &v);                  /**< the main checking logic, central checking functions caller */
string string_separate(string in);              /**< separates the line from its justification (i.e. line/rule/num1/num2) */
void tr_input(vector<string> &tr, string in);   /**< appends the trur statement in the universal truth array */
bool is_substring(string sub, string str);      /**< checks if the sub is present in str */
int extract(string s, int& c);

#endif
