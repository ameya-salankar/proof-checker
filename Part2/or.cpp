#include "or.h"
#include "helpers.h"

using namespace std;

bool or_introduction_check(vector<string> &tr, string in, int pos)
{
    string temp = string_separate(in);
    string pf_temp;
    int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    generate(temp, pf_temp);
    if (pf_temp.back() == 'V')
    {
        if (is_substring(tr[l1], pf_temp))
        {
            tr.push_back(pf_temp);
            return true;
        }
    }
    return false;
}