#include <iostream>
using namespace std;

int main() {

    int num1, num2, num3, num4, num5, average;

    cout << "Enter 5 numbers" << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    cin >> num5;
    average = (num1 + num2 + num3 + num4 + num5) / 5;
    cout << "Average = " << average << endl;

    return 0;
}
