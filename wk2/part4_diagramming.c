#include <stdio.h>

#define SAFE_DAYS 10
#define SOSO_DAYS 7
#define YES 'y'
#define NO 'n'

int main(void) {
    printf("How many days till your assignment due?: ");
    int days;

    // while (scanf("%d", &days) == 1) {
        if (days > SAFE_DAYS) {
            printf("Are you up to date with lectures and labs?: ");

            char up_to_date;
            scanf(" %c", &up_to_date);

            if (up_to_date == YES) {
                printf("Work on your assignment!\n");
            } else {
                printf("Catch up on them!\n");
            }
        } else if (days >= SOSO_DAYS) {
            printf("Have you started your assignment?: ");
            char started;
            scanf(" %c", &started);
            
            if (started == YES) {
                printf("Great! Don't forget to check style as you go!\n");
            } else {
                printf("You should start! Ask for help if you need\n");
            }
        } else {
            printf("Are you on track to finish?: ");
            char on_track;
            scanf(" %c", &on_track);
            if (on_track == YES) {
                printf("You got this, keep at it!\n");
            } else {
                printf("Attend help sessions, ask your tutors and forums for assistance.\n");
            }
        }
    //     printf("How many days till your assignment due?: ");
    // }
}