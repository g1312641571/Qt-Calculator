#pragma once
#ifndef _calculation_
#define _calculation_

#include <stack>
#include <vector>
#include <string>
#include <cctype>

class calculation
{
public:
	void set(std::string s) { equation = s; }
	void calculate();
	double get() { return result; }

private:
	std::string equation;
	double result;
	int get_priority(char c);

};

int calculation::get_priority(char c)
{
	if (c == '(')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == '*' || c == '/')
		return 3;
	else
		return 0;//error:其他符号
}

void calculation::calculate()
{
	//infix expression to suffix expression
	std::vector<char> suffix;
	std::stack<char> operators;
	for (int i = 0; equation[i] != '\0';)
	{

		if (equation[i] == '-')
		{
			if (i == 0 || equation[i - 1] == '(')
			{
				suffix.push_back('|');
				suffix.push_back(equation[i++]);
				while (isdigit(equation[i]))
					suffix.push_back(equation[i++]);
				if (equation[i] == '.')
				{
					suffix.push_back(equation[i++]);
					while (isdigit(equation[i]))
						suffix.push_back(equation[i++]);
				}
			}
		}
		if (isdigit(equation[i]))
		{
			suffix.push_back('|');
			suffix.push_back(equation[i++]);
			while (isdigit(equation[i]))
				suffix.push_back(equation[i++]);
			if (equation[i] == '.')
			{
				suffix.push_back(equation[i++]);
				while (isdigit(equation[i]))
					suffix.push_back(equation[i++]);
			}
		}
		else if (equation[i] == '(')
			operators.push(equation[i++]);
		else if (equation[i] == ')')
		{
			++i;
			while (operators.top() != '(')
			{
				suffix.push_back('|');
				suffix.push_back(operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
		{
			if (operators.empty())
				operators.push(equation[i++]);
			else
			{
				while (get_priority(equation[i]) <= get_priority(operators.top()))
				{
					suffix.push_back('|');
					suffix.push_back(operators.top());
					operators.pop();
					if (operators.empty())
						break;
				}
				operators.push(equation[i++]);
			}
		}
		else
			return;
	}
	while (!operators.empty())
	{
		suffix.push_back('|');
		suffix.push_back(operators.top());
		operators.pop();
	}

	//suffix expression evaluation
	std::stack<double> num;
	for (int i = 0; i != suffix.size(); )
	{
		if (suffix[i] == '|')
		{
			std::string symbol;
			while (++i != suffix.size() && suffix[i] != '|')
				symbol += suffix[i];
			if (symbol.size() == 1 && !isdigit(symbol[0]))
			{
				double d1(num.top());
				num.pop();
				double d2(num.top());
				num.pop();
				switch (symbol[0])
				{
                case '+':num.push(d2 + d1); break;
                case '-':num.push(d2 - d1); break;
                case '*':num.push(d2 * d1); break;
                case '/':num.push(d2 / d1); break;
				default:break;//error:其他符号
				}
			}
			else
				num.push(std::stod(symbol));//throw out_of_range
		}
		else
		{
			break;//error
		}
	}
	result = num.top();
}

#endif
