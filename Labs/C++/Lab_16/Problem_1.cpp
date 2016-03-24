// Lab 16 - Problem 1
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;


int main() {

    string input;
    cin >> input;

    // Convert the string to a C-string
    input.c_str();

    // Convert each C-string character to its ASCII number and adjust if it
    // is a lowercase letter
    for (int i = 0; i < input.length(); i++) {
        if (96 < int(input[i]) && int(input[i]) < 123)
            input[i] = int(input[i]) - 32;
    }

    cout << input << endl;

    return 0;
}
