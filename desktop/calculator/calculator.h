#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

#define MAX_LENGTH 255

static const char MSG_DIVISION_BY_ZERO[] = "The divisor number must be different by zero.";

float g_result;
char g_error_message[MAX_LENGTH];

void starts_a_new_calculation();
float shows_a_result();
void sum_calculation(float numbers[], size_t length);
void subtraction_calculation(float numbers[], size_t length);
void multiplication_calculation(float numbers[], size_t length);
void division_calculation(float numbers[], size_t length);
char * shows_a_error_message();
void reset_error_message();

#define MAX_TOKENS 255
#define IS_TRUE 1
#define IS_FALSE 0

char g_tokens[MAX_TOKENS];
int g_number_of_inputs;

void inputs_reset();
void inputs(char token);
void inputs_equals();
void reset_token_array();
char * get_tokens();
float sum(float firstNumber, float secondNumber);
float sub(float firstNumber, float secondNumber);
float mult(float firstNumber, float secondNumber);
float div_(float firstNumber, float secondNumber);
char * ftoa(float f);
int fequal(float a, float b);
int is_integer(float val);


#endif // CALCULATOR_H_INCLUDED
