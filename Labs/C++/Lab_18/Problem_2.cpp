// Lab 18 - Problem 2
// Derek P Sifford
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void test();
string _find(string input1 = "", string input2 = "");


int main() {

    test();
    _find();

    return 0;
}

string _find(string input1, string input2) {

    bool isTest = input1 != "" ? true : false;

    if (!isTest) {
        cout << "HAYSTACK: Enter any string." << endl;
        getline(cin, input1, '\n');
        cout << "NEEDLE: Enter a string to find in the haystack." << endl;
        getline(cin, input2, '\n');
    }

    int found = 0, pos = -1;
    string output = "";

    while (input1.find(input2, pos + 1) != input1.npos) {
        found = input1.find(input2, pos + 1);
        pos = int(found);
        output += to_string(pos) + ", ";
    }

    output = output.substr(0, output.length() - 2);

    if (!isTest) {
        if (output == "") {
            cout << "No occurrences of the 'needle' string found." << endl;
        } else {
            cout << "Found '" << input2 << "' at the following positions:\n" <<
                output << endl;
        }
    }

    return output;
}

void test() {

    assert(_find("this is a test", "test") == "10");
    assert(_find("the test test the test the", "the") == "0, 14, 23");
    assert(_find("this test will fail", "pass") == "");
    assert(_find("this test will pass", "pass") == "15");
    assert(_find("aaaaa", "a") == "0, 1, 2, 3, 4");
    assert(_find("ababababa", "a") == "0, 2, 4, 6, 8");
    assert(_find("AaAaAaA", "a") == "1, 3, 5");

    cout << "==== Tests Passed ====" << endl;

}
