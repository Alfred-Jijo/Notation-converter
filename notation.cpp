#include "notation.hpp"
#include <iostream>
#include <stack>
#include <string>

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
