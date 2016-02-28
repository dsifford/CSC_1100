// Lab 11 - Problem 2
// Derek P Sifford
#include <iostream>
#include <cmath>
using namespace std;

// Simply return the mean from the inputted numbers
double mean(double x1, double x2, double x3, double x4, double x5) {
    return ((x1 + x2 + x3 + x4 + x5) / 5);
}

double sd(double x1, double x2, double x3, double x4, double x5) {
    // First calculate the mean
    double x = mean(x1, x2, x3, x4, x5);

    // Next, calculate the sum of squared deviations
    double ssq = pow((x1 - x), 2) + pow((x2 - x), 2) + pow((x3 - x), 2) +
        pow((x4 - x), 2) + pow((x5 - x), 2);

    // Return the standard deviation
    return sqrt(ssq / 5);
}

int main() {
    int x1, x2, x3, x4, x5;

    cout << "Enter five numbers" << endl;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;

    cout << "The mean of your numbers is:\t" << mean(x1, x2, x3, x4, x5) << endl;
    cout << "The SD of your numbers is:\t" << sd(x1, x2, x3, x4, x5) << endl;

    return 0;
}
