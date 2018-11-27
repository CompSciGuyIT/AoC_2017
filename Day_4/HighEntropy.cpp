#include <iostream>     // cout
#include <fstream>      // file getline
#include <sstream>      // istringstream 
#include <vector>
#include <iterator>     // istream_iterator

using namespace std;

int main(void) {
    ifstream file("passphrases.txt");
    string line;

    int number_valid = 0;

    // Get each passphrase
    while(getline(file, line)) {
        // Separate each word to a separate string in vector
        istringstream iss(line);
        vector<string> results((istream_iterator<string>(iss)),
                                         istream_iterator<string>());
        // Initialise flag
        bool duplicate = false;

        // compare each string to one another
        for (int index_1 = 0; index_1 < results.size() - 1; index_1++) {
            for (int index_2 = index_1 + 1; index_2 < results.size(); index_2++) {
                if (results.at(index_1).compare(results.at(index_2)) == 0)
                    duplicate = true;
            }
        }

        // Increment number_valid if passed
        if (!duplicate)
            number_valid++;
    }

    cout << "The number of valid passphrases is " << number_valid << endl;

    return 0;
}