// Lab 6
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {


    double baseSalary, noOfServiceYears, totalSales, bonus, additionalBonus, payCheck;

    cout << "Enter base salary" << endl;
    cin >> baseSalary;

    cout << "Enter number of years worked" << endl;
    cin >> noOfServiceYears;

    cout << "Enter total sales" << endl;
    cin >> totalSales;

    if (noOfServiceYears <= 5) {
        bonus = 10 * noOfServiceYears;
    } else {
        bonus = 20 * noOfServiceYears;
    }

    if (totalSales < 5000) {
        additionalBonus = 0;
    } else if (totalSales > 100000) {
        additionalBonus = (totalSales * 0.06) + totalSales;
    } else {
        additionalBonus = (totalSales * 0.03) + totalSales;
    }

    payCheck = baseSalary + bonus + additionalBonus;

    cout << "The paycheck for this month is: $" << payCheck << endl;

    return 0;
}
