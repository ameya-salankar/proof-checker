// Paste this code in your editor and then work. Append the final changes here.
// Code is incomplete. Functions aren’t declared.

// check.cpp
#include <iostream>
#include <vector>
#include "postfix.h"
using namespace std;

bool check (vector<string>& v)
{
    vector<string> tr;
    bool verdict;
    int c;
    for (int i = 0; i < v.size(); ++i)
    {
        while(v[i][c] != '/') c++;
        c++;

        switch(v[i][c])
        {
            case 'P':
                tr_input(tr, v[i]);
                break;
            case '^':
                c++;
                if (v[i][c] == 'i')
                {
                    and_introduction_check(tr, v[i]);
                    break;
                }
                else if (v[i][c] == 'e')
                {
                    int k = c + 2;
                    /*
                        check if the whole statement v[v[i][k]] is in tr
                        and this line is one of its parts
                    */
                    and_elimination_check(tr, v[i]);
                }
                break;
            case 'V':
                /*
                    check if either of the constituents are in tr
                */
                or_introduction_check(tr, v[i]);
                break;
            case '>':
                int k = c + 3;
                /*
                    check if the lines p:v[v[i][k]] and
                    q:v[v[i][k+1]] are in tr
                    and q should be the left part of > in p
                */
				impl_elimination_check(tr,v[i]);
                break;
            case 'M':
                int k = c + 3;
                break;

            default:
                verdict = true;
        }
    }

    fin:
    return verdict;
}
