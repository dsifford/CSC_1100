// Lab 18 - Problem 3
// Derek P Sifford
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


string removeVowels(string);
bool isVowel(char);
void test();

int main() {

    test();

    string input, newString;
    cout << "Enter a string" << endl;
    getline(cin, input, '\n');

    newString = removeVowels(input);

    cout << "Your string without vowels is: " << newString << endl;

    return 0;
}

bool isVowel(char x) {

    switch(int(x)) {
        case 65:
        case 69:
        case 73:
        case 79:
        case 85:
        case 89:
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
        case 121:
            return true;
        default:
            return false;
    }

}

string removeVowels(string input) {

    string output = "";
    for (char i : input) {
        if (!isVowel(i)) output+= i;
    }

    return output;
}

void test() {

    assert(removeVowels("this is a test") == "ths s  tst");
    assert(removeVowels("rEmOve All thE vowEls") == "rmv ll th vwls");
    assert(removeVowels("aeiouyAEIOUY") == "");
    assert(removeVowels("x dDv jcCPl ;35 19") == "x dDv jcCPl ;35 19");

    cout << "==== Tests Passed ====" << endl;

}
