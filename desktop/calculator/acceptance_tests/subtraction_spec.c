#include <string.h>
#include "bdd-for-c.h"
#include "../calculator.h"
#include <stddef.h>

spec("[CALC-US-02] Calculate Subtraction") {

    float numbers[3];
    size_t length;

    context("when the General User input two or more numbers for subtraction calculation") {

        before_each() {
            // given
            starts_a_new_calculation();
        }

        it("should shows the desired result (equals -4) when the numbers are positive or negative (1, -2 and -3)") {
            // when
            numbers[0] = 1;
            numbers[1] = -2;
            numbers[2] = -3;
            length = sizeof numbers / sizeof *numbers;
            subtraction_calculation(numbers, length);

            // then
            printf("result %f \n", shows_a_result());
            check(fequal(shows_a_result(), -4) == IS_TRUE);
        }

        it("should shows the desired result (equals -6) when the numbers are negative (-1, -2 and -3)") {
            // when
            numbers[0] = -1;
            numbers[1] = -2;
            numbers[2] = -3;
            length = sizeof numbers / sizeof *numbers;
            subtraction_calculation(numbers, length);

            // then
            printf("result %f \n", shows_a_result());
            check(fequal(shows_a_result(), -6) == IS_TRUE);
        }

        it("should shows the desired result (equals -0.4) when the numbers are non integer (0.1, -0.2 and -0.3)") {
            // when
            numbers[0] = 0.1;
            numbers[1] = -0.2;
            numbers[2] = -0.3;
            length = sizeof numbers / sizeof *numbers;
            subtraction_calculation(numbers, length);

            // then
            check(fequal(shows_a_result(), -0.4) == IS_TRUE);
        }

    }


}
