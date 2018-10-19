#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

string tr_input(vector <string>& tr, string in);//input tab tak lena hai jab tak you dont hit a '/'
void and_elimination_check(vector <string>& tr, string in);//to check and elimination
void and_introduction_check(vector <string>& tr, string in);//and introduction check
void or_introduction_check(vector <string>& tr, string in);//to check or introduction
void impl_elimination_check(vector <string>& tr, string in);//to check implication elimination
bool is_substr(string sub, string str);

#endif
