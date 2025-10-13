// functions.c
//
// Written by Sofia De Bellis (z5418801)
// on March 2024
//
// This program is a simple demonstration of functions

#include <stdio.h>

int add(int number1, int number2);

int main(void) {
    int result;
    int num1 = 5;
    int num2 = 3;

    int result = add(num1, num2);

    printf("Result: %d\n", result);
    return 0;
}

int add(int number1, int number2) {
    return number1 + number2;
}

