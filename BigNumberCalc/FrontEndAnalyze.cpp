#include "FrontEndAnalyze.h"

bool inputIsValid(std::string input)
{
	if (input.empty())
	{
		std::cout << "Error: Input is empty." << std::endl;
		return false;
	}

	bool alphaFlag = false, invalidSymbol = false;
	// alpha or not symbol of operation is unacceptable.
	for (int i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]) || input[i] == '.' || input[i] == ' ')
			continue;
		else if (isSymbol(input[i]))
			continue;
		else if (isalpha(input[i]))
			alphaFlag = true;
		else
			invalidSymbol = true;
	}
	if (alphaFlag || invalidSymbol)
	{
		if (alphaFlag)
			std::cout << "Error: Input is invalid, using alpha." << std::endl;

		if (invalidSymbol)
			std::cout << "Error: Input is invalid, using invalid symbol" << std::endl;

		return false;
	}
	return true;
}

std::string replace(std::string input)
{
	std::string output = "";
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '+')
			output += " + ";
		else if (input[i] == '-')
			output += " - ";
		else if (input[i] == '*')
			output += " * ";
		else if (input[i] == '/')
			output += " / ";
		else if (input[i] == '(')
			output += " ( ";
		else if (input[i] == ')')
			output += " ) ";
		else if (input[i] == '!')
			output += " ! ";
		else if (input[i] == '^')
			output += " ^ ";
		else if (input[i] == '%')
			output += " % ";
		else
			output += input[i];
	}
	return output;
}

bool isSymbol(char in)
{
	if (in == '+' || in == '-' || in == '*' || in == '/' ||
		in == '(' || in == ')' || in == '^' || in == '%' ||
		in == '!')
	{
		return true;
	}
	return false;
}

std::string format(std::string input)
{
	std::string output = replace(input);
	int prevIndex = 0, nextIndex = 0;
	bool warningFlag = 0;
	while (nextIndex < output.size() && prevIndex < output.size())
	{
		if (output[prevIndex] == '+' || output[prevIndex] == '-')
		{
			nextIndex = prevIndex + 1;
			while (nextIndex < output.size() && (output[nextIndex] != '+' && output[nextIndex] != '-'))
			{
				if (output[nextIndex] != ' ')
				{
					prevIndex = nextIndex;
					break;
				}
				nextIndex++;
			}
			// Simplification
			if (output[prevIndex] == '+' && output[nextIndex] == '+')
			{
				output[nextIndex] = ' ';
				warningFlag = true;
			}
				
			else if (output[prevIndex] == '+' && output[nextIndex] == '-')
			{
				output[prevIndex] = '-';
				output[nextIndex] = ' ';
				warningFlag = true;
			}
			else if (output[prevIndex] == '-' && output[nextIndex] == '+')
			{
				output[prevIndex] = '-';
				output[nextIndex] = ' ';
				warningFlag = true;
			}
			else if (output[prevIndex] == '-' && output[nextIndex] == '-')
			{
				output[prevIndex] = '+';
				output[nextIndex] = ' ';
				warningFlag = true;
			}
		}
		else
			prevIndex++;
	}
	if (warningFlag)
		std::cout << "Warning: + or - the way you used may cause some incorrect answer, please add ( and ) in euqatin when you enter." << std::endl;
	output = "( " + output;
	output += " )";
	return output;
}

int priority(std::string alpha)
{
	if (alpha == "+" || alpha == "-")
		return 1;

	if (alpha == "*" || alpha == "/")
		return 2;

	if (alpha == "^")
		return 3;

	if (alpha == "!")
		return 4;

	return 0;
}

// this algorithm please refer the README.md file.
BigNumber convert(std::string infix)
{
	if (!inputIsValid(infix))
		return BigNumber();

	infix = format(infix);
	//std::cout << "after format => " << infix << std::endl;
	std::stack<std::string> op;
	std::stack<BigNumber> num;
	std::stringstream ss;
	std::string temp;
	bool isSign = 0;
	ss << infix;
	while (ss.good())
	{
		ss >> temp;
		if (ss.fail())
			break;

		if (isBigNumber(temp))
		{
			isSign = 0;
			BigNumber tempBN(temp);

			num.push(tempBN);
		}
		else
		{
			if (temp == "(")
			{
				op.push(temp);
				isSign = 1;
			}
			else if (temp == ")")
			{
				while (op.top() != "(")
				{
					if (op.top() == "!")
					{
						BigNumber a;
						a = factorial(num.top());
						num.pop();
						num.push(a);
					}
					else
					{
						if (num.size() < 2)
						{
							std::cout << "Error: Input is invalid, using symbol of operation improper" << std::endl;
							return BigNumber();
						}
						else
						{
							BigNumber a, b;
							b = num.top();
							num.pop();
							a = num.top();
							num.pop();
							num.push(Calculate(a, b, op.top()));
						}
					}
					op.pop();
				}
				op.pop();
			}
			else
			{
				// preSolve
				// to judge is add and sub or positive and negative
				if (isSign && temp == "+")
				{
					BigNumber a(1);
					op.push("*");
					num.push(a);
				}
				else if (isSign && temp == "-") 
				{
					BigNumber a(-1);
					op.push("*");
					num.push(a);
				}
				else
				{
					// is symbol of operation
					while (!op.empty() && priority(temp) <= priority(op.top()))
					{
						if (op.top() == "!")
						{
							BigNumber a;
							a = factorial(num.top());
							num.pop();
							num.push(a);
						}
						else
						{
							if (num.size() < 2)
							{
								std::cout << "Error: Input is invalid, using symbol of operation improper" << std::endl;
								return BigNumber();
							}
							BigNumber a, b;
							b = num.top();
							num.pop();
							a = num.top();
							num.pop();
							num.push(Calculate(a, b, op.top()));
						}
						op.pop();
					}
					op.push(temp);
				}
			}
		}
	}
	// clear op stack
	while (!op.empty())
	{
		if (op.top() == "!")
		{
			BigNumber a;
			a = factorial(num.top());
			num.pop();
			num.push(a);
		}
		else
		{
			if (num.size() < 2)
			{
				std::cout << "Error: Input is invalid, using symbol of operation improper" << std::endl;
				return BigNumber();
			}
			BigNumber a, b;
			b = num.top();
			num.pop();
			a = num.top();
			num.pop();
			num.push(Calculate(a, b, op.top()));
		}
		op.pop();
	}
	
	if (num.size() == 0)
	{
		std::cout << "Error: Input is empty." << std::endl;
		return BigNumber();
	}
	else if (num.size() != 1) {
		std::cout << "Error: Input is incorrect." << std::endl;
		return BigNumber();
	}
	return num.top();
}

bool isBigNumber(std::string num)
{
	for (int i = 0; i < num.size(); i++)
	{
		if (!(isdigit(num[i]) || num[i] == '.'))	// isn't digit or '.'
			return false;
	}
	return true;
}

BigNumber Calculate(const BigNumber& a, const BigNumber& b, std::string symbol)
{
	BigNumber result;
	if (symbol == "+")
		result = a + b;
	else if (symbol == "-")
		result = a - b;
	else if (symbol == "*")
		result = a * b;
	else if (symbol == "/")
		result = a / b;
	else if (symbol == "%")
		result = a % b;
	else if (symbol == "^")
		result = power(a, b);
	return result;
}
