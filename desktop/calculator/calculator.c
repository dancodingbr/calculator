#include "calculator.h"

void starts_a_new_calculation() {
    g_result = 0;
    strcpy(g_error_message, "");
}

float shows_a_result() {
    if (isinf(g_result)) {
        g_result = 0;
        strcpy(g_error_message, MSG_DIVISION_BY_ZERO);
    }
    return g_result;
}

void sum_calculation(float numbers[], size_t length) {
    for (int i=0; i < length; i++) {
        g_result = sum(g_result, numbers[i]);
    }
}

void subtraction_calculation(float numbers[], size_t length) {
    for (int i=0; i < length; i++) {
        g_result = sub(g_result, (-1) * numbers[i]);
    }
}

void multiplication_calculation(float numbers[], size_t length) {
    for (int i=0; i < length; i++) {
        if (i==0) {
            g_result = mult(numbers[i], 1);
        } else {
            g_result = mult(g_result, numbers[i]);
        }
    }
}

void division_calculation(float numbers[], size_t length) {
    for (int i=0; i < length; i++) {
        if (i==0) {
            g_result = div_(numbers[i], 1);
        } else {
            g_result = div_(g_result, numbers[i]);
        }
    }
}

char * shows_a_error_message() {
    return g_error_message;
}

void reset_error_message() {
    memset(g_error_message, 0, MAX_LENGTH);
}

void inputs_reset() {
    starts_a_new_calculation();
    reset_token_array();
}

void inputs(char token) {
    g_tokens[g_number_of_inputs] = token;
    g_number_of_inputs++;
}

void inputs_equals() {

    char word_number[MAX_TOKENS]
        , first_number[MAX_TOKENS]
        , second_number[MAX_TOKENS]
        , operator_;
    int pos=0
        , i=0;

    memset(word_number, 0, MAX_TOKENS);
    memset(first_number, 0, MAX_TOKENS);
    memset(second_number, 0, MAX_TOKENS);
    operator_ = '\0';

    if (g_tokens[0] == '-') {
        strcpy(first_number, ftoa(0));
    }

    while (i < g_number_of_inputs) {

        if ((g_tokens[i] != '+') && (g_tokens[i] != '-') && (g_tokens[i] != '*') && (g_tokens[i] != '/')) {
            word_number[pos] = g_tokens[i];
            pos++;

        } else {

            if (first_number[0] == '\0') {
                strcpy(first_number, word_number);
                memset(word_number, 0, MAX_TOKENS);
                pos=0;
            }
            else if (second_number[0] == '\0') {
                strcpy(second_number, word_number);
                memset(word_number, 0, MAX_TOKENS);
                pos=0;
            }

            if ((first_number[0] != '\0') && (second_number[0] != '\0')) {
                switch(operator_) {
                    case '+':
                        g_result = sum(atof(first_number), atof(second_number));
                        strcpy(first_number, ftoa(g_result));
                        memset(second_number, 0, MAX_TOKENS);
                        operator_ = '\0';
                        break;
                    case '-':
                        g_result = sub(atof(first_number), atof(second_number));
                        strcpy(first_number, ftoa(g_result));
                        memset(second_number, 0, MAX_TOKENS);
                        operator_ = '\0';
                        break;
                    case '*':
                        g_result = mult(atof(first_number), atof(second_number));
                        strcpy(first_number, ftoa(g_result));
                        memset(second_number, 0, MAX_TOKENS);
                        operator_ = '\0';
                        break;
                    case '/':
                        g_result = div_(atof(first_number), atof(second_number));
                        strcpy(first_number, ftoa(g_result));
                        memset(second_number, 0, MAX_TOKENS);
                        operator_ = '\0';
                        break;
                    default:
                        break;
                }
            }

            if ((operator_ == '*') && (g_tokens[i] == '-')) {
                g_result = mult((-1)*atof(first_number), 1);
                strcpy(first_number, ftoa(g_result));
            }
            else if ((operator_ == '/') && (g_tokens[i] == '-')) {
                g_result = div_((-1)*atof(first_number), 1);
                strcpy(first_number, ftoa(g_result));
            }
            else {
                operator_ = g_tokens[i];
            }
        }

        i++;

        if (i == g_number_of_inputs) {
            strcpy(second_number, word_number);
            if ((first_number != '\0') && (second_number != '\0')) {
                switch(operator_) {
                    case '+':
                        g_result = sum(atof(first_number), atof(second_number));
                        break;
                    case '-':
                        g_result = sub(atof(first_number), atof(second_number));
                        break;
                    case '*':
                        g_result = mult(atof(first_number), atof(second_number));
                        break;
                    case '/':
                        g_result = div_(atof(first_number), atof(second_number));
                        break;
                    default:
                        break;
                }
            }
        }

        if (isinf(g_result) && (operator_ == '/')) {
            g_result = 0;
            strcpy(g_error_message, MSG_DIVISION_BY_ZERO);
            break;
        }

    }

    reset_token_array();
    strcpy(g_tokens, ftoa(g_result));
    g_number_of_inputs = strlen(g_tokens);
}

void reset_token_array() {
    memset(g_tokens, 0, MAX_TOKENS);
    g_number_of_inputs = 0;
}

char * get_tokens() {
    return g_tokens;
}

float sum(float firstNumber, float secondNumber) {
    return firstNumber + secondNumber;
}

float sub(float firstNumber, float secondNumber) {
    return firstNumber - secondNumber;
}

float mult(float firstNumber, float secondNumber) {
    return firstNumber * secondNumber;
}

float div_(float firstNumber, float secondNumber) {
    return firstNumber / secondNumber;
}

char * ftoa(float f) {
    static char        buf[17];
    char *            cp = buf;
    unsigned long    l, rem;

    if(f < 0) {
        *cp++ = '-';
        f = -f;
    }
    l = (unsigned long)f;
    f -= (float)l;
    rem = (unsigned long)(f * 1e6);

    if (is_integer(f) == IS_TRUE) {
        sprintf(cp, "%lu", l);
    } else {
        sprintf(cp, "%lu.%6.6lu", l, rem);
    }
    return buf;
}

int fequal(float a, float b) {
    if (fabs(a-b) < FLT_EPSILON) {
        return IS_TRUE;
    }
    return IS_FALSE;
}

int is_integer(float val) {
    int truncated = (int)val;
    if (val == truncated) {
        return IS_TRUE;
    }
    return IS_FALSE;
}
