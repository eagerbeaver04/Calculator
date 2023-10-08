#include "Parser.h"


int Parser::opPriority(const std::string& symbol)
{
    return this->operations->getPriority(symbol);
}

bool Parser::opAssociativity(const std::string& symbol)
{
	return this->operations->getAssociativity(symbol);
}

int Parser::opBinary(const std::string& symbol)
{
	return this->operations->getBinary(symbol);
}

bool Parser::isOperator(const std::string& symbol)
{
    if (symbol == "(" || symbol == ")")
        return false;
	bool acc = this->opAssociativity(symbol);
	int bin = this->opBinary(symbol);
	if ((acc == true && bin == 2) || (acc == false && bin == 1) )
		return true;
	return false;
}

bool Parser::isFunction(const std::string& symbol)
{
    if (symbol == "(" || symbol == ")")
        return false;
    if (this->opAssociativity(symbol) == true && this->opBinary(symbol) == 1)
        return true;
	return false;
}

bool Parser::isIdent(const std::string& symbol)
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

bool Parser::isLetter(const std::string& symbol)
{
    return (symbol >= "a" && symbol <= "z");
}

double Parser::calculation(const std::string& symbol, double a, double b)
{
    return this->operations->calculation(symbol, a, b);
}

bool Parser::parse(const std::string& input, std::string& output)
{
    std::stack<std::string> operations_;
    int length = input.length();
    output = "";
    for (int i = 0; i < length; ++i) 
    {
        char current_symbol = input[i];
        std::string current_substring = { current_symbol };
        if (current_substring != " ") 
        {
            if (current_symbol == '(')
                operations_.push(current_substring);
            else if (current_symbol == ')')
            {
                std::string symbols;
                while (!operations_.empty())
                {
                    symbols = operations_.top();
                    operations_.pop();
                    if (symbols == "(")
                        break;
                    else
                        output += symbols + "|";
                }
                if (operations_.empty() && symbols != "(")
                {
                    std::cerr << "Error: parentheses mismatched" << std::endl;
                    return false;
                }
                if (!operations_.empty())
                {
                    symbols = operations_.top();
                    if (isFunction(symbols))
                    {
                        output += symbols + "|";
                        operations_.pop();
                    }
                }
            }
            else if (isIdent(current_symbol))
            {
                int j = 0;
                while (j < length)
                {
                    j = i + 1;
                    char c_current = input[j];
                    if (isIdent(c_current) || c_current == '.')
                        current_substring += c_current;
                    else
                        break;
                    i++;
                }
                output += std::to_string(stod(current_substring)) + "|";
            }
            else if (isLetter(current_substring))
            {
                int j = i + 1;
                char c_current = input[j];
                while (j<length)
                {
                    j = i + 1;
                    char c_current = input[j];
                    if (isLetter(c_current))
                        current_substring += c_current;
                    else
                        break;
                    i++;
                }
                if (isFunction(current_substring))
                    operations_.push(current_substring);
            }
            else if (isOperator(current_substring)) 
            {
                while (!operations_.empty())
                {
                    std::string sc = operations_.top();
                    std::string sc_str = { sc };
                    if (isOperator(sc_str) && ((opAssociativity(current_substring) && (opPriority(current_substring) <= opPriority(sc_str))) ||
                        (!opAssociativity(current_substring) && (opPriority(current_substring) < opPriority(sc_str))))) 
                    {
                        output += sc_str +"|";
                        operations_.pop();
                    }
                    else
                        break;
                }
                operations_.push(current_substring);
            }            
            else 
            {
                std::cerr << "Unknown token in" << current_substring << std::endl;
                return false;
            }
        }
    }
    while (!operations_.empty()) 
    {
        std::string sc = operations_.top();
        operations_.pop();
        if (sc == "(" || sc == ")") 
        {
            std::cerr << "Error: parentheses mismatched" << std::endl;
            return false;
        }
        output += sc + "|";
    }
    return true;
}

bool Parser::evaluate(const std::string& input)
{
    int const length = input.length();
    std::vector<std::string> operations_(length);
    std::vector < double > values(length);
    int sl = 0;
    int rn = 0;
    for (int i = 0; i < length; ++i) 
    {
        char current_symbol = input[i];
        std::string current_substring = { current_symbol };
        if (isIdent(current_substring)) 
        {
            double value;
            char c_current = input[i+1];
            while (c_current != '|')
            {

                current_substring += c_current;
                i++;
                c_current = input[i+1];
            }
            i++;
            std::istringstream(current_substring) >> value;
            operations_[sl] = current_substring;
            values[sl] = value;
            ++sl;
        }
        else 
        {
            if (isLetter(current_substring))
            {
                char c_current = input[i + 1];
                while (c_current != '|')
                {
                    current_substring += c_current;
                    i++;
                    c_current = input[i + 1];
                }
                operations_[sl] = current_substring;
            }
            i++;
            if (isOperator(current_substring) || isFunction(current_substring)) 
            {
                int arguments = opBinary(current_substring);
                double value = 0;
                std::string res = "(" +  std::to_string(rn++) + ")";
                std::cout << res << " = ";

                if (sl < arguments) 
                {
                    std::cerr << "Error: insufficient arguments in expression" << std::endl;
                    return false;
                }

                if (arguments == 1)
                {
                    std::string sc = operations_[sl - 1];
                    double sc2 = values[sl - 1];
                    sl--;
                    value = calculation(current_substring, sc2, 0);
                    if(opAssociativity(current_substring))
                        std::cout << current_substring << " " << sc << " = " << value << std::endl;
                    else
                        std::cout  << sc << " " << current_substring  << " = " << value << std::endl;
                }
                else
                {
                    std::string sc1 = operations_[sl - 2];
                    double sc21 = values[sl - 2];
                    std::cout << sc1 << " " << current_symbol << " ";
                    std::string sc2 = operations_[sl - 1];
                    double sc22 = values[sl - 1];
                    value = calculation(current_substring, sc21, sc22);
                    std::cout << sc2 << " = " << value << std::endl;
                    sl -= 2;
                }
                operations_[sl] = res;
                values[sl] = value;
                ++sl;
            }
        }
    }

    if (sl == 1) 
    {
        std::string sc = operations_[sl - 1];
        double sc1 = values[sl - 1];
        sl--;
        std::cerr << "Result : " << sc << " = " << sc1 << std::endl;
        return true;
    }

    std::cerr << "Error: too many values entered by the user" << std::endl;
    return false;
}


