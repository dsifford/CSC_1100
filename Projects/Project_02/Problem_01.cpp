// Project 2 - Problem 1
// Derek P Sifford
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

string getInput();
string reversed(string);
int getLargestSize(string, string);
int typeSwap(char);
char typeSwap(int);
string calcSum(string, string);
void displayResult(string);
void test();

int main() {

    test();

    string input1 = getInput();
    string input2 = getInput();

    displayResult(calcSum(input1, input2));

    return 0;
}


string getInput() {

    string input;

    while(true) {

        bool isInvalidInput = false;
        cout << "Please enter an integer up to 20 digits long" << endl;
        getline(cin, input, '\n');

        if (input.length() > 20) continue;

        for (int i : input) {
            switch (i) {
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                case 56:
                case 57:
                    break;
                default:
                    isInvalidInput = true;
            }
        }

        if (isInvalidInput) continue;

        break;
    }

    return input;
}

int getLargestSize(string x, string y) {
    if (x.length() >= y.length()) {
        return x.length();
    }
    return y.length();
}

string reversed(string x) {
    string output = "";
    for (int i = x.length() - 1; i >= 0; i-- ) {
        output += x[i];
    }
    return output;
}

int typeSwap(char x) {
    switch (x) {
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 5;
        case 54:
            return 6;
        case 55:
            return 7;
        case 56:
            return 8;
        case 57:
            return 9;
    }
    return 0;
}

char typeSwap(int x) {
    switch (x) {
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
    }
    return '0';
}

string calcSum(string x, string y) {

    x = reversed(x);
    y = reversed(y);

    int iterator = getLargestSize(x, y);
    int intermediate[iterator];
    int _remainder = 0;
    int calcValue;
    string output = "";

    for (int i = 0; i < iterator; i++) {
        calcValue = typeSwap(x[i]) + typeSwap(y[i]) + _remainder;

        if (calcValue < 10) {
            intermediate[i] = calcValue;
            _remainder = 0;
            continue;
        }

        intermediate[i] = calcValue - 10;
        _remainder = 1;

    }

    if (_remainder == 1) {
        output += typeSwap(_remainder);
    }

    for (int i = iterator - 1; i >= 0; i--) {
        output += typeSwap(intermediate[i]);
    }

    return output;

}

void displayResult(string res) {
    // cout << "The sum of the two numbers is: " << res << endl;
    for (size_t i = 0; i < res.length(); i++) {
        cout << res[i] << endl;
    }
    cout << "DONE" << endl;
}


void test() {


    assert(reversed("abcd") == "dcba");
    assert(reversed("5d 6 9!j 0") == "0 j!9 6 d5");
    assert(reversed("123456789") == "987654321");
    assert(reversed("") == "");
    assert(reversed("55155") == "55155");

    assert(getLargestSize("12345", "123") == 5);
    assert(getLargestSize("4654819681", "465481968") == 10);
    assert(getLargestSize("12345", "12345") == 5);
    assert(getLargestSize("9999", "1111111111") == 10);
    assert(getLargestSize("1", "123") == 3);

    assert(typeSwap('4') == 4);
    assert(typeSwap('9') == 9);
    assert(typeSwap('2') == 2);
    assert(typeSwap(' ') == 0);

    assert(calcSum("12345", "54321") == "66666");
    assert(calcSum("7123741235615", "12398758971243") == "19522500206858");
    assert(calcSum("99999999999999999999", "1234") == "100000000000000001233");
    assert(calcSum("6541884", "") == "6541884");
    assert(calcSum("", "55555555555555555555") == "55555555555555555555");

    cout << "==== Tests Passed ====" << endl;

}
