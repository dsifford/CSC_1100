// Lab 1, Problem 2
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {

    double capacity, mpg, totalMiles;

    cout << "What is the capacity of your fuel tank?" << endl;
    cin >> capacity;

    cout << "How many miles does your vehicle get per gallon?" << endl;
    cin >> mpg;

    totalMiles = capacity * mpg;

    cout << "Your vehicle can travel a total of " << totalMiles << " miles without refueling.";

    return 0;
}
