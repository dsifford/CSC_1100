// Lab 9 - Problem 3
// Derek P Sifford
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int num;
    cout << "Enter a positive integer\n";
    cin >> num;

    if (num < 0) {
        cout << "The integer must be positive\n";
        return 0;
    }

    if (num % 2 == 0) {
        if (num == 2) {
            cout << "The number is prime\n";
            return 0;
        }
        cout << "The number is not prime\n";
    }
    else {
        int num2 = sqrt(num);
        int counter = 3;

        while (counter <= num2) {
            if (num % counter == 0) {
                cout << "The number is not prime\n";
                return 0;
            }
            counter = counter + 2;
        }
        cout << "The number is prime\n";
    }

    return 0;
}
