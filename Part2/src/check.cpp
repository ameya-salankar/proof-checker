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
    int c = 0, k = 0, l1, l2;

    for (int i = 0; i < v.size(); ++i)
    {
        c = v[i].find('/');       
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
                    c++; //Pass at '/'
                    l1 = extract(v[i], c);
                    l2 = extract(v[i], c);
                    verdict = and_introduction_check(tr, v[i], l1-1, l2-1);
                }
                else if (v[i][c] == 'e')
                {
                    l1 = extract(v[i], c);
                    l2 = extract(v[i], c);
                    verdict = and_elimination_check(tr, v[i], l1, l2-1, v);
                }

                if (!verdict)
                    return verdict;
                break;

            case 'V':
                c++;
                l1 = extract(v[i], c);
                l2 = extract(v[i], c);
                verdict = or_introduction_check(tr, v[i], l1, l2-1, v);
                
                if (!verdict)
                    return verdict;
                break;
            
            
            case '>':
                c += 2;
                l1 = extract(v[i], c);
                l2 = extract(v[i], c);
                verdict = impl_elimination_check(tr, v[i], l1-1, l2-1);

                if (!verdict)
                    return verdict;
                break;
            
            
            case 'M':
                c += 2;
                l1 = extract(v[i], c);
                l2 = extract(v[i], c);
                verdict = mt_check(tr, v[i], l1, l2-1);

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
