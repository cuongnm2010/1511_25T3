// bubble_tea.c
//
// Written by YOUR-NAME (YOUR-ZID) on TODAYS-DATE
//
// This program is a simple bubble tea store used to teach functions

#include <stdio.h>

#define LARGE 'L'
#define REGULAR 'R'
#define ADDED_COST 0.5
#define BASE_TEA 10
#define BASE_TOPPINGS 5
#define BASE_COST 6.5

// enum definitions
enum bubble_tea_type {
    MILK_TEA,
    FRUIT_TEA,
    TARO_MILK,
    MATCHA_LATTE,
};

enum topping_types {
    TAPIOCA_PEARLS,
    JELLY,
    POPPING_PEARLS,
    ALOE_VERA,
};

// struct definitions
struct bubble_tea {
    enum bubble_tea_type type;
    enum topping_types topping;
    int topping_qty;
    char size;
};

struct inventory {
    int tea;
    int toppings;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// FUNCTION PROTOTYPES /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Add functions prototypes here

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// MAIN FUNCTION ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

enum bubble_tea_type scan_bubble_tea_type();
int is_insufficient_inventory(struct inventory inventory, struct bubble_tea order);

int main(void) {
    struct inventory inventory;
    inventory.tea = BASE_TEA;
    inventory.toppings = BASE_TOPPINGS;

    // Take the user's bubble tea order
    struct bubble_tea order;

    order.type = scan_bubble_tea_type();

    printf("Enter topping (0: TAPIOCA PEARLS, 1: JELLY, 2: POPPING PEARLS, "
            "3: ALOE VERA): ");
    int type;
    scanf("%d", &type);
    if (type == 0) {
        order.topping = TAPIOCA_PEARLS;
    } else if (type == 1) {
        order.topping = JELLY;
    } else if (type == 2) {
        order.topping = POPPING_PEARLS;
    } else if (type == 3) {
        order.topping = ALOE_VERA;
    }

    printf("Enter topping qty: ");
    scanf("%d", &order.topping_qty);

    printf("Enter size (L for Large, R for Regular): ");
    scanf(" %c", &order.size);

    // Check available stock and end the program if insufficient stock
    if (is_insufficient_inventory(inventory, order)) {
        printf("Sorry, we cannot fulfill your bubble tea order due to "
                "insufficient stock.\n");
        return 1; 
    }

    

    // Print the final order and cost
    print_order_details(order);

    

    // Update the stock after fulfilling the order
    inventory = update_inventory(inventory, order);

    // Step 6: print the remaining inventory
    print_inventory_details(inventory);


    return 0;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// FUNCTION DEFINITIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

enum bubble_tea_type scan_bubble_tea_type() {
    int type;

    printf("Enter bubble tea type (0: MILK TEA, 1: FRUIT TEA, 2: TARO MILK, "
            "3: MATCHA LATTE): ");
    scanf("%d", &type);
    if (type == 0) {
        return MILK_TEA;
    } else if (type == 1) {
        return FRUIT_TEA;
    } else if (type == 2) {
        return TARO_MILK;
    } else if (type == 3) {
        return MATCHA_LATTE;
    } else {
        return -1;
    }
}

int is_insufficient_inventory(struct inventory inventory, struct bubble_tea order) {
    return inventory.tea - 1 <= 0 ||
        inventory.toppings - order.topping_qty <= 0;
}

double calculate_cost(struct bubble_tea order) {
    // Calculate the cost
    double total_cost = BASE_COST;

    if (order.size == LARGE) {
        total_cost += ADDED_COST;
    }

    if (order.type == MILK_TEA ||
        order.type == TARO_MILK ||
        order.type == MATCHA_LATTE) {
        total_cost += ADDED_COST;
    }

    int count = 0;
    while (count < order.topping_qty) {
        total_cost += ADDED_COST;
        count++;
    }

    return total_cost;
}

struct inventory update_inventory(struct inventory inventory, struct bubble_tea order) {
    if (order.size == LARGE) {
        inventory.tea -= 2;
    } else {
        inventory.tea -= 1;
    }
            
    inventory.toppings -= order.topping_qty;

    return inventory;
}

void print_order_details(struct bubble_tea order) {
    printf("Order:\n");
    printf("Type: %d\n", order.type);
    printf("Topping Qty: %d\n", order.topping_qty);
    printf("Size: %c\n", order.size);

    double total_cost = calculate_cost(order);
    printf("Total Cost: %.2lf\n", total_cost);
}

void print_inventory_details(struct inventory inventory) {
    printf("The current inventory is: ");
    printf("Bubble tea(s): %d\n", inventory.tea);
    printf("Topping(s): %d\n", inventory.toppings);
}