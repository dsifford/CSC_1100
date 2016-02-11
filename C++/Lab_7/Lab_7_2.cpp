// Lab 7 - Problem 2
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char op;

    cout << "Enter two integers" << endl;
    cin >> num1 >> num2;

    cout << "Enter the operation to be performed (+, -, *, /)" << endl;
    cin >> op;

    switch (+op) {
        case (43):
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case (45):
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case (42):
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case (47):
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            cout << "Invalid operator. Please try again." << endl;
    }

}
