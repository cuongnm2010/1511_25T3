// part2_2d_while_loops.c
//
// This program was writtn by Sofia De Bellis (z5418801)
// on Febuarary 2024
//
// This program is a simple deonstration of a 2D while loop 

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int main(void) {
    // print "Start of outer loop!"
    // declare and initialise integer 'row' and 'col' to 0
    // while row < MAX:
    //     print "Start of inner loop!"
    //     while col < MAX:
    //             print col
    //             increment 'col'
    //     print "End of inner loop!"
    //     increment 'row'
    // print "End of outer loop!
    
    int row = 0;
    int col = 0;
    while (row < MAX_ROW) {
        col = 0;
        while (col < MAX_COL) {
            printf("%d ", col);
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}
