// coffee_shop.c
//
// Written by YOUR-NAME (zID)
// on TODAYS-DATE 
//
// This program is a simple coffee shop used to demonstrate the use of 
// structs and enums in C. This program takes user input for a coffee order
// and outputs the cost of the order.

#include <stdio.h>

#define LARGE 'L'
#define REGULAR 'R'
#define ADDED_COST 0.5
#define BASE_COST 4.5

// TODO: Define an enum `coffee_type` that stores the different types of coffees 
// the shop sells. These are: LATTEE, CAPPUCCINO, ESPRESSO, AMERICANO & MATCHA.

enum coffee_type { 
    LATTE, 
    CAPPUCCINO, 
    ESPRESSO, 
    AMERICANO, 
    MATCHA
};
// TODO: Define a struct `coffee` that stores 
// 1. the coffee type (an enum)
// 2. the number of sugars 
// 3. the size of a coffee 

struct coffee {
    enum coffee_type type;
    int num_sugars;
    char size;    
};

int main(void) {
    struct coffee coffee;

    printf("Enter coffee type (0: LATTE, 1: CAPPUCCINO, 2: ESPRESSO, "
            "3: AMERICANO, 4: MATCHA): ");

    int type;
    scanf("%d", &type);
    if (type == 0) {
        coffee.type = LATTE;
    } else if (type == 1) {
        coffee.type = CAPPUCCINO;
    } else if (type == 2) {
        coffee.type = ESPRESSO;
    } else if (type == 3) {
        coffee.type = AMERICANO;
    } else {
        coffee.type = MATCHA;
    }

    // alternative soln
    if (type >= LATTE && type <= MATCHA) {
        coffee.type = type;
    } else {
        printf("The input is not supported.\n");
        return 0;
    }

    printf("Enter number of sugars: ");
    scanf("%d", &coffee.num_sugars);

    printf("Enter size (L for Large, R for Regular): ");
    scanf(" %c", &coffee.size);

    // The base price is always 4.5.
    // A LARGE coffee incurs an additional charge.
    // A LATTE, CAPPUCCINO or MATCHA incurs an additional charge.
    // Every sugar added incurs an additional charge.
    double total_cost = BASE_COST;
    if (coffee.size == LARGE) {
        total_cost += ADDED_COST;
    }

    if (coffee.type == LATTE 
        || coffee.type == MATCHA 
        || coffee.type == CAPPUCCINO
    ) {
        total_cost += ADDED_COST;
    }

    total_cost += ADDED_COST * coffee.num_sugars;

    printf("Total cost: %.2lf\n", total_cost);
    return 0;
}