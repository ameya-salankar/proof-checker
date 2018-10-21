// Paste this code in your editor and then work. Append the final changes here.
// Code is incomplete. Functions aren’t declared.

// check.cpp
#include <iostream>
#include <vector>
#include "helpers.h"
#include "and.h"
#include "or.h"
#include "impl.h"

using namespace std;

bool check (vector<string>& v)
{
    vector<string> tr;
    bool verdict=false;
    int c=0, k=0;
    // cout << "Iwashere";
    for (int i = 0; i < v.size(); ++i)
    {   c = 0;
        // cout << "Iwashere"<<endl;
        while (c < v[i].length() && v[i][c] != '/'){
            cout<<v[i][c];
            c++;
            
        } 

        c++;

        switch(v[i][c])
        {
            case 'P':
                tr_input(tr, v[i]);
                verdict = true;
                break;
            
            
            case '^':
                c++;
                if (v[i][c] == 'i')
                {
                    k = c + 2;
                    cout << "I was here";
                    verdict = and_introduction_check(tr, v[i], k);
                    // if (!verdict)
                    //     return verdict;
                    // break;
                }
                else if (v[i][c] == 'e')
                {
                    k = c + 1;
                    /*
                        check if the whole statement v[v[i][k]] is in tr
                        and this line is one of its parts
                    */
                    verdict = and_elimination_check(tr, v[i], k, v);
                }
                if (!verdict)
                    return verdict;
                break;
            
            
            case 'V':
                k = c + 2;
                /*
                    check if either of the constituents are in tr
                */
                verdict = or_introduction_check(tr, v[i], k, v);
                if (!verdict)
                    return verdict;
                break;
            
            
            case '>':
                k = c + 3;
                /*
                    check if the lines p:v[v[i][k]] and
                    q:v[v[i][k+1]] are in tr
                    and q should be the left part of > in p
                */
				verdict = impl_elimination_check(tr, v[i], k);
                if (!verdict)
                    return verdict;
                break;
            
            
            case 'M':
                k = c + 3;
                verdict = mt_check(tr, v[i], k);
                if (!verdict)
                    return verdict;
                break;

            default:
                verdict = true;
        }
    }
    for(int i=0;i<tr.size();i++){
        cout<<endl<<"tr: "<<endl<<tr[i]<<endl;
    }
    // fin:
    return verdict;
}
