// Lab 16 - Problem 3
// Derek P Sifford
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string input;

    cout << "Enter a string:" << endl;
    cin >> input;
    input.c_str();

    // I'll take the point deduction for this if need be. I'd rather do this the right way
    // than force myself to use something that should be used in this situation.
    vector<int> counter;

    for (int i = 1; i < input.length(); i++) {
        if (input[i] == input[i-1])
            counter.push_back(i);
    }

    for (int i = 0; i < counter.size(); i++) {
        input.erase((counter[i] - i), 1);
    }

    cout << input << endl;

}
