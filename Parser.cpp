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
	int bin = this->opBinary(symbol);
	if ((acc == true && bin == 2) || (acc == false && bin == 1))
		return true;
	return false;
}


bool Parser::isFunction(std::string symbol)
{
    if (symbol == "(" || symbol == ")")
        return false;
    if (this->opAssociativity(symbol) == true && this->opBinary(symbol) == 1)
        return true;
	return false;
}

bool Parser::isIdent(std::string symbol) 
{
	return (symbol >= "0" && symbol <= "9");
}

bool Parser::isIdent(char symbol) 
{
    return (symbol >= '0' && symbol <= '9');
}

bool Parser::isLetter(char symbol) 
{
    return (symbol >= 'a' && symbol <= 'z');
}

bool Parser::isLetter(std::string symbol)
{
    return (symbol >= "a" && symbol <= "z");
}

bool Parser::shuntingYard(const std::string& input, std::string& output)
{
    bool interruotion = false;
    std::stack<std::string> op_stack;
    int length = input.length();
    output = "";
    for (size_t i = 0; i < length; ++i) 
    {
        if (interruotion == true)
        {
            std::cerr << " Process was interrupted" << std::endl;
            std::cerr << " Please, rewrite expression" << std::endl;
            return false;
        }
        char c = input[i];
        std::string c_str = { c };
        if (c_str != " ") 
        {
            if (c == '(')
            {
                op_stack.push(c_str);
            }
            else if (c == ')')
            {
                bool pe = false;
                while (!op_stack.empty())
                {
                    std::string sc = op_stack.top();
                    op_stack.pop();
                    if (sc == "(")
                    {
                        pe = true;
                        break;
                    }
                    else
                        output += sc + "|";
                }
                if (!pe)
                {
                    std::cout << "Error: parentheses mismatched" << std::endl;
                    interruotion = true;
                    return false;
                }
                if (!op_stack.empty())
                {
                    std::string sc = op_stack.top();
                    if (isFunction(sc))
                    {
                        output += sc + "|";
                        op_stack.pop();
                    }
                }
            }
            else if (isIdent(c))
            {
                int j = 0;
                int dot_flag = 0;
                while (j < length)
                {
                    j = i + 1;
                    char c_current = input[j];
                    if (c_current == '.')
                    {
                        dot_flag++;
                        if (dot_flag < 2)
                            c_str += c_current;
                        else
                        {
                            std::cerr << " More than one dote in number :" << c_str << std::endl;
                            interruotion = true;
                            break;
                        }
                    }
                    else if (isIdent(c_current))
                        c_str += c_current;
                    else
                        break;
                    i++;
                }
                output += c_str + "|";
            }
            else if (isLetter(c_str))
            {
                int j = i + 1;
                char c_current = input[j];
                while (j<length)
                {
                    j = i + 1;
                    char c_current = input[j];
                    if (isLetter(c_current))
                        c_str += c_current;
                    else
                        break;
                    i++;
                }
                if (isFunction(c_str))
                    op_stack.push(c_str);
            }
            else if (isOperator(c_str)) 
            {
                while (!op_stack.empty()) 
                {
                    std::string sc = op_stack.top();
                    std::string sc_str = { sc };
                    if (isOperator(sc_str) && ((opAssociativity(c_str) && (opPriority(c_str) <= opPriority(sc_str))) ||
                        (!opAssociativity(c_str) && (opPriority(c_str) < opPriority(sc_str))))) 
                    {
                        output += sc_str +"|";
                        op_stack.pop();
                    }
                    else
                        break;
                }
                op_stack.push(c_str);
            }            
            else 
            {
                std::cout << "Unknown token in" << c_str << std::endl;
                interruotion = true;
                return false;
            }
        }
    }
    while (!op_stack.empty()) {
        std::string sc = op_stack.top();
        op_stack.pop();
        if (sc == "(" || sc == ")") 
        {
            std::cout << "Error: parentheses mismatched" << std::endl;
            interruotion = true;
            return false;
        }
        output += sc + "|";
    }
    return true;
}

bool Parser::executionOrder(const std::string& input) 
{
    std::cout << "order: (arguments in reverse order)" << std::endl;
    std::string stack[32];
    int length = input.length();
    int sl = 0;
    int rn = 0;
    for (size_t i = 0; i < length; ++i) 
    {
        char c = input[i];
        std::string c_str = { c };
        if (isIdent(c_str)) 
        {
            char c_current = input[i+1];
            while (c_current != '|')
            {

                c_str += c_current;
                i++;
                c_current = input[i+1];
            }
            i++;
            stack[sl] = c_str;
            ++sl;
        }
        else 
        {
            if (isLetter(c_str))
            {
                char c_current = input[i + 1];
                while (c_current != '|')
                {

                    c_str += c_current;
                    i++;
                    c_current = input[i + 1];
                }
                stack[sl] = c_str;
            }
            i++;
            if (isOperator(c_str) || isFunction(c_str)) 
            {
                int nargs = opBinary(c_str);
                std::cout << nargs << std::endl;
                int Tnargs = nargs;
                std::string res = "_" + std::to_string(rn++);
                std::cout << res << " = ";

                if (sl < nargs) 
                {
                    std::cout << "Error: insufficient arguments in expression" << std::endl;
                    return false;
                }

                if (nargs == 1)
                {
                    std::string sc = stack[sl - 1];
                    sl--;
                    std::cout << c_str << " " << sc << ";" << std::endl;
                }
                else
                {
                    std::string sc1 = stack[sl - 2];
                    std::cout << sc1 << " " << c << " ";
                    std::string sc2 = stack[sl - 1];
                    std::cout << sc2 << ";" << std::endl;
                    sl -= 2;
                }
                stack[sl] = res;
                ++sl;
            }
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

