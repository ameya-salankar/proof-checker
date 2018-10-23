#include <stack>
#include <string>

using namespace std;

/**< all the functions being used */
void add_stack(stack<char>& op_in, char in);/**< adds operator to stack nothing else */
void check_negation(stack<char>& op_check, string& postfix);/**< checks for negation */
void check_bracket(stack<char>& op_brack, string& postfix);/**< checks for right bracket */
void generate(string& input_taken, string& postfix);