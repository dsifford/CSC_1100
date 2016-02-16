// Lab 8
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {

    int popA, popB;
    double growthA, growthB;
    int yrs = 0;

    cout << "Enter the population of town A" << endl;
    cin >> popA;

    cout << "Enter the growth rate of town A" << endl;
    cin >> growthA;

    cout << "Enter the population of town B" << endl;
    cin >> popB;

    cout << "Enter the growth rate of town B" << endl;
    cin >> growthB;

    if (growthA > 1) {
        growthA = growthA / 100;
    }

    if (growthB > 1) {
        growthB = growthB / 100;
    }

    while (popB >= popA) {
        popB = (popB * growthB) + popB;
        popA = (popA * growthA) + popA;
        yrs++;
    }

    cout << "The population of town A will be greater than town B after " << yrs << " years.\n";
    cout << "The population of town A is: " << popA << endl;
    cout << "The population of town B is: " << popB << endl;

    return 0;
}
