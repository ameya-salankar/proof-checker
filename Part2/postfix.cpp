#include <iostream>
#include "postfix.h"
using namespace std;

void generate(string& input_taken, string& postfix)
{
    string input;//working input
    stack <char> op;//operator stack
    
    input.push_back('(');
    input.append(input_taken);
    input.push_back(')');
    
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        if (!(input[i] >= 'a' && input[i] <= 'z'))
        {
            add_stack(op, input[i]); //adding operator to stack
            if (i > 0)
                check_bracket(op, postfix); //check for right bracket if present then pop it after that print all elements till left bracket and  stop at left bracket
        }
        else
        {
            postfix.push_back(input[i]); //adding literals to the postfix
            check_negation(op, postfix); //checking for negation after postfix
        }
    }
    


    // cout << "final postfix : " << postfix << endl;

    return;
}

void add_stack(stack<char>& op_in, char in)
{
    op_in.push(in);//ADDING OPERATOR TO STACK 
}

void check_negation(stack<char>& op_check, string& postfix)
{
    if(op_check.size() == 0)
        return;//iF NEGATION IS THE FIRST ELEMENT WE DON'T WANT TO PRINT IT
    if(op_check.top() == '~')
    {
        postfix.push_back('~');//AGAR NEGATION HAI TO USKO PRINT KARNA HAI ISLIYE
        op_check.pop();
    }
}

void check_bracket(stack<char>& op_brack, string& postfix)
{
    if(op_brack.top() == ')')
    {//If i find right bracket 
        op_brack.pop();//first remove it
        
        while(op_brack.top() != '(')
        {//till i dont find left bracket
            postfix.push_back(op_brack.top());//add the operator at top in stack to postfix
            op_brack.pop();//then remove it
        }
        
        op_brack.pop();//you reach at left bracket so remove it
        check_negation(op_brack,postfix);//checking for negation if any before the bracket
    }
}