#include "functions.h"
#include "postfix.h"

using namespace std;

string string_separate(string in)
{
	/**< To seperate the strings to get the useful part */
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
{ /**<To input whatever is the absolute truth in the truth vector*/
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp); /**<generates the postfix substring and stores it in pf_temp*/
	tr.push_back(pf_temp);
}

bool and_introduction_check(vector<string> &tr, string in, int pos)
{			 /**<to check for and introduction*/
	int pos; /**<vector to store position*/
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp); /**<postfix generation and stored in pf_temp*/
	if (pf_temp.back() == '^')
	{ /**<first check if and is present*/
		if (is_substring(tr[pos], pf_temp) && is_substring(tr[pos + 2], pf_temp))
		{
			/**<both in universal are part of that in the given test string*/
			tr.push_back(pf_temp); /**<input the correct statement in the truth array*/
			return true;
		}
	}
	return false;
}

bool and_elimination_check(vector<string> &tr, string in, int pos)
{
	string temp = string_separate(in);
	string pf_temp;
	int pos; /**<to get the line number*/
	generate(temp, pf_temp);
	if (is_substring(pf_temp, tr[pos]))
	{
		tr.push_back(pf_temp);
		return true;
	}
	return false;
}

bool or_introduction_check(vector<string> &tr, string in, int pos)
{
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp);
	if (pf_temp.back() == 'V')
	{
		if (is_substring(tr[pos], pf_temp))
		{
			tr.push_back(pf_temp);
			return true;
		}
	}
	return false;
}

bool impl_elimination_check(vector<string> &tr, string in, int k)
{
	int pos = in[k] - '0';
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp);

	if (pf_temp.back() == '>')
	{
		/**
		 * if p is substring of p > q and
		 * first element of postfixes of p and p>q are same and
		 * q is a substring of p>q
		 * then true
		 */

		if ((is_substring(tr[pos + 2], tr[pos])) && is_substring(pf_temp, tr[pos]))
		{
			int l = tr[pos + 2].length();
			if (check_impl_left(tr[pos + 2], tr[pos]))
			{
				if (check_impl_right(pf_temp, tr[pos], l))
				{
					tr.push_back(pf_temp);
					return true;
				}
			}
		}
	}
	return false;
}

bool mt_check(vector<string> &tr, string in, int pos)
{
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp);
	pf_temp.pop_back();
	int l = pf_temp.length(), l1 = (in[pos]-'0') - 1, l2 = (in[pos+2]-'0') - 1;
	string pro = tr[l2];
	pro.pop_back();

	if(is_substring(pf_temp, tr[l1]) && is_substring(pro, tr[l1]))
	{
		if(check_impl_right(pro, tr[l1], l))
		{
			if(check_impl_left(pf_temp, tr[l1]))
			{
				tr.push_back(pf_temp);
					return true;
			}
		}
	}
	return false;
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
}

bool check_impl_left(string part, string whole)
{
	int l = part.length(), l2 = whole.length(), i, j;
	for(i = 0, j = 0; i < l && j < l2; i++, j++)
	{
		if(part[i] != whole[j])
			break;
	}

	if(i == l)
		return true;
	else
		return false;
}

bool check_impl_right(string part, string whole, int start)
{
	int l = part.length(), l2 = whole.length(), i , j;
	for (i = 0, j = start; i < l && j < l2; i++, j++)
	{
		if (part[i] != whole[j])
			break;
	}

	if (i == l)
		return true;
	else
		return false;
}