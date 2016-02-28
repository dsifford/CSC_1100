// Lab 11 - Problem 3
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;

int getLowerVowels(string input, bool includeY) {

    // Instantiate a counter
    int numLCVowels = 0;

    // Loop through the input, incrementing the counter each time a
    // lowercase letter is found (as determined by the ascii code).
    // A conditional exists in the 'y' case to only include it if
    // the 'includeY' param is true
    for (int i = 0; i < input.length(); i++) {
        int x = int(input[i]);
        switch(x) {
            case 97:
            case 101:
            case 105:
            case 111:
            case 117:
                numLCVowels++;
                break;
            case 121:
                if (includeY) {
                    numLCVowels++;
                }
                break;
            default:
                break;
        }
    }

    return numLCVowels;
}

int main() {

    string input;
    char isYVowel;
    bool yIsVowel, wrongInput = true;

    cout << "Enter any string" << endl;
    getline(cin, input);

    // Logic to handle whether or not the user considers 'y' to be
    // a vowel. Switches on ASCII code.
    // If the user can't follow directions, keep looping over cin
    // until they learn how to follow directions
    cout << "Do you consider 'Y' to be a vowel? [y/n]" << endl;
    while (wrongInput) {
        cin >> isYVowel;
        switch (int(isYVowel)) {
            case 121:
            case 89:
                yIsVowel = true;
                wrongInput = false;
                break;
            case 110:
            case 78:
                yIsVowel = false;
                wrongInput = false;
                break;
            default:
                cout << "Please enter either 'y' or 'n'" << endl;
        }
    }


    cout << "The number of lowercase vowels in your input is: " <<
        getLowerVowels(input, yIsVowel) << endl;

    return 0;
}
