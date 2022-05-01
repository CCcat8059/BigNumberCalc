#include "FrontEndAnalyze.h"
bool inputIsValid(std::string input) {
    bool doubleOperator = 0;
    bool hasAlpha = 0;
    
}

int priority(std::string alpha) {
    if (alpha == "+" || alpha == "-")
        return 1;

    if (alpha == "*" || alpha == "/")
        return 2;

    if (alpha == "^")
        return 3;


    return 0;
} 
BigNumber convert(std::string infix) {
    std::stack<std::string> op;
    std::stack<BigNumber> num;
    std::stringstream ss;
    std::string temp;
    ss << infix;
    while (ss.good()) {
        ss >> temp;
        if (isBigNumber(temp)) {
            BigNumber tempBN(temp);
            num.push(tempBN);
        }
        else {
            if (temp == "(") {
                op.push(temp);
            }
            else if (temp == ")") {
                while (op.top() != "(") {
                    BigNumber a, b;
                    b = num.top();
                    num.pop();
                    a = num.top();
                    num.pop();
                    num.push(Caculate(a, b, op.top()));
                    op.pop();
                }
                op.pop();
            }
            else {
                while (!op.empty() && priority(temp) <= priority(op.top())) {
                    BigNumber a, b;
                    b = num.top();
                    num.pop();
                    a = num.top();
                    num.pop();
                    num.push(Caculate(a, b, op.top()));
                    op.pop();
                }
                op.push(temp);
            }
        }
    }
    while (!op.empty()) {
        BigNumber a, b;
        b = num.top();
        num.pop();
        a = num.top();
        num.pop();
        num.push(Caculate(a, b, op.top()));
        op.pop();
    }
    return num.top();
}
/*
BigNumber convert(std::string infix)
{
    int i = 0;
    std::deque<BigNumber> postfix;
    //std::string postfix = "";
    // using inbuilt stack< > from C++ stack library
    std::stack<std::string> sTemp;
    std::deque<std::string> s;

    std::stringstream ss;
    ss << infix;
    //std::cout << ss.str() << std::endl;
    while (ss.good())
    {
        // if operand add to the postfix expression
        std::string temp;
        ss >> temp;
        std::cout << temp << std::endl;
        if (isBigNumber(temp))
        {
            postfix.push_back(temp);
        }
        // if opening bracket then push the stack
        else if (temp == "(")
        {
            sTemp.push(temp);
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if (temp == ")")
        {
            while (sTemp.top() != "(") {

                s.push_back(sTemp.top());
                sTemp.pop();
            }
            sTemp.pop();
        }
        else
        {
            while (!sTemp.empty() && priority(temp) <= priority(sTemp.top())) {
                s.push_back(sTemp.top());
                sTemp.pop();
            }
            sTemp.push(temp);
        }
    }
    while (!sTemp.empty()) {
        std::cout << sTemp.top() << " ";
        s.push_back(sTemp.top());
        sTemp.pop();
    }

    //----------output test----------------
    std::cout << "HERE" << std::endl;
    while (!postfix.empty()) {
        std::cout << postfix.front() << " ";
        postfix.pop_front();
    }
    std::cout << std::endl;
    while (!s.empty()) {
        std::cout << s.front() << " ";
        s.pop_front();
    }
    //----------calculate----------------
    BigNumber BN(0);
    return BN;
}
*/

bool isBigNumber(std::string num)
{
    for (int i = 0; i < num.size(); i++) {
        if (isdigit(num[i]) || num[i] == '.') {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

BigNumber Caculate(const BigNumber& a, const BigNumber& b, std::string symbol)
{
    BigNumber result;
    if (symbol == "+") {
        result = a + b;
    }
    else if (symbol == "-") {
        result = a - b;
    }
    else if (symbol == "*") {
        result = a * b;
    }
    else if (symbol == "/") {
        result = a / b;
    }
    else if (symbol == "%") {
        result = a % b;
    }
    // -------------------------------
    // ÁÙ¦³power
    // -------------------------------
    return result;
}

