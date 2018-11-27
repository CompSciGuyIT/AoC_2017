#include <iostream>     // cout
#include <fstream>      // file getline
#include <sstream>      // istringstream 
#include <vector>
#include <iterator>     // istream_iterator
#include <algorithm>    // sort

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
        bool anagram = false;

        // compare each string to one another for anagrams
        for (int index_1 = 0; index_1 < results.size() - 1; index_1++) {
            for (int index_2 = index_1 + 1; index_2 < results.size(); index_2++) {
                sort(results.at(index_1).begin(), results.at(index_1).end());
                sort(results.at(index_2).begin(), results.at(index_2).end());
                
                if (results.at(index_1).compare(results.at(index_2)) == 0)
                    anagram = true;
            }
        }

        // Increment number_valid if passed
        if (!anagram)
            number_valid++;
    }

    cout << "The number of valid passphrases is " << number_valid << endl;

    return 0;
}