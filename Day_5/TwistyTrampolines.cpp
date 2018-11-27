#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main (void) {
    int array[1003];    // 1003 is the number of integers in the file
    int steps = 0;
    int index = 0;

    // Read file into array
    ifstream file("input.txt");
    string line;
    int value;

    while(getline(file, line)) {
        stringstream integer(line);
        integer >> value;

        array[index] = value;

        index++;
    }

    index = 0;

    // Loop until index is out of bounds
    while(1) {
        // Increment value of Array at index
        array[index]++;

        // Add value to index minus 1
        index += (array[index] - 1);

        // Increment steps
        steps++;

        // Check if index is out of bounds
        if (index < 0 || index > 1002) {
            cout << "Steps: " << steps << endl;
            break;
        }
    }

    return 0;
}