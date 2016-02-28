// Lab 10
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {

    char input;
    int group1 = 0, group2 = 0, sum = 0, i = 0;
    int n;

    cout << "Enter an integer\n";
    while (cin.get(input)) {
        if (input == '\n')
            break;

        n = int(input) - 48;

        if (i % 2 == 0) {
            group1 = group1 + n;
        }
        else {
            group2 = group2 + n;
        }
        i++;

    }

    if ((group1 + group2) % 2 == 0) {
        group1 = group1 * -1;
    } else {
        group2 = group2 * -1;
    }

    sum = group1 + group2;

    if (sum % 11 == 0) {
        cout << "The number is divisible by 11\n";
    } else {
        cout << "The number is not divisible by 11\n";
    }

}
