// Type definitions
// Program by: Derek P Sifford

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a = 20, b = 7;
    double x = 20, y = 7, z = 0;

    z = a + b;
    cout << "20 + 7 = " << z << endl;

    z = a - b;
    cout << "20 - 7 = " << z << endl;

    z = b - a;
    cout << "7 - 20 = " << z << endl;

    z = a * b;
    cout << "20 * 7 = " << z << endl;

    z = a / b;
    cout << "20 / 7 = " << z << endl;

    z = x / y;
    cout << "20 / 7 = " << z << endl;

    z = fmod(x, y);
    cout << "20 % 7 = " << z << endl;

    z = fmod(y, x);
    cout << "7 % 20 = " << z << endl;


    return 0;
}
