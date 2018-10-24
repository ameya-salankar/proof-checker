#include "impl.h"
#include "helpers.h"

using namespace std;
/**
 * \brief Takes the proof statement and checks for validity of implication elimination 
 * \param in string argument
 * \param tr universal truth vector
 * \param l1 integer argument line number telling about the implication statement
 * \param l2 integer argument line number
 * \return boolean validity of the proof statement 
 */
bool impl_elimination_check(vector<string> &tr, string in, int l1, int l2)
{
    string temp = string_separate(in), pf_temp;
    generate(temp, pf_temp);
    
    if (tr[l1].back() == '>')
    {    
        string correct  = tr[l2];
        correct.append(pf_temp);
        correct.push_back('>');
    
        if (correct == tr[l1])
        {
            tr.push_back(pf_temp);
            return true;        
        }
    }
    
    return false;
}
/**
 * \brief Takes the proof statement and checks for modus tollens
 * \param in string argument
 * \param tr universal truth vector
 * \param l1 integer argument 
 * \param l2 integer argument
 * \return boolean validity of the proof statement
 */
bool mt_check(vector<string> &tr, string in, int l1, int l2)
{
    string temp = string_separate(in), pf_temp;
    generate(temp, pf_temp);
    pf_temp.pop_back();
    
    string pf_right = tr[l2];
    pf_right.pop_back();

    if (tr[l1].back() == '>')
    {
        string correct = pf_temp;
        correct.append(pf_right);
        correct.push_back('>');

        if (correct == tr[l1])
        {
            pf_temp.push_back('~');
            tr.push_back(pf_temp);
            return true;
        }
    }

    return false;
}