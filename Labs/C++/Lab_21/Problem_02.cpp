// Lab 21 - Problem 2
// Derek P Sifford
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


struct letter {
    struct {
        int upper;
        int lower;
    };
};

int openFile(ifstream&, ofstream&);
int count(letter[26], ifstream&);
int printResult(letter[26], ofstream&);

int main() {

    ifstream input;
    ofstream output;
    letter _a = {{0,0}}, _b = {{0,0}}, _c = {{0,0}}, _d = {{0,0}}, _e = {{0,0}},
        _f = {{0,0}}, _g = {{0,0}}, _h = {{0,0}}, _i = {{0,0}}, _k = {{0,0}},
        _l = {{0,0}}, _m = {{0,0}}, _n = {{0,0}}, _o = {{0,0}}, _p = {{0,0}},
        _q = {{0,0}}, _r = {{0,0}}, _s = {{0,0}}, _t = {{0,0}}, _u = {{0,0}},
        _v = {{0,0}}, _w = {{0,0}}, _x = {{0,0}}, _y = {{0,0}}, _z = {{0,0}};

    letter letterArr[26] = {_a, _b, _c, _d, _e, _f, _g, _h, _i, _k, _l, _m,
        _n, _o, _p, _q, _r, _s, _t, _u, _v, _w, _x, _y, _z};

    int err = openFile(input, output);
    if (err == 1) {
        cout << "One of the files you specified could not be opened. Exiting..." << endl;
        return 1;
    }

    count(letterArr, input);
    printResult(letterArr, output);

    return 0;
}

/**
 * Takes an input file stream and output file stream by reference and opens them.
 *
 * Once the open method is called on each file, it checks to be sure that the file is indeed open. If not (i.e., if there was an error) the function returns an error code
 * @param  input  Input file stream reference
 * @param  output Ouput file stream reference
 * @return        Status code
 */
int openFile(ifstream &input, ofstream &output) {

    string inputName, outputName;

    cout << "Enter the name of the input file" << endl;
    cin >> inputName;

    input.open(inputName);
    if (!input.is_open())
        return 1;

    cout << "Enter the name of the output file" << endl;
    cin >> outputName;

    output.open(outputName);
    if (!output.is_open())
        return 1;

    return 0;
}

/**
 * Counts and stores the times each letter is present in the input file.
 *
 * This function simply takes an array of type letter and loops over each
 *   character of the input file. For each character, a conditional is checked
 *   to see if the int value of the character in question matches the ASCII code
 *   of either a lowercase or uppercase letter. Depending on which it is (and
 *   what letter), the value for that letter is incremented in the letter array.
 * @param letter  Array of type letter and length 26
 * @param file    Input file passed by reference
 * @return        Status code
 */

int count(letter arr[26], ifstream &file) {

    char l;

    while (file >> l) {
        if (64 < int(l) && int(l) < 91) {
            arr[int(l)-65].upper++;
            continue;
        }
        if (96 < int(l) && int(l) < 123) {
            arr[int(l)-97].lower++;
        }
    }

    file.close();

    return 0;
}

/**
 * Responsible for printing the required computations to the output file.
 *
 * NOTE: The instructions for this part were not good. It wasn't clear whether
 *   the results should be printed to std out or if they should be printed to
 *   the output file. I chose the output file because why else would we be
 *   opening it in the first place?
 *
 * First, the function loops through the letter array and calculates the sum of
 *   all lowercase and uppercase letters. Then the percentage of uppercase is
 *   calculated. The percentage of lowercase is not explicitly calculated
 *   because it must be the complement to the percentage of uppercase. Finally,
 *   the required parameters are printed to the output file and the file is
 *   closed.
 *
 * @param arr   Array of type letter and length 26
 * @param file  Output file stream passed as reference
 * @return      Status code
 */
int printResult(letter arr[26], ofstream &file) {

    int upperCount = 0, lowerCount = 0;
    double upperPercent;

    for (int i = 0; i < 26; i++) {
        upperCount += arr[i].upper;
        lowerCount += arr[i].lower;
    }

    upperPercent = upperCount / (upperCount+lowerCount);

    file
        << "# of uppercase letters: " << upperCount << endl
        << "# of lowercase letters: " << lowerCount << endl << endl
        << "Percent uppercase letters: " << int(upperPercent * 100) << "%\n"
        << "Percent lowercase letters: " << int((1 - upperPercent) * 100) << "%\n\n";

    file << "Counts of all letters:" << endl;

    for (int i = 0; i < 26; i++) {
        file << char(i + 65) << ": " << arr[i].upper << endl;
        file << char(i + 97) << ": " << arr[i].lower << endl;
    }

    file.close();

    return 0;
}
