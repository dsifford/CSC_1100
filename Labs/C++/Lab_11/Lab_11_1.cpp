// Lab 11 - Problem 1
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;


int reverseDigit(int input) {
    bool isNeg = false;
    string process, payload;

    // If input is neative, keep a memory of that using isNeg
    // and then make it positive
    if (input < 0) {
        isNeg = true;
        input *= -1;
    }

    // Convert to string so we can work with it easier
    process = to_string(input);

    // Loop through the length of the string, and reverse it
    for (int i = 0; i < process.length(); i++) {
        payload = process[i] + payload;
    }

    // Was the input integer negative? If so, append a negative sign
    payload = (isNeg) ? "-" + payload : payload;

    // Return payload converted to a signed integer
    return stoi(payload);
}

int main() {

    int input;

    cout << "Enter an integer" << endl;
    cin >> input;

    cout << reverseDigit(input) << endl;

    return 0;
}
