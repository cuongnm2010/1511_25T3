#include <stdio.h>

#define QUIT 'q'

//  Enter characters until the user presses 'q'. 
// Then, display the count of characters entered.

int main(void) {
    char input;
    scanf(" %c", &input);

    int count = 0;
    while (input != QUIT) {
        count++;
        scanf(" %c", &input);
    }

    printf("%d\n", count);
    return 0;
}