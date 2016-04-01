// Lab 18 - Problem 1
// Derek P Sifford
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

const double POPCORN_PRICES[4] = {1.25, 2.25, 3.50, 4.25};
const double DRINK_PRICES[4] = {1.50, 2.50, 3.75, 4.50};

void test();
double getPrice(int input1 = -1, int input2 = -1);


int main() {

    test();
    getPrice();

    return 0;
}

double getPrice(int input1, int input2) {
    enum sizes {SMALL, MEDIUM, LARGE, JUMBO};
    sizes popcornSize, drinkSize;
    bool isTest = (input1 != -1 ? true : false);

    int input;
    if (!isTest) {
        printf(
            "Choose a popcorn size from one of the following\n"
            "0) Small\n"
            "1) Medium\n"
            "2) Large\n"
            "4) Jumbo\n"
        );
        do {
            cin >> input;
        } while (input < 0 || 4 < input);
    } else {
        input = input1;
    }

    switch (input) {
        case SMALL:
            popcornSize = SMALL;
            break;
        case MEDIUM:
            popcornSize = MEDIUM;
            break;
        case LARGE:
            popcornSize = LARGE;
            break;
        case JUMBO:
            popcornSize = JUMBO;
            break;
    }

    if (!isTest) {
        printf(
            "Choose a drink size from one of the following\n"
            "0) Small\n"
            "1) Medium\n"
            "2) Large\n"
            "4) Jumbo\n"
        );
        do {
            cin >> input;
        } while (input < 0 || 4 < input);
    } else {
        input = input2;
    }

    switch (input) {
        case SMALL:
            drinkSize = SMALL;
            break;
        case MEDIUM:
            drinkSize = MEDIUM;
            break;
        case LARGE:
            drinkSize = LARGE;
            break;
        case JUMBO:
            drinkSize = JUMBO;
            break;
    }

    double totalPrice = POPCORN_PRICES[popcornSize] + DRINK_PRICES[drinkSize];

    if (!isTest) {
        cout << fixed << setprecision(2);
        cout << "Your total cost is $" << totalPrice << endl;
    }
    return totalPrice;
}

void test() {

    assert(getPrice(0, 0) == 2.75);
    assert(getPrice(0, 2) == 5);
    assert(getPrice(3, 1) == 6.75);
    assert(getPrice(1, 3) == 6.75);
    assert(getPrice(2, 0) == 5);
    assert(getPrice(2, 2) == 7.25);
    assert(getPrice(3, 3) == 8.75);
    assert(getPrice(1, 1) == 4.75);
    assert(getPrice(0, 3) == 5.75);
    cout << "==== Tests passed ====" << endl;

}
