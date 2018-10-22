#include "impl.h"
#include "helpers.h"

using namespace std;

bool impl_elimination_check(vector<string> &tr, string in, int pos)
{
    string temp = string_separate(in), pf_temp;
    generate(temp, pf_temp);

    int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    
    if (tr[l1].back() == '>')
    {
    
        /**
		 * if p is substring of p > q and
		 * first element of postfixes of p and p>q are same and
		 * q is a substring of p>q
		 * then true
		 */
    
        string correct  = tr[l2];
        correct.append(pf_temp);
        correct.push_back('>');
    
        if (correct == tr[l1])
        {
            tr.push_back(pf_temp);
            return true;        
        }
    }
    
    return false;
}

bool mt_check(vector<string> &tr, string in, int pos)
{
    string temp = string_separate(in), pf_temp;
    generate(temp, pf_temp);
    pf_temp.pop_back();
    
    int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;

    string pf_right = tr[l2];
    pf_right.pop_back();

    if (tr[l1].back() == '>')
    {
        /**
		 * if p is substring of p > q and
		 * first element of postfixes of p and p>q are same and
		 * q is a substring of p>q
		 * then true
		 */
        string correct = pf_temp;
        correct.append(pf_right);
        correct.push_back('>');

        if (correct == tr[l1])
        {
            pf_temp.push_back('~');
            tr.push_back(pf_temp);
            return true;
        }
    }

    return false;
}