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
    CAPPUCINO,
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
    double num_sugars;
    char size;
};

int main(void) {
    // TODO: Initalise a variable for the struct
    struct coffee coffee;
    printf("Enter coffee type (0: LATTE, 1: CAPPUCCINO, 2: ESPRESSO, \
            3: AMERICANO, 4: MATCHA): ");
    
    // TODO: take user input
    int coffee_type;
    scanf("%d", &coffee_type);
    if (coffee_type >= 0 && coffee_type <= 4) {
        coffee.type = coffee_type;
    } else {
        printf("Error\n");
        return 0;
    }
    

    printf("Enter number of sugars: ");
    // // TODO: take user input
    scanf("%lf", &coffee.num_sugars);

    printf("Enter size (L for Large, R for Regular): ");
    // // TODO: take user input
    scanf(" %c", &coffee.size);

    // // TODO: Calculate cost of order
    double total_cost = BASE_COST;
    if (coffee.size == LARGE) {
        total_cost += ADDED_COST;
    }

    if (coffee.type == MATCHA 
        || coffee.type == CAPPUCINO 
        || coffee_type == LATTE
    ) {
        total_cost += ADDED_COST;
    }

    total_cost += ADDED_COST * coffee.num_sugars;

    printf("Total cost: %.2lf\n", total_cost);
    return 0;
}

// if (letter >= 'a' && letter <= 'z') -> lowercase
// if (letter >= 'A' && letter <= 'Z') -> uppercase
