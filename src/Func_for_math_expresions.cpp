#include "Func_for_math_expresions.h"

void status_1(string &s, vector<vector <char> > &val, Stack <value_operation> &operation, int &index, int &status)
{
	if (s[index] == '\0')
	{
		status = 3;
	}
	else if (s[index] == '(')
	{
		operation.push({ 0, s[index] });
		status = 1;
	}
	else if ((s[index] >= 48) && (s[index] <= 57))
	{
		vector <char> obl;
		while (((s[index] >= 48) && (s[index] <= 57)))
		{
			obl.push_back(s[index]);
			index++;
		}
		index--;
		val.push_back(obl);
		status = 2;
	}
	else
		status = 4;
}

void status_2(string &s, vector<vector <char> > &val, Stack <value_operation> &operation, int &index, int &status)
{
	if (s[index] == '\0')
	{
		status = 3;
	}
	else if (s[index] == ')')
	{
		while ((!operation.empty()) && (operation.top().func != '('))
		{
			vector <char> obl;
			obl.push_back(operation.top().func);
			val.push_back(obl);
			operation.pop();
		}
		if (operation.empty())
		{
			status = 4;
			return;
		}
		operation.pop();
		status = 2;
	}
	else if ((s[index] == '+') || (s[index] == '-'))
	{
		if (operation.empty())
		{
			operation.push({ 1, s[index] });
		}
		else if (operation.top().value >= 1)
		{

			while ((!operation.empty()) && (operation.top().value >= 1))
			{
				vector <char> obl;
				obl.push_back(operation.top().func);
				val.push_back(obl);
				operation.pop();
			}
			operation.push({ 1, s[index] });
		}
		else
			operation.push({ 1, s[index] });
		status = 1;
	}
	else if ((s[index] == '*') || (s[index] == '/'))
	{
		if (operation.empty())
		{
			operation.push({ 2, s[index] });
		}
		else if (operation.top().value >= 2)
		{
			while ((!operation.empty()) && (operation.top().value >= 2))
			{
				vector <char> obl;
				obl.push_back(operation.top().func);
				val.push_back(obl);
				operation.pop();
			}
			operation.push({ 2, s[index] });
		}
		else
			operation.push({ 2, s[index] });
		status = 1;
	}
	else
	{
		status = 4;
	}
}

void status_3(vector<vector <char> > &val, Stack <value_operation> &operation, int &status)
{
	while (!operation.empty())
	{
		if (operation.top().func == '(')
		{
			throw 1;
			status = 4;
			return;
		}
		vector <char> obl;
		obl.push_back(operation.top().func);
		val.push_back(obl);
		operation.pop();
	}
	status = 3;
}

bool check_and_convert_str_to_Poland(string s, vector <vector <char>> &val, Stack <value_operation> &operation)
{
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
			if (status == 3)
				return true;
			return false;
		}
		else if (status == 4)
		{
			throw 1;
			return false;
		}
	}
	if (status == 3)
	{
		status_3(val, operation, status);
		if (status == 3)
			return true;
		return false;
	}
}

int get_result_from_Poland(vector <vector <char>> poland)
{
	Stack <int> numb;
	for (int i = 0; i < poland.size(); i++)
	{
		if ((poland[i][0] >= 48) && (poland[i][0] <= 57))
		{
			int tmp = 0;
			for (int j = 0; j < poland[i].size(); j++)
				tmp = tmp * 10 + poland[i][j] - 48;
			numb.push(tmp);
		}
		else
		{
			int res = 0;
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
