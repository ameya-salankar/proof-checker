#include <stack>
#include "and.h"
#include "helpers.h"

using namespace std;

bool and_introduction_check(vector<string> &tr, string in, int l1, int l2) /**< checks for the correctness of and introduction */
{
    string temp = string_separate(in), pf_temp;
    generate(temp, pf_temp);                /**<postfix generation and stored in pf_temp*/

    if (pf_temp.back() == '^')              /**<first check if and is present*/
    {
        string correct = tr[l1];
        correct.append(tr[l2]);
        correct.push_back('^');

        if (correct == pf_temp)             /**<both in universal are part of that in the given test string*/
        {
            tr.push_back(pf_temp);          /**<input the correct statement in the truth array*/
            return true;
        }
    }

    return false;
}

bool and_elimination_check(vector<string> &tr, string in, int l1, int l2, vector<string>& v)
{
    string temp = string_separate(in), pf_temp;
    generate(temp, pf_temp);

    /*l1 is type of elimination and l2 is line number of the and statement*/
    
    stack<char> check;
    string temp_input = v[l2];
    string input = string_separate(temp_input);

    string left, right;

    check.push('(');

    if(l1 == 1)
    {
        for (int i = 0; i < input.length(); i++)
        {
            left.push_back(input[i]);

            if (input[i] == '(')
                check.push(input[i]);
            else if (input[i] == ')')
                check.pop();

            if (check.size() == 1 && input[i + 1] == '^')
            {
                string pf_left;
                generate(left, pf_left);
                if (pf_left == pf_temp)
                {
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
    }
    else if(l1 == 2)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '(')
                check.push(input[i]);
            else if (input[i] == ')')
                check.pop();

            if (check.size() == 1 && input[i + 1] == '^')
            {
                for (int j = i + 2; j < input.length(); j++)
                    right.push_back(input[j]);

                string pf_right;
                generate(right, pf_right);

                if (pf_right == pf_temp)
                {
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
    }
    
    return false;
}