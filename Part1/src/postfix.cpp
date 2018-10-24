#include <iostream>
#include <csignal>
#include "postfix.h"

using namespace std;

/**
 * \brief Handles the segfaults generated in the check_bracket function
 * \param signal_num the signal code of SIGSEGV
*/
void signal_handler(int signal_num)
{
    cout << "\nInvalid input.\nPlease input a well-formed formula and try again."  << endl;
    exit(signal_num);
}

/**
 * \brief Takes two string arguments and generates postfix string
 * \param input_taken a string argument
 * \param postfix a string argument
*/
void generate(string & input_taken, string & postfix)
{
    string input;
    stack<char> op;

    input.push_back('(');
    input.append(input_taken);
    input.push_back(')');

    int n = input.size();

    for (int i = 0; i < n; i++)
    {
        if (!(input[i] >= 'a' && input[i] <= 'z'))
        {
            add_stack(op, input[i]); /** adding operator to stack */
            if (i > 0)
                check_bracket(op, postfix); /** check for right bracket, if present then pop it after that print all elements till left bracket and  stop at left bracket */
        }
        else
        {
            postfix.push_back(input[i]); /** adding literals to the postfix */
            check_negation(op, postfix); /** checking for negation after postfix */
        }
    }

    return;
}

/**
 * \brief takes a character argument and adds it to the operator stack
 * \param op a stack
 * \param in charachter argument
 * \sa generate(), check_negation(), check_bracket()
 */
void add_stack(stack<char> & op_in, char in)
{
    op_in.push(in); /** adding operator to stack */
}

 /**
 * \brief takes the operator stack and checks for presence of negation operator
 * \param op a stack
 * \param postfix string argument
 * \sa generate(), add_stack(), check_bracket()
*/
void check_negation(stack<char> & op_check, string & postfix)
{
    if (op_check.size() == 0)
        return; /** if stack is empty return*/
    if (op_check.top() == '~')
    {
        postfix.push_back('~'); /** print the negation symbol */
        op_check.pop();
    }
}

/**
 * \brief takes the operator stack and checks for presence of closing { ')' } bracket
 * \param op a stack
 * \param postfix string argument
 * \sa generate(), add_stack(), check_negation()
*/
void check_bracket(stack<char> & op_brack, string & postfix)
{
    signal(SIGSEGV, signal_handler);

    if (op_brack.top() == ')')
    {                   /** if function encounters a right bracket then it will remove a left bracket  */
        op_brack.pop(); /** removes the right bracket */

        while (op_brack.top() != '(')
        {                                      /** if the function encounters a left bracket then the function will add the operator in the stack to postfix */
            postfix.push_back(op_brack.top()); /** add the operator at top in stack to postfix */
            op_brack.pop();                    /** removes the operator */
        }

        op_brack.pop();                    /** you reach at left bracket so remove it */
        check_negation(op_brack, postfix); /** checking for negation if any before the bracket */
    }
}