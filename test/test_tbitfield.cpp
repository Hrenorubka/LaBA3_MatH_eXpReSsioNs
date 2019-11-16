#include "Func_for_math_expresions.h"
#include <gtest.h>

TEST(math_expresions_b1, can_check_true_string)
{
	string s = "(3+3)*(1)";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	ASSERT_NO_THROW(check_and_convert_str_to_Poland(s, obl, operation));
}

TEST(math_expresions_b1, can_check_too_many_brackets_v_left)
{
	string s = "((((3";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	ASSERT_ANY_THROW(check_and_convert_str_to_Poland(s, obl, operation));
}

TEST(math_expresions_b1, can_check_too_many_brackets_v_rigth)
{
	string s = "3)))))";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	ASSERT_ANY_THROW(check_and_convert_str_to_Poland(s, obl, operation));
}

TEST(math_expresions_b1, can_check_unknown_symbol)
{
	string s = "3+a";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	ASSERT_ANY_THROW(check_and_convert_str_to_Poland(s, obl, operation));
}

TEST(math_expresions_b1, can_check_worse_bracket)
{
	string s = "3+()";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	ASSERT_ANY_THROW(check_and_convert_str_to_Poland(s, obl, operation));
}

TEST(math_expresions_b2, can_create_correct_poland_add)
{
	string s = "3+3";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ('+', obl[2][0]);
}

TEST(math_expresions_b2, can_create_correct_poland_mul)
{
	string s = "3+3*3";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ('*', obl[3][0]);
}

TEST(math_expresions_b2, can_create_correct_poland_division)
{
	string s = "3+3/3*3";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ('/', obl[3][0]);
}

TEST(math_expresions_b2, can_create_correct_poland_big_num)
{
	string s = "339";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ('9', obl[0][2]);
}

TEST(math_expresions_b3, can_get_answer_solo_num)
{
	string s = "339";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(339, get_result_from_Poland(obl));
}


TEST(math_expresions_b3, can_get_answer_easy_math_add)
{
	string s = "339+104";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(443, get_result_from_Poland(obl));
}

TEST(math_expresions_b3, can_get_answer_easy_math_sub)
{
	string s = "339-104";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(235, get_result_from_Poland(obl));
}

TEST(math_expresions_b3, can_get_answer_easy_math_mul)
{
	string s = "3*4";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(12, get_result_from_Poland(obl));
}

TEST(math_expresions_b3, can_get_answer_easy_math_div)
{
	string s = "9/3";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(3, get_result_from_Poland(obl));
}

TEST(math_expresions_b3, can_get_answer_normal_math_no_brackets)
{
	string s = "3+3*4-5+6/3";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(12, get_result_from_Poland(obl));
}

TEST(math_expresions_b3, can_get_answer_normal_math_with_brackets)
{
	string s = "(3+3)*4-14/(9-2)";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(22, get_result_from_Poland(obl));
}


TEST(math_expresions_b3, can_get_answer_hard_math)
{
	string s = "(3-(3+5*4-(10+6)))";
	vector <vector <char> > obl;
	Stack <value_operation> operation;
	check_and_convert_str_to_Poland(s, obl, operation);
	EXPECT_EQ(-4, get_result_from_Poland(obl));
}