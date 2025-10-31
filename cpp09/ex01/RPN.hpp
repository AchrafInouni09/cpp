#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    int evaluate(const std::string &expression);

private:
    bool isOperator(const std::string &token) const;

    int performOperation(const std::string &op, int a, int b) const;
};

#endif