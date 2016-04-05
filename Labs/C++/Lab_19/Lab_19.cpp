// Lab 19
// Derek P Sifford
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string reverse(string x);
void test();

int main() {

    test();

    string input;

    cout << "Enter any string" << endl;
    getline(cin, input, '\n');

    input = reverse(input);

    cout << "Your string reversed is: " << input << endl;

    return 0;
}


string reverse(string x) {

    x.c_str();

    string output;

    for (int i = x.length() - 1; i >= 0; i--) {
        output += x[i];
    }

    return output;

}

void test() {

    assert(reverse("abcd") == "dcba");
    assert(reverse("a d 3 x 8fd") == "df8 x 3 d a");
    assert(reverse("2jc93dnx") == "xnd39cj2");

    cout << "==== Tests Passed ====" << endl;
}
