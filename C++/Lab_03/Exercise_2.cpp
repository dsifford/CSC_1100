// Exercise 2
// Derek P Sifford
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

    float kg, lbs;

    cout << "Enter your weight in kilograms" << endl;
    cin >> kg;

    lbs = kg * 2.2;

    cout << "Pounds: " << fixed << setprecision(2) << lbs << endl;
    cout << "Kilograms: " << fixed << setprecision(2) << kg << endl;

    return 0;
}
