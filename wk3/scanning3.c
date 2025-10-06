#include <stdio.h>

// Scan for numbers until end of input and display all even numbers entered.

int main(void) {
    // scanning input and get the return value of scanf function
    int input;
    int return_scanf = scanf("%d", &input);

    int count_even = 0;
    while (return_scanf == 1) { // if it is not ctrl-D, the scanf will return 1 as a number of successful scanning
        if (input % 2 == 0) {
            count_even++;
        }
        // reassigning return_scanf for the new scanning 
        return_scanf = scanf("%d", &input);
    }

    printf("Even number counting: %d\n", count_even);

    /*================ alternative solution ================*/
    // int input;

    // int count_even = 0;
    // while (scanf("%d", &input) == 1) { // if it is not ctrl-D, the scanf will return 1 as a number of successful scanning
    //     if (input % 2 == 0) {
    //         count_even++;
    //     }
    // }

    // printf("Even number counting: %d\n", count_even);

    return 0;
}