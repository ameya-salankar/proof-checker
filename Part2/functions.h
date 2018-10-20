#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

// string string_separate(string in);
//input tab tak lena hai jab tak you dont hit a '/'
//to check and elimination
//and introduction check
//to check or introduction
//to check implication elimination

string string_separate(string in);
void tr_input(vector<string> &tr, string in);
bool and_introduction_check(vector<string> &tr, string in, int pos);
bool and_elimination_check(vector<string> &tr, string in, int pos);
bool or_introduction_check(vector<string> &tr, string in, int pos);
bool impl_elimination_check(vector<string> &tr, string in, int pos);
bool mt_check(vector<string> &tr, string in, int pos);
bool is_substring(string sub, string str);

#endif
