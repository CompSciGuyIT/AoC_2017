#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    // For initial square to be set to all zeros,
    // must set direction_count to -1 in Down direction
    // to simulate what would be that prior array state
    int direction_count[4] = {0, 0, 0, -1}; // [Right, Up, Left, Down]
    int direction_index = 3;                // indexes direction_count array
    
    int change_direction = 1;               // increment direction_index at 0
    int increase_direction_limit = 1;       // reassign direction_limit at 0
    
    int direction_limit = 0;                // assigned to change_direction when it reaches 0
    const int limit_changes = 2;            // number of direction changes before increasing direction_limit
    const int direction_count_limit = 4;    // keeps direction_index within scope of direction_count array
    int input;

    /* Get user input */
    cout << "Enter puzzle input: ";
    cin >> input;

    /* Find position on grid */
    for (int square = 1; square <= input; square++) {
        // Increase direction moved in by 1
        direction_count[direction_index]++;
        
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
    int distance = abs(direction_count[0] - direction_count[2]) + abs(direction_count[1] - direction_count[3]);

    cout << distance << endl;

    return 0;
}