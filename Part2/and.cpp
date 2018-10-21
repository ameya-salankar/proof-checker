#include "and.h"
#include "helpers.h"
#include<stack>
using namespace std; 
bool and_introduction_check(vector<string> &tr, string in, int pos) /**< checks for the correctness of and introduction */
{
    string temp = string_separate(in);
    string pf_temp;
    generate(temp, pf_temp);                                /**<postfix generation and stored in pf_temp*/
    int l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    if (pf_temp.back() == '^') /**<first check if and is present*/
    {
        cout<< "l1: " << l1 << " " << tr[l1] << endl;
        cout<< "l2: " << l2 << " " << tr[l2] << endl;
        string correct = tr[l1];
        correct.append(tr[l2]);
        correct.push_back('^');
        // cout<<"correct: "<<correct<<endl;
        if (correct == pf_temp)
        {
            /**<both in universal are part of that in the given test string*/
            tr.push_back(pf_temp); /**<input the correct statement in the truth array*/
            return true;
        }
    }
    return false;
}

bool and_elimination_check(vector<string> &tr, string in, int pos,vector<string>& v)
{
    string temp = string_separate(in);
    int l1 = (in[pos] - '0'), l2 = (in[pos + 2] - '0') - 1;
    string pf_temp;
    /*l1 is type of elimination and l2 is line number of the and statement*/
    
    stack<char> check;
    string temp_input = v[l2];
    string input = string_separate(temp_input);

    string left;
    string right;
    check.push('(');
    for(int i=0; i<input.length(); i++)
    {
        if(l1 == 1)
        {
            //something will happen

            left.push_back(input[i]);

            if (input[i] == '(')
                check.push(input[i]);
            else if (input[i] == ')')
                check.pop();

            if (check.size() == 1 && input[i + 1] == '^')
            {   
                string pf_left;
                generate(temp, pf_temp);
                generate(left,pf_left);
                if (pf_left == pf_temp)
                {   
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
        else if(l1 == 2)
        {
            string right;

            if (input[i] == '(')
                check.push(input[i]);
            else if (input[i] == ')')
                check.pop();

            if (check.size() == 1 && input[i + 1] == '^')
            {
                for(int j = i+2; j<input.length(); j++)
                    right.push_back(input[j]);

                string pf_right;
                generate(temp, pf_temp);
                generate(right, pf_right);

                if(pf_right == pf_temp)
                {
                    // generate(temp,pf_temp);
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
    }
    return false;
}