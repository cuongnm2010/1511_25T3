#include <stdio.h>

// Scan for integers keeping a cumulative sum, until the sum of entered 
// integers reaches or exceeds the target sum provided by the user. 
// Print the final sum.

int main(void) {

    // Scan target
    int target;
    scanf("%d", &target);

    // declare and initialise number (to scan) and sum (to add up numbers)
    int number;
    int sum = 0;
    while (sum <= target) { // executing the loop as long as the sum is not greater than the target (i.e until the sum exceeds target)
        // scanning number
        scanf("%d", &number);

        // add scanned number to sum
        sum += number;
    }

    printf("Final sum: %d\n", sum);

    return 0;
}