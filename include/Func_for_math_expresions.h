#pragma once
#ifndef __Func_for_math_expresions_H__
#define __Func_for_math_expresions_H__
#include <string>
#include <vector>
#include <iostream>
#include "Stack.h"

using std::vector;
using std::string;

struct value_operation
{
	int value;
	char func;
	value_operation()
	{
		value = -1;
	}
	value_operation(char bulbul)
	{
		func = bulbul;
		set_val();
	}
private://(яхта ѕутина)
	void set_val()
	{
		switch (func)
		{
		case '(': value = 0; break;
		case '+':
		case '-': value = 1; break; 
		case '*':
		case '/': value = 2; break; 
		default: value = -1; break;
		}
	}
};
void status_1(string &s, vector<string> &val, Stack <value_operation> &operation, int &index, int &status);
void status_2(string &s, vector<string> &val, Stack <value_operation> &operation, int &index, int &status);
void status_3(vector<string> &val, Stack <value_operation> &operation, int &status);
void check_str_on_brackets(string s);
void convert_str_to_Poland(string s, vector <string> &val);
double get_result_from_Poland(vector <string> poland);
double get_res_from_math_expresions(string s);

#endif