#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(void) {
    ifstream file("input.txt");
    string line;

    int total = 0;

    while (getline(file, line)) {
        stringstream ss;
        string temp;
        int temp_int;
        bool found = false;
        vector<int> numbers_1;

        ss << line;

        // Add numbers in line to vector
        while (!ss.eof()) {
            ss >> temp;
            stringstream(temp) >> temp_int;
            numbers_1.push_back(temp_int);

        }

        // Make duplicate of vector (deep copy)
        vector<int> numbers_2(numbers_1);

        // Find result of evenly divisible values and add to total
        for (int index_1 = 0; index_1 < numbers_1.size(); index_1++) {
            for (int index_2 = 0; index_2 < numbers_2.size(); index_2++) {

                if (numbers_1[index_1] == numbers_2[index_2])
                    continue;

                if (numbers_1[index_1] % numbers_2[index_2] == 0) {
                    found = true;
                    total += (numbers_1[index_1] / numbers_2[index_2]);
                }
            }
            if (found)
                break;
        }
    }

    cout << "Final result = " << total << endl;

    return 0;
}