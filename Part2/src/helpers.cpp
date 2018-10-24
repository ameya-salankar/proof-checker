#include "helpers.h"
#include <iostream>

using namespace std;

/**
 * \brief Seperates the proof rule and the statement in the input string
 * \param in string argument
 * \return The separated string
 */
string string_separate(string in)
{
	string temp;
	int i = 0;
	while (in[i] != '/')
	{
		temp.push_back(in[i]);
		i++;
	}
	return temp;
}
/**
 * \brief Takes the argument string and adds it to the universal truth array 
 * \param in string argument
 * \param tr universal truth vector
 */
void tr_input(vector<string> &tr, string in)
{ 
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp); 
	tr.push_back(pf_temp);
}
/**
 * \brief Takes the argument string and extracts the line number(s) mentioned
 * \param s string argument
 * \param c integer argument
 * \return (integer)The line number
 */
int extract(string s, int& c)
{
	string num;
	int k = c+1;
	
	while (s[k] != '/' && s[k] != '\0')
		num.push_back(s[k++]);
	
	c = k;
	
	
	try
	{
		k = stoi(num);
	}
	catch(const exception& e)
	{
		cout << "Invalid Proof" << endl;
		exit(1);
	}

	return k;
}