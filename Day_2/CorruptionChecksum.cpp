#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
    ifstream file("input.txt");
    string line;

    int total = 0;

    while (getline(file, line)) {
        stringstream ss;
        string temp;
        int temp_int;

        int smallest = 0;
        int largest = 0;

        ss << line;

        while (!ss.eof()) {
            ss >> temp;

            stringstream(temp) >> temp_int;

            if (temp_int > largest)
                largest = temp_int;

            if (smallest == 0 || temp_int < smallest)
                smallest = temp_int;
        }

        total += (largest - smallest);
    }

    cout << total << endl;

    return 0;
}