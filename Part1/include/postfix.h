#include <stack>
#include <string>

using namespace std;

/**< all the functions being used to generate the postfix*/
void signal_handler(int signal_num);                        /** handles the segfaults generated in check_bracket()*/
void add_stack(stack<char> &op_in, char in);                /** adds operator to stack */
void check_negation(stack<char>& op_check, string& postfix);/** checks for negation */
void check_bracket(stack<char>& op_brack, string& postfix); /** checks for right bracket */
void generate(string& input_taken, string& postfix);        /** the main postfix generating function */