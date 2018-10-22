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
    bool verdict = false;
    int c = 0, k = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        c = 0;

        while (c < v[i].length() && v[i][c] != '/')
        {
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
                    verdict = and_introduction_check(tr, v[i], k);
                }
                else if (v[i][c] == 'e')
                {
                    k = c + 1;
                    verdict = and_elimination_check(tr, v[i], k, v);
                }

                if (!verdict)
                    return verdict;
                break;

            case 'V':
                k = c + 2;
                
                verdict = or_introduction_check(tr, v[i], k, v);
                
                if (!verdict)
                    return verdict;
                break;
            
            
            case '>':
                k = c + 3;

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

    // fin:
    return verdict;
}
