#include "Func_for_math_expresions.h"

void status_1(string &s, vector<string> &val, Stack <value_operation> &operation, int &index, int &status)
{
	if (s[index] == '\0')
	{
		status = 3;
	}
	else if (s[index] == '(')
	{
		value_operation obl('(');
		operation.push(obl);
		status = 1;
	}
	else if ((s[index] >= (int)'0') && (s[index] <= (int)'9') || (s[index] == '.'))
	{
		string obl;
		while (((s[index] >= (int)'0') && (s[index] <= (int)'9')))
		{
			obl.push_back(s[index]);
			index++;
		}
		if (s[index] == '.')
		{
			obl.push_back(s[index]);
			index++;
			while (((s[index] >= (int)'0') && (s[index] <= (int)'9')))
			{
				obl.push_back(s[index]);
				index++;
			}
		}
		if (obl[obl.length()-1] == '.')
			throw 1;
		index--;
		val.push_back(obl);
		status = 2;
	}
	else
		throw 1;
}

void status_2(string &s, vector<string> &val, Stack <value_operation> &operation, int &index, int &status)
{
	if (s[index] == '\0')
	{
		status = 3;
	}
	else if (s[index] == ')')
	{
		while ((!operation.empty()) && (operation.top().func != '('))
		{
			string obl;
			obl.push_back(operation.top().func);
			val.push_back(obl);
			operation.pop();
		}
		operation.pop();
		status = 2;
	}
	else if ((s[index] == '+') || (s[index] == '-') || (s[index] == '*') || (s[index] == '/'))
	{
		value_operation cloud9_fake(s[index]);
		while ((!operation.empty()) && (cloud9_fake.value <= operation.top().value))
		{
			string obl;
			obl.push_back(operation.top().func);
			val.push_back(obl);
			operation.pop();
		}
		operation.push(cloud9_fake);
		status = 1;
	}
	else
	{
		throw 1;
	}
}

void status_3(vector<string> &val, Stack <value_operation> &operation, int &status)
{
	while (!operation.empty())
	{
		string obl;
		obl.push_back(operation.top().func);
		val.push_back(obl);
		operation.pop();
	}
	status = 3;
}

void check_str_on_brackets(string s)
{
	Stack <char> brackets;
	bool flag = true;
	for (int i = 0; i <= s.length(); i++)
	{
		switch (s[i])
		{
		case '(':
			brackets.push(s[i]);
			flag = false;
			break;
		case ')': 
			if ((flag) && (brackets.top() == '('))
				brackets.pop();
			else
				throw 1;
			break;
		default: 
			flag = true;
			break;
		}
		
	}
	if (!brackets.empty())
	{
		std::cout << brackets.top();
		throw 1;
	}
}

void convert_str_to_Poland(string s, vector <string> &val)
{
	Stack <value_operation> operation;
	int status = 1;
	for (int i = 0; i <= s.length(); i++)
	{
		if (status == 1)
		{
			status_1(s, val, operation, i, status);
		}
		else if (status == 2)
		{
			status_2(s, val, operation, i, status);
		}
		else if (status == 3)
		{
			status_3(val, operation, status);
			return;
		}
	}
	if (status == 4)
	{
		throw 1;
	}
	else if (status == 3)
	{
		status_3(val, operation, status);
	}
}

double get_result_from_Poland(vector <string> poland)
{
	Stack <double> numb;
	for (int i = 0; i < poland.size(); i++)
	{
		if ((poland[i][0] >= (int)'0') && (poland[i][0] <= (int)'9'))
		{
			double tmp = std::stod(poland[i]);
			numb.push(tmp);
		}
		else
		{
			double res = 0;
			res = numb.top();
			numb.pop();
			switch (poland[i][0])
			{
			case '+':
			{
				res = res + numb.top();
				break;
			}
			case '-':
			{
				res = numb.top() - res;
				break;
			}
			case '*':
			{
				res = numb.top() * res;
				break;
			}
			case '/':
			{
				if (res == 0)
					throw 1;
				res = numb.top() / res;
				break;
			}
			default: throw 1;

			}
			numb.pop();
			numb.push(res);
		}
	}
	return numb.top();
}

double get_res_from_math_expresions(string s)
{
	vector <string> val;
	check_str_on_brackets(s);
	convert_str_to_Poland(s, val);
	return get_result_from_Poland(val);
}