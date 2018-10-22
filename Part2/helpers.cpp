#include "helpers.h"

using namespace std;

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

void tr_input(vector<string> &tr, string in)
{ 
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp); 
	tr.push_back(pf_temp);
}

bool is_substring(string sub, string str)
{
	int l = str.length(), i, j = 0;

	for (i = 0; i < l; i++)
	{
		if (str[i] == sub[j])
		{
			while (str[i] == sub[j] && j < sub.length())
			{
				i++;
				j++;
			}
		}
		if (j == sub.length())
			return true;

		i -= j;

		j = 0;
	}
	return false;
}
