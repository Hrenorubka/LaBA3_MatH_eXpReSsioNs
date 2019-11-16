#include <Func_for_math_expresions.h>
#include <iostream>

using std::string;
using std::vector;

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		string s;
		s = argv[i];
		vector <vector <char> > obl;
		Stack <value_operation> operation;
		check_and_convert_str_to_Poland(s, obl, operation);
		std::cout << get_result_from_Poland(obl) << "\n";
	}
	return 0;
}