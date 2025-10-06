// part1_while_loops.c
//
// Written by YOUR-NAME (zID), 
// on TODAYS-DATE
//
// This program is a simple demonstration of a count loop in c


#include <stdio.h>

int main(void) {
    // declare integer 'x' and prompt the user for value of ‘x’

    // print "Start of loop!"
    // while x < 10:
    //     print x
    //     increment x

    // print "End of loop!"

    printf("Enter a number: ");
    int x;
    scanf("%d", &x);

    printf("Start of loop!\n");
    while (x < 10) {
        printf("%d\n", x);
        x = x + 1;
    }

    printf("End of loop!\n");


    return 0;
}
