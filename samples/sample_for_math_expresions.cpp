#include <Func_for_math_expresions.h>
#include <iostream>

using std::string;
using std::vector;

int main(int argc, char *argv[])
{
	if (argc > 1)
		for (int i = 1; i < argc; i++)
		{
			string s;
			s = argv[i];
			vector <string> obl;
			std::cout << get_res_from_math_expresions(s) << "\n";
		}
	else
	{
		string s;
		std :: cin >> s;
		vector <string> obl;
		Stack <value_operation> operation;
		std::cout << get_res_from_math_expresions(s) << "\n";
	}
	return 0;
}