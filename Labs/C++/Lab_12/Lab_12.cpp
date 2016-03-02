// Lab 12
// Derek P Sifford
#include <iostream>
using namespace std;

void inputFunc(double& current, double& oneYear, double& twoYear) {

    cout << "Enter the current price" << endl;
    cin >> current;

    cout << "Enter the price one year ago" << endl;
    cin >> oneYear;

    cout << "Enter the price two years ago" << endl;
    cin >> twoYear;

}

double calculate(double current, double past) {
    return (current - past) / past;
}

void output(double result1, double result2) {
    if (result1 > result2) {
        cout << "Inflation is increasing" << endl;
        return;
    }

    if (result2 > result1) {
        cout << "Inflation is decreasing" << endl;
        return;
    }
}

int main() {

    double current, oneYear, twoYear, result1, result2;
    inputFunc(current, oneYear, twoYear);
    result1 = calculate(current, oneYear);
    result2 = calculate(oneYear, twoYear);
    output(result1, result2);

    return 0;
}
