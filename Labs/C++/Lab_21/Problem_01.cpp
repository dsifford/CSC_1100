// Lab 21 - Problem 1
// Derek P Sifford
#include <iostream>
#include <cassert>
using namespace std;

struct fraction {
    int numerator;
    int denominator;
};

fraction sumFractions(fraction, fraction);
void test();

int main() {

    test();

    fraction f1;
    fraction f2;

    cout << "Enter the integers for fraction 1" << endl;
    cin >> f1.numerator;
    cin >> f1.denominator;

    cout << "Enter the integers for fraction 2" << endl;
    cin >> f2.numerator;
    cin >> f2.denominator;

    fraction output = sumFractions(f1, f2);

    cout << "The sum of the fractions is " << output.numerator << "/" << output.denominator << endl;


    return 0;
}

/**
 * Computes the sum of two input params of type fraction.
 *
 * Starts by checking that neither denominator is zero. If either is zero, then
 *   the function throws an error and the program exits. Next, the  numerators
 *   of each fraction are multiplied by the denominator of the opposing fraction
 *   and the denominators are multiplied by each other. This ensures that each
 *   intermediate fraction is of the same denominator. Next the numerators are
 *   added together and f2 is thrown out since we don't need it anymore.
 *   Finally, a for loop is initiated which loops backwards from the value of
 *   the denominator to 2 until both the numerator and the denominator are
 *   divisible by the iterating value. Once that happens, it can be assumed that
 *   is the GCM of the fraction, and the fraction is simplified by that number
 *   and returned.
 * @param  f1 One of the two fractions to be added.
 * @param  f2 The second of the two fractions to be added.
 * @return    A simplified fraction which is the sum of the two input fractions.
 */
fraction sumFractions(fraction f1, fraction f2) {
    f1.numerator *= f2.denominator;
    f2.numerator *= f1.denominator;
    f1.numerator += f2.numerator;
    f1.denominator *= f2.denominator;

    if (f1.denominator == 0 || f2.denominator == 0)
        throw invalid_argument("Neither denominator can be zero.");

    for (int i = f1.denominator; i > 1; i--) {
        if (f1.numerator % i == 0 && f1.denominator % i == 0) {
            f1.numerator /= i;
            f1.denominator /= i;
            break;
        }
    }
    return f1;
}

void test() {
    fraction a = { 15, 28 };
    fraction b = { 38, 38 };

    assert(
        sumFractions(a, b).numerator == 43 &&
        sumFractions(a, b).denominator == 28
    );

    a = {1235, 2445};
    b = {234, 355};
    assert(
        sumFractions(a, b).numerator == 202111 &&
        sumFractions(a, b).denominator == 173595
    );

    cout << "==== Tests Passed ====" << endl;
}
