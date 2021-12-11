#include <string.h>
#include "bdd-for-c.h"
#include "../calculator.h"
#include <stddef.h>

spec("[CALC-US-03] Calculate Division") {

    float numbers[3];
    size_t length;

    context("when the General User input two or more numbers for division calculation") {

        before_each() {
            // given
            starts_a_new_calculation();
        }

        it("should shows the desired result (equals -0.166666667) when the numbers are positive or negative (1, 2 and -3)") {
            // when
            numbers[0] = 1;
            numbers[1] = 2;
            numbers[2] = -3;
            length = sizeof numbers / sizeof *numbers;
            division_calculation(numbers, length);

            // then
            printf("result %f \n", shows_a_result());
            check(fequal(shows_a_result(), -0.166666667) == IS_TRUE);
        }

        it("should shows the desired result (equals -0.125) when the numbers are negative (-1, -2 and -4)") {
            // when
            numbers[0] = -1;
            numbers[1] = -2;
            numbers[2] = -4;
            length = sizeof numbers / sizeof *numbers;
            division_calculation(numbers, length);

            // then
            printf("result %f \n", shows_a_result());
            check(fequal(shows_a_result(), -0.125) == IS_TRUE);
        }

        it("should shows the desired result (equals 1.666666667) when the numbers are non integer (0.1, -0.2 and -0.3)") {
            // when
            numbers[0] = 0.1;
            numbers[1] = -0.2;
            numbers[2] = -0.3;
            length = sizeof numbers / sizeof *numbers;
            division_calculation(numbers, length);

            // then
            printf("result %f \n", shows_a_result());
            check(fequal(shows_a_result(), 1.666666667) == IS_TRUE);
        }

        it("should shows an error message telling me that divisor number must be different by zero") {
            // when
            numbers[0] = 2;
            numbers[1] = 0;
            numbers[2] = 3;
            length = sizeof numbers / sizeof *numbers;
            division_calculation(numbers, length);

            // then
            printf("result %f \n", shows_a_result());
            check(shows_a_error_message(), MSG_DIVISION_BY_ZERO);
        }

    }

}
