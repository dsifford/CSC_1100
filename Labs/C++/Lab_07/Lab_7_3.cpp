// Lab 7 - Problem 3
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {

    int grade;
    cout << "Enter your percentage\n";
    cin >> grade;

    if (grade > 89 && grade < 101) {
        cout << "A\n";
    } else if (grade > 79 && grade < 90) {
        cout << "B\n";
    } else if (grade > 69 && grade < 80) {
        cout << "C\n";
    } else if (grade > 59 && grade < 70) {
        cout << "D\n";
    } else if (grade > 0 && grade < 60) {
        cout << "F\n";
    } else {
        cout << "Input not within range. Please try again.\n";
    }

    return 0;
}
