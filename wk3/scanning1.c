#include <stdio.h>

int main(void) {
    // Enter a series of integers until you reach a negative number. 
    // Then, stop and calculate the sum.

    int number;
    scanf("%d", &number);

    int sum = 0;
    while (number >= 0) {
        sum += number;
        scanf("%d", &number);
    }

    printf("Sum: %d\n", sum);
    return 0;
}