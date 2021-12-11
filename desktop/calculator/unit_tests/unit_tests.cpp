
#include <gtest/gtest.h>

extern "C" {
    #include "../calculator.h"
}

//  [CALC-US-05] Erase the results displayed

TEST(when_starts_a_new_calculation, should_initialize_a_result_equals_zero) {
    inputs_reset();
    EXPECT_EQ(0, shows_a_result());
}


//  [CALC-US-01] Calculate Sum

TEST(when_makes_sum_calculation, should_sum_positive_numbers) {
    inputs_reset();
    inputs('1');
    inputs('5');
    inputs('0');
    inputs('+');
    inputs('2');
    inputs('5');
    inputs('0');
    inputs('+');
    inputs('3');
    inputs('0');
    inputs('0');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(700, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sum_calculation, should_sum_positive_or_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('5');
    inputs('0');
    inputs('+');
    inputs('2');
    inputs('5');
    inputs('0');
    inputs('-');
    inputs('5');
    inputs('0');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(50, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sum_calculation, should_sum_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('-');
    inputs('2');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-3, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sum_calculation, should_sum_non_integer_numbers) {
    inputs_reset();
    inputs('0');
    inputs('.');
    inputs('1');
    inputs('+');
    inputs('0');
    inputs('.');
    inputs('2');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(0.3, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sum_calculation_and_display_is_dirty, should_makes_sum_numbers) {
    inputs_reset();
    inputs('1');
    inputs('+');
    inputs('2');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(3, shows_a_result()) == IS_TRUE);
    inputs('+');            // "dirty" = makes calc with previous result
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(6, shows_a_result()) == IS_TRUE);
    inputs('-');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(3, shows_a_result()) == IS_TRUE);
}


//  [CALC-US-02] Calculate Subtraction

TEST(when_makes_sub_calculation, should_sub_positive_or_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('5');
    inputs('0');
    inputs('+');
    inputs('2');
    inputs('5');
    inputs('0');
    inputs('-');
    inputs('5');
    inputs('0');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(50, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sub_calculation, should_sub_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('2');
    inputs('-');
    inputs('2');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-35, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sub_calculation, should_sub_non_integer_numbers) {
    inputs_reset();
    inputs('0');
    inputs('.');
    inputs('1');
    inputs('-');
    inputs('0');
    inputs('.');
    inputs('2');
    inputs('-');
    inputs('0');
    inputs('.');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-0.4, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_sub_calculation_and_display_is_dirty, should_makes_sub_numbers) {
    inputs_reset();
    inputs('1');
    inputs('-');
    inputs('2');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-1, shows_a_result()) == IS_TRUE);
    inputs('+');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(2, shows_a_result()) == IS_TRUE);
    inputs('-');
    inputs('5');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-3, shows_a_result()) == IS_TRUE);
}


//  [CALC-US-03] Calculate Multiplication

TEST(when_makes_mult_calculation, should_mult_positive_or_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('5');
    inputs('0');
    inputs('*');
    inputs('2');
    inputs('5');
    inputs('0');
    inputs('*');
    inputs('-');
    inputs('5');
    inputs('0');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(1875000, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_mult_calculation, should_mult_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('2');
    inputs('*');
    inputs('-');
    inputs('2');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(276, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_mult_calculation, should_mult_non_integer_numbers) {
    inputs_reset();
    inputs('0');
    inputs('.');
    inputs('1');
    inputs('*');
    inputs('-');
    inputs('0');
    inputs('.');
    inputs('2');
    inputs('*');
    inputs('0');
    inputs('.');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-0.006, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_mult_calculation_and_display_is_dirty, should_makes_mult_numbers) {
    inputs_reset();
    inputs('1');
    inputs('*');
    inputs('-');
    inputs('2');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-2, shows_a_result()) == IS_TRUE);
    inputs('*');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-6, shows_a_result()) == IS_TRUE);
    inputs('*');
    inputs('5');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-30, shows_a_result()) == IS_TRUE);
}


//  [CALC-US-04] Calculate Division

TEST(when_makes_div_calculation, should_div_positive_or_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('3');
    inputs('0');
    inputs('0');
    inputs('/');
    inputs('2');
    inputs('*');
    inputs('-');
    inputs('5');
    inputs('0');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(7500, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_div_calculation, should_div_negative_numbers) {
    inputs_reset();
    inputs('-');
    inputs('1');
    inputs('2');
    inputs('/');
    inputs('-');
    inputs('2');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(0.52173913, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_div_calculation, should_div_non_integer_numbers) {
    inputs_reset();
    inputs('0');
    inputs('.');
    inputs('1');
    inputs('/');
    inputs('-');
    inputs('0');
    inputs('.');
    inputs('2');
    inputs('/');
    inputs('0');
    inputs('.');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-1.666666667, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_div_calculation_and_display_is_dirty, should_makes_div_numbers) {
    inputs_reset();
    inputs('1');
    inputs('/');
    inputs('-');
    inputs('2');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-0.5, shows_a_result()) == IS_TRUE);
    inputs('/');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-0.166666667, shows_a_result()) == IS_TRUE);
    inputs('/');
    inputs('5');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    ASSERT_TRUE(fequal(-0.0333333, shows_a_result()) == IS_TRUE);
}

TEST(when_makes_div_calculation_and_divisor_is_zero, should_shows_a_error_message) {
    inputs_reset();
    inputs('2');
    inputs('/');
    inputs('0');
    inputs('/');
    inputs('3');
    inputs_equals();
    printf("\nresult is %f\n", shows_a_result());
    EXPECT_STREQ(MSG_DIVISION_BY_ZERO, shows_a_error_message());
}


//  Utils

TEST(when_gets_an_integer_result, should_shows_no_decimal_zeros) {
    inputs_reset();
    EXPECT_STREQ("0", ftoa(shows_a_result()));
}

/*
TEST(when_it_shows_the_outputs_on_window_prompt, should_saves_the_content_to_a_file) {

}
*/
