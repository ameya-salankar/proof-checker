#include "functions.h"

using namespace std;

string tr_input(vector<string>& tr, string in)
{
    string temp;
    while(in[i] != '/')
    {
        temp.push_back(in[i]);
		i++;
    }
    tr.push_back(temp);
	return temp;
}

void and_introduction_check(vector<string>& tr,string in)
{
	string temp = tr_input(tr, in);
    

}

void and_elimination_check(vector<string>& tr,string in)
{

}

void or_introduction_check(vector<string>& tr,string in)
{

}

void impl_elimination_check(vector<string>& tr,string in)
{

}

bool is_substr(string sub, string str)
{
	int l = str.length(), i, j = 0;
	for (i = 0; i < l; i++)
	{
		if (str[i] == sub[j])
		{
			while(str[i] == sub[j] && j < sub.length())
			{
				i++;
				j++;
			}
		}
		if(j == sub.length())
			return true;

		i -= j;

		j = 0;
	}
}
