#include <string.h>
#include "bdd-for-c.h"
#include "../calculator.h"
#include <stddef.h>


spec("[CALC-US-05] Erase the results displayed") {

    context("when the General User starts a new calculation") {
        it("should initially shows a result equals zero value on calculator display") {
            // when
            starts_a_new_calculation();
            // then
            check(fequal(shows_a_result(), 0) == IS_TRUE);
        }
    }

}
