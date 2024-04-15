#include <iostream>
#include <stack>
#include <string>

int precedence(char op);
bool IsOperand(char c);
bool IsOperator(char c);
std::string convert(std::string infix);
bool eqlOrhigher(char op1, char op2);

int main() {
  std::string infix_expression, postfix_expression;
  std::string choice;
  do {
    std::cout << "Infix Ex:" << std::endl;
    std::getline(std::cin, infix_expression);
    postfix_expression = convert(infix_expression);
    std::cout << "Postfix Ex:" << postfix_expression << std::endl;
    std::cout << "\t Covert another? (Y/N)" << std::endl;
  } while (choice.compare("N") == 0);
}

int precedence(char op) {
  if (op == '+' || op == '-') /* it defines the lowest precedence */
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^') /* exponent operator has the highest precedence */
    return 3;
  return 0;
}

bool IsOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    return true;
  }
  return false;
}

bool IsOperand(char c) {
  if (c >= 'A' && c <= 'Z') /* Define the character in between A to Z. If not,
                               it returns False.*/
    return true;
  if (c >= 'a' && c <= 'z') // Define the character in between a to z. If not,
                            // it returns False. */
    return true;
  if (c >= '0' && c <= '9') // Define the character in between 0 to 9. If not,
                            // it returns False. */
    return true;
  return false;
}

bool eqlOrhigher(char op1, char op2) {
  int p1 = precedence(op1);
  int p2 = precedence(op2);
  if (p1 == p2) {
    if (op1 == '^')
      return false;
    return true;
  }
  return (p1 > p2 ? true : false);
}

/* string convert() function is used to convert the infix expression to the
 * postfix expression of the Stack */

std::string convert(std::string infix) {
  std::stack<char> S;
  std::string postfix = "";
  char ch;

  S.push('(');
  infix += ')';

  for (int i = 0; i < infix.length(); i++) {
    ch = infix[i];

    if (ch == ' ')
      continue;
    else if (ch == '(')
      S.push(ch);
    else if (IsOperand(ch))
      postfix += ch;
    else if (IsOperator(ch)) {
      while (!S.empty() && eqlOrhigher(S.top(), ch)) {
        postfix += S.top();
        S.pop();
      }
      S.push(ch);
    } else if (ch == ')') {
      while (!S.empty() && S.top() != '(') {
        postfix += S.top();
        S.pop();
      }
      S.pop();
    }
  }
  return postfix;
}
