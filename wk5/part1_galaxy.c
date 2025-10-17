// Space Exploration
// part1_galaxy.c
//
// This program was written by YOUR-NAME-HERE (zXXXXXXX)
// on INSERT-DATE-HERE
//
// This program is a simple game that allows the user to build a galaxy. 
// The user can place stars, planets, and nebulae in the galaxy.

#include <stdio.h>

#define SIZE 5
#define NEBULA_POINTS -10

#define STOP_COMMAND 'q'
enum entity {
    STAR,
    PLANET,
    NEBULA,
    SPACESHIP,
    EMPTY,
};

struct celestial_body {
    enum entity entity;
    int points;
};

void print_map(struct celestial_body galaxy[SIZE][SIZE]);
void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]);

int main(void) {
    struct celestial_body galaxy[SIZE][SIZE];

    // TODO: Initialize the galaxy
    initialise_galaxy(galaxy);

    // TODO: Place the planets and nebulae in the galaxy
    planet_nebula_setup(galaxy);

    // TODO: Place the player in the galaxy
    player_setup(galaxy); 

    // TODO: Place the stars in the galaxy
    star_setup(galaxy);

    // TODO: Print the map
    print_map(galaxy);
    return 0;
}

void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            galaxy[i][j].entity = EMPTY;
            galaxy[i][j].points = 0;
        }
    }
}

void planet_nebula_setup(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter planets and nebulae:\n");
    char command;
    while (scanf(" %c", &command) == 1 && command != STOP_COMMAND) {
        int row, col;
        if (command == 'p') {
            int points;
            scanf("%d %d %d", &row, &col, &points);
            galaxy[row][col].entity = PLANET;
            galaxy[row][col].points = points;
        } else if (command == 'n') {
            scanf("%d %d", &row, &col);
            galaxy[row][col].entity = NEBULA;
            galaxy[row][col].points = NEBULA_POINTS;
        }
    }
}

void player_setup(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter the starting position of the player: ");
    int player_row, player_col;
    scanf("%d %d", &player_row, &player_col);
    while (invalid_player_position(galaxy, player_row, player_col)) {
        printf("Invalid starting position!\n");
        printf("Enter the starting position of the player: ");
        scanf("%d %d", &player_row, &player_col);
    }
    galaxy[player_row][player_col].entity = SPACESHIP;
}

int invalid_player_position(struct celestial_body galaxy[SIZE][SIZE], int player_row, int player_col) {
    return !(player_row < SIZE && player_row >= 0 
            && player_col < SIZE && player_col >= 0) 
            || galaxy[player_row][player_col].entity != EMPTY;
}

void star_setup(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter the position and points of the star(s):\n");
    int row, col, points;
    while (scanf("%d %d %d", &row, &col, &points) == 3) {
        galaxy[row][col].entity = STAR;
        galaxy[row][col].points = points;
    }
}


// Function prints the map of the galaxy
// 
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void print_map(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("\n---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|");
            if (galaxy[i][j].entity == SPACESHIP) {
                printf(" X ");
            } else if (galaxy[i][j].entity == EMPTY) {
                printf("   ");
            } else if (galaxy[i][j].entity == STAR) {
                printf(" * ");
            } else if (galaxy[i][j].entity == PLANET) {
                printf(" o ");
            } else if (galaxy[i][j].entity == NEBULA) {
                printf(" # ");
            }
        }
        printf("|\n");
        printf("---------------------\n");
    }
}