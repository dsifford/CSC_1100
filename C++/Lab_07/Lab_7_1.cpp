// Lab 7 - Problem 1
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {

    double num1, num2, num3;
    cout << "Enter three numbers" << endl;
    cin >> num1 >> num2 >> num3;

    if (num1 > num2) {
        if (num1 > num3) {
            if (num3 > num2) {
                cout << num1 << "\n" << num3 << "\n" << num2 << endl;
            } else {
                cout << num1 << "\n" << num2 << "\n" << num3 << endl;
            }
        } else {
            cout << num3 << "\n" << num1 << "\n" << num2;
        }
    } else {
        if (num2 > num3) {
            if (num3 > num1) {
                cout << num2 << "\n" << num3 << "\n" << num1;
            } else {
                cout << num2 << "\n" << num1 << "\n" << num3;
            }
        } else {
            cout << num3 << "\n" << num2 << "\n" << num1;
        }
    }

    return 0;
}
