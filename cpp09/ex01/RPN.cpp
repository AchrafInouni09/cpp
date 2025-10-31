#include "RPN.hpp"
#include <sstream>
#include <iostream>

int RPN::evaluate(const std::string &expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]))
        {
            std::istringstream numStream(token);
            int number;
            numStream >> number;
            stack.push(number);
        } else if (isOperator(token))
        {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: insufficient operands");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(performOperation(token, a, b));
        } else
        {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }

    return stack.top();
}

bool RPN::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(const std::string &op, int a, int b) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Error: division by zero");
        }
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}