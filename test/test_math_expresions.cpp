#include "Func_for_math_expresions.h"
#include <gtest.h>

TEST(math_expresions_b1, can_check_true_string)
{
	string s = "(3+3)*(1)";
	vector <string> obl;
	ASSERT_NO_THROW(convert_str_to_Poland(s, obl));
}

TEST(math_expresions_b1, can_check_too_many_brackets_v_left)
{
	string s = "((((3";
	ASSERT_ANY_THROW(check_str_on_brackets(s));
}

TEST(math_expresions_b1, can_check_too_many_brackets_v_rigth)
{
	string s = "3)))))";
	ASSERT_ANY_THROW(check_str_on_brackets(s));
}

TEST(math_expresions_b1, can_check_more_rigth_brackets_in_the_end)
{
	string s = "(10+3))*3+(15)";
	ASSERT_ANY_THROW(check_str_on_brackets(s));
}

TEST(math_expresions_b1, can_check_string_with_only_brackets)
{
	string s = "((()))";
	ASSERT_ANY_THROW(check_str_on_brackets(s));
}

TEST(math_expresions_b1, can_check_more_left_brackets_in_the_end)
{
	string s = "(10+3)*3+((15)";
	ASSERT_ANY_THROW(check_str_on_brackets(s));
}

TEST(math_expresions_b1, can_check_unknown_symbol)
{
	string s = "3+a";
	vector <string> val;
	ASSERT_ANY_THROW(convert_str_to_Poland(s, val));
}

TEST(math_expresions_b1, can_check_worse_bracket)
{
	string s = "3+()";
	ASSERT_ANY_THROW(check_str_on_brackets(s));
}

TEST(math_expresions_b2, can_create_correct_poland_add)
{
	string s = "3+3";
	vector <string> obl;
	convert_str_to_Poland(s, obl);
	EXPECT_EQ('+', obl[2][0]);
}

TEST(math_expresions_b2, can_create_correct_poland_mul)
{
	string s = "3+3*3";
	vector <string> obl;
	convert_str_to_Poland(s, obl);
	EXPECT_EQ('*', obl[3][0]);
}

TEST(math_expresions_b2, can_create_correct_poland_division)
{
	string s = "3+3/3*3";
	vector <string> obl;
	convert_str_to_Poland(s, obl);
	EXPECT_EQ('/', obl[3][0]);
}

TEST(math_expresions_b2, can_create_correct_poland_big_num)
{
	string s = "339";
	vector <string> obl;
	Stack <value_operation> operation;
	convert_str_to_Poland(s, obl);
	EXPECT_EQ('9', obl[0][2]);
}

TEST(math_expresions_b3, can_get_answer_solo_num)
{
	string s = "339";
	EXPECT_EQ(339.0, get_res_from_math_expresions(s));
}


TEST(math_expresions_b3, can_get_answer_easy_math_add)
{
	string s = "339+104";
	EXPECT_EQ(443, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, can_get_answer_easy_math_sub)
{
	string s = "339-104";
	EXPECT_EQ(235, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, can_get_answer_easy_math_mul)
{
	string s = "3*4";
	EXPECT_EQ(12, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, can_get_answer_easy_math_div)
{
	string s = "9/3";
	EXPECT_EQ(3, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, can_get_answer_normal_math_no_brackets)
{
	string s = "3+3*4-5+6/3";
	EXPECT_EQ(12, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, can_get_answer_normal_math_with_brackets)
{
	string s = "(3+3)*4-14/(9-2)";
	EXPECT_EQ(22, get_res_from_math_expresions(s));
}


TEST(math_expresions_b3, can_get_answer_hard_math)
{
	string s = "(3-(3+5*4-(10+6)))";
	EXPECT_EQ(-4, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, can_divide_double)
{
	string s = "2/4";
	EXPECT_EQ(0.5, get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, cant_divide_zero_v1)
{
	string s = "2/0";
	ASSERT_ANY_THROW(get_res_from_math_expresions(s));
}

TEST(math_expresions_b3, cant_divide_zero_v2)
{
	string s = "(10*14+6)/(3/3-1)";
	ASSERT_ANY_THROW(get_res_from_math_expresions(s));
}

TEST(math_expresions_b1, can_check_false_fraction_v1)
{
	string s = "3.123.31";
	ASSERT_ANY_THROW(get_res_from_math_expresions(s));
}

TEST(math_expresions_b1, can_check_false_fraction_v2)
{
	string s = "1.2.34+0.6*7.98";
	ASSERT_ANY_THROW(get_res_from_math_expresions(s));
}

TEST(math_expresions_b1, can_check_true_fraction_v1)
{
	string s = "1.2+0.6*7.98";
	ASSERT_NO_THROW(get_res_from_math_expresions(s));
}

TEST(math_expresions_b1, can_check_true_fraction_v2)
{
	string s = "(1.2+3.8)*1.5";
	EXPECT_EQ(7.5 ,get_res_from_math_expresions(s));
}
