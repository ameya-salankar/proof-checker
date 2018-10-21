#include "and.h"
#include "helpers.h"

bool and_introduction_check(vector<string> &tr, string in, int pos) /**< checks for the correctness of and introduction */
{
    string temp = string_separate(in);
    string pf_temp;
    generate(temp, pf_temp);                                /**<postfix generation and stored in pf_temp*/
    int l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    if (pf_temp.back() == '^') /**<first check if and is present*/
    {
        if (is_substring(tr[l1], pf_temp) && is_substring(tr[l2], pf_temp))
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
    int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    generate(temp, pf_temp);
    if (is_substring(pf_temp, tr[l1]))
    {
        tr.push_back(pf_temp);
        return true;
    }
    return false;
}