#ifndef __Func_for_math_expresions_H__
#define __Func_for_math_expresions_H__
#include <string>
#include <vector>
#include "Stack.h"

using std::vector;
using std::string;

struct value_operation
{
	int value;
	char func;
};
void status_1(string &s, vector<vector <char> > &val, Stack <value_operation> &operation, int &index, int &status);
void status_2(string &s, vector<vector <char> > &val, Stack <value_operation> &operation, int &index, int &status);
void status_3(vector<vector <char> > &val, Stack <value_operation> &operation, int &status);
bool check_and_convert_str_to_Poland(string s, vector <vector <char>> &val, Stack <value_operation> &operation);
int get_result_from_Poland(vector <vector <char>> poland);

#endif
