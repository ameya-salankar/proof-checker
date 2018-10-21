#include "impl.h"
#include "helpers.h"

using namespace std;

bool impl_elimination_check(vector<string> &tr, string in, int pos)
{
    // int pos = in[k] - '0';
    string temp = string_separate(in);
    string pf_temp;
    generate(temp, pf_temp);
    int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    // cout<<"tr[l1]: "<<tr[l1]<<endl;
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
        cout<<"correct: "<<endl;
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
    string temp = string_separate(in);
    string pf_temp;
    generate(temp, pf_temp);
    pf_temp.pop_back();
    
    int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;

    string pf_right = tr[l2];
    pf_right.pop_back();
    
    cout<<"tr[l1]: "<<tr[l1]<<endl;
    cout<<"pf_temp: "<<pf_temp<<endl;
    cout<<"pf_right: "<<pf_right<<endl;
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
        cout << endl<<"correct: " <<correct<<endl;
        if (correct == tr[l1])
        {
            pf_temp.push_back('~');
            tr.push_back(pf_temp);
            return true;
        }
    }
    return false;
    // string temp = string_separate(in);
    // string pf_temp;
    // generate(temp, pf_temp);
    // pf_temp.pop_back();
    // int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
    // string pro = tr[l2];
    // pro.pop_back();

    // if (is_substring(pf_temp, tr[l1]) && is_substring(pro, tr[l1]))
    // {
    //     if (check_impl_right(pro, tr[l1], l))
    //     {
    //         if (check_impl_left(pf_temp, tr[l1]))
    //         {
    //             tr.push_back(pf_temp);
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

// bool check_impl_left(string part, string whole)
// {
//     int l = part.length(), l2 = whole.length(), i, j;
//     for (i = 0, j = 0; i < l && j < l2; i++, j++)
//     {
//         if (part[i] != whole[j])
//             break;
//     }

//     if (i == l)
//         return true;
//     else
//         return false;
// }

// bool check_impl_right(string part, string whole, int start)
// {
//     int l = part.length(), l2 = whole.length(), i, j;
//     for (i = 0, j = start; i < l && j < l2; i++, j++)
//     {
//         if (part[i] != whole[j])
//             break;
//     }

//     if (i == l)
//         return true;
//     else
//         return false;
// }