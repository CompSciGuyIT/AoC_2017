#include <iostream>
#include <cmath>
#include <stdlib.h> 

using namespace std;

struct square {
    int x_coord;
    int y_coord;
    int value;
};

struct node {
    square sqr;
    node *next;
};

node * add_square(node *, square *);

int main(void) {
    int direction_index = 3;                // indexes direction_count array
    
    int change_direction = 1;               // increment direction_index at 0
    int increase_direction_limit = 1;       // reassign direction_limit at 0
    
    int direction_limit = 0;                // assigned to change_direction when it reaches 0
    const int limit_changes = 2;            // number of direction changes before increasing direction_limit
    const int direction_count_limit = 4;    // keeps direction_index within scope of direction_count array
    int input;

    int x = 0;
    int y = 1;
    int total_value;


    // Initialise linked list
    node *squares = NULL;

    /* Get user input */
    cout << "Enter puzzle input: ";
    cin >> input;

    /* Find position on grid */
    for (int index = 1; index <= input; index++) {
        total_value = 0;

        // Move to next square
        switch (direction_index) {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
        }

        // Check adjacent squares and add to total
        node *head = squares;

        for ( ; squares != NULL; squares = squares->next) {

            // Check if above-left square exists
            if (squares->sqr.x_coord == x - 1 && squares->sqr.y_coord == y + 1)
                total_value += squares->sqr.value;

            // Check if above square exists
            if (squares->sqr.x_coord == x && squares->sqr.y_coord == y + 1)
                total_value += squares->sqr.value;

            // Check if above-right square exists
            if (squares->sqr.x_coord == x + 1 && squares->sqr.y_coord == y + 1)
                total_value += squares->sqr.value;

            // Check if left square exists
            if (squares->sqr.x_coord == x - 1 && squares->sqr.y_coord == y)
                total_value += squares->sqr.value;

            // Check if right square exists
            if (squares->sqr.x_coord == x + 1 && squares->sqr.y_coord == y)
                total_value += squares->sqr.value;

            // Check if below-left square exists
            if (squares->sqr.x_coord == x - 1 && squares->sqr.y_coord == y - 1)
                total_value += squares->sqr.value;

            // Check if below square exists
            if (squares->sqr.x_coord == x && squares->sqr.y_coord == y - 1)
                total_value += squares->sqr.value;

            // Check if below-right square exists
            if (squares->sqr.x_coord == x + 1 && squares->sqr.y_coord == y - 1)
                total_value += squares->sqr.value;       
        }

        squares = head;

        // Check total against input and exit loop if over
        if (total_value > input)
            break;

        // Add node to list
        square *new_square = new square;

        new_square->x_coord = x;
        new_square->y_coord = y;

        if (x == 0 && y == 0)
            new_square->value = 1;
        else
            new_square->value = total_value;

        node *new_head = add_square(squares, new_square);
        if (new_head == NULL) {
            cout << "memory allocation failure\n";
            
            exit(EXIT_FAILURE);
        }
        squares = new_head;

        delete new_square;

        /* Check if need to change direction */
        change_direction--;

        if (!change_direction) {
            // Set array index
            direction_index++;
            direction_index %= direction_count_limit;

            increase_direction_limit--;

            // Check if need to increase step size
            if (!increase_direction_limit) {
                direction_limit++;

                // Reset increase_direction_limit
                increase_direction_limit = limit_changes;
            }

            // reset change_direction
            change_direction = direction_limit;
        }
    }

    /* Find distance from origin */

    cout << total_value << endl;

    return 0;
}

/* Add authenticated player to the list of players */
node * add_square(node *squares, square *sqr) {

    /* Create a new node to add to the list */
    node *new_node = new node;

    /* Insert new node */
    new_node->sqr = *sqr;
    new_node->next = squares;

    return new_node;
}