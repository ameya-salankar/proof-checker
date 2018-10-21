#include "or.h"
#include "helpers.h"

using namespace std;

bool or_introduction_check(vector<string> &tr, string in, int pos, vector<string>& v)
{
    string temp = string_separate(in);
    
    int l1 = (in[pos] - '0'), l2 = (in[pos + 2] - '0') - 1;
    string pf_temp, pf_sub;
    /*l1 is type of elimination and l2 is line number of the and statement*/

    stack<char> check;
    string temp_input = v[l2];
    string sub = string_separate(temp_input);
    
    generate(temp, pf_temp);
    generate(sub, pf_sub);

    cout << "sub: "<<sub<<' '<<pf_sub<<endl;
    cout << "temp: " << temp << ' ' << pf_temp<<endl;

    string left;
    string right;
    check.push('(');
    for (int i = 0; i < temp.length(); i++)
    {
        if (l1 == 1)
        {
            //something will happen
            cout<<"temp[i]: "<<temp[i]<<endl;
            left += temp[i];
            cout<<"left.push_back: "<<left<<endl;

            if (temp[i] == '(')
                check.push(temp[i]);
            else if (temp[i] == ')')
                check.pop();

            if (check.size() == 1 && temp[i + 1] == 'V')
            {
                string pf_left;
                generate(left, pf_left);
                cout<<endl<<"left: "<<left<<' '<<pf_left<<endl;
                if (pf_left == pf_sub)
                {
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
        else if (l1 == 2)
        {
            if (temp[i] == '(')
                check.push(temp[i]);
            else if (temp[i] == ')')
                check.pop();

            if (check.size() == 1 && temp[i + 1] == 'V')
            {
                for (int j = i + 2; j < temp.length(); j++)
                    right.push_back(temp[j]);

                string pf_right;
                generate(right, pf_right);

                cout << endl<< "right: " << right << ' ' << pf_right << endl;

                if (pf_right == pf_sub)
                {
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
    }
    return false;
    // string temp = string_separate(in);
    // string pf_temp;
    // int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    // generate(temp, pf_temp);
    // if (pf_temp.back() == 'V')
    // {
    //     if (is_substring(tr[l1], pf_temp))
    //     {
    //         tr.push_back(pf_temp);
    //         return true;
    //     }
    // }
    // return false;
}