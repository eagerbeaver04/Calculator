#include "Parser.h"
#include <stack>

int Parser::opPriority(std::string symbol)
{
	return this->operaions_map->getPriority(symbol);
}

bool Parser::opAssociativity(std::string symbol)
{
	return this->operaions_map->getAssociativity(symbol);
}

int Parser::opBinary(std::string symbol)
{
	return this->operaions_map->getBinary(symbol);
}

bool Parser::isOperator(std::string symbol)
{
    if (symbol == "(" || symbol == ")")
        return false;
	bool acc = this->opAssociativity(symbol);
	bool bin = this->opBinary(symbol);
	if ((acc == true && bin == true) || (acc == false && bin == false))
		return true;
	return false;
}

bool Parser::isFunction(std::string symbol)
{
	if (this->opAssociativity(symbol) == true && this->opBinary(symbol) == 1)
		return true;
	return false;
}

bool Parser::isIdent(std::string symbol) //only for integer
{
	return (symbol >= "0" && symbol <= "9");
}

bool Parser::shuntingYard(const std::string& input, std::string& output)
{
    std::stack<char> op_stack;
    output = "";
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        std::string c_str = { c };
        if (c != ' ') 
        {
            if (c == '(')
            {
            op_stack.push(c);
            }
            else if (c == ')')
            {
                bool pe = false;
                while (!op_stack.empty()) {
                    char sc = op_stack.top();
                    op_stack.pop();
                    if (sc == '(') {
                        pe = true;
                        break;
                    }
                    else {
                        output += sc;
                    }
                }
                if (!pe) {
                    std::cout << "Error: parentheses mismatched" << std::endl;
                    return false;
                }
                if (!op_stack.empty()) {
                    char sc = op_stack.top();
                    std::string sc_str = { sc };
                    if (isFunction(sc_str)) {
                        output += sc;
                        op_stack.pop();
                    }
                }
            }
            else if (isIdent(c_str)) {
                output += c;
            }
            else if (isFunction(c_str)) {
                op_stack.push(c);
            }
            else if (c == ',') {
                bool pe = false;
                while (!op_stack.empty()) {
                    char sc = op_stack.top();
                    op_stack.pop();
                    if (sc == '(') {
                        pe = true;
                        break;
                    }
                    else {
                        output += sc;
                    }
                }
                if (!pe) {
                    std::cout << "Error: separator or parentheses mismatched" << std::endl;
                    return false;
                }
            }
            else if (isOperator(c_str)) {
                while (!op_stack.empty()) {
                    char sc = op_stack.top();
                    std::string sc_str = { sc };
                    if (isOperator(sc_str) && ((opAssociativity(c_str) && (opPriority(c_str) <= opPriority(sc_str))) || (!opAssociativity(c_str) && (opPriority(c_str) < opPriority(sc_str))))) {
                        output += sc;
                        op_stack.pop();
                    }
                    else {
                        break;
                    }
                }
                op_stack.push(c);
            }        
            else {
                std::cout << "Unknown token " << c << std::endl;
                return false;
            }
        }
    }
    while (!op_stack.empty()) {
        char sc = op_stack.top();
        op_stack.pop();
        if (sc == '(' || sc == ')') {
            std::cout << "Error: parentheses mismatched" << std::endl;
            return false;
        }
        output += sc;
    }
    return true;
}

bool Parser::executionOrder(const std::string& input) 
{
    //std::cout << "order: (arguments in reverse order)" << std::endl;
    std::string stack[32];
    int sl = 0;
    int rn = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        std::string c_str = { c };
        if (isIdent(c_str)) {
            stack[sl] = c;
            ++sl;
        }
        else if (isOperator(c_str) || isFunction(c_str)) {
            std::string res = "_" + std::to_string(rn++);
            //std::cout << res << " = ";
            int nargs = opBinary(c_str);
            int Tnargs = nargs;
            if (sl < nargs) {
                std::cout << "Error: insufficient arguments in expression" << std::endl;
                return false;
            }
            if (isFunction(c_str)) {
                std::cout << c << "(";
                while (nargs > 0) {
                    std::string sc = stack[sl - nargs];
                    if (nargs > 1) {
                        std::cout << sc << ", ";
                    }
                    else {
                        std::cout << sc << ")" << std::endl;
                    }
                    --nargs;
                }
                sl -= Tnargs;
            }
            else {
                if (nargs == 1) {
                    std::string sc = stack[sl - 1];
                    sl--;
                    //std::cout << c << " " << sc << ";" << std::endl;
                }
                else {
                    std::string sc1 = stack[sl - 2];
                    //std::cout << sc1 << " " << c << " ";
                    std::string sc2 = stack[sl - 1];
                    //std::cout << sc2 << ";" << std::endl;
                    sl -= 2;
                }
            }
            stack[sl] = res;
            ++sl;
        }
    }
    if (sl == 1) {
        std::string sc = stack[sl - 1];
        sl--;
        //std::cout << sc << " is a result" << std::endl;
        return true;
    }
    std::cout << "Error: too many values entered by the user" << std::endl;
    return false;
}


