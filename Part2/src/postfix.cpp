#include <iostream>
#include "postfix.h"
using namespace std;

void generate(string& input_taken, string& postfix)
{
    string input;/**< working input*/
    stack <char> op;/**< operator stack*/
    
    input.push_back('(');
    input.append(input_taken);
    input.push_back(')');
    
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        if (!(input[i] >= 'a' && input[i] <= 'z'))
        {
            add_stack(op, input[i]); /**< adding operator to stack*/
            if (i > 0)
                check_bracket(op, postfix); /**< check for right bracket if present then pop it after that print all elements till left bracket and  stop at left bracket and pop it*/
        }
        else
        {
            postfix.push_back(input[i]); /**< adding literals to the postfix*/
            check_negation(op, postfix); /**< checking for negation if present*/
        }
    }
    
    return;
}

void add_stack(stack<char>& op_in, char in)
{
    op_in.push(in);/**< adding operator to stack*/
}

void check_negation(stack<char>& op_check, string& postfix)
{
    if(op_check.size() == 0)
        return;/**< if stack is empty return*/
    if(op_check.top() == '~')
    {
        postfix.push_back('~');/**< prints NEGATION symbol*/
        op_check.pop();
    }
}

void check_bracket(stack<char>& op_brack, string& postfix)
{
    if(op_brack.top() == ')')
    {                  
        op_brack.pop();/**< removes the right bracket */

        while(op_brack.top() != '(')
        {                                      /**< if the function encounters a left bracket then the function will add the operator in the stack to postfix */
            postfix.push_back(op_brack.top()); /**< add the operator at top in stack to postfix */
            op_brack.pop();                    /**< removes the operator */
        }

        op_brack.pop();                    /**< you reach at left bracket so remove it */
        check_negation(op_brack, postfix); /**< checking for negation if any before the bracket */
    }
}