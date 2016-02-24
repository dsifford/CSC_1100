// Lab 9 - Problem 1
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;

int main() {

    int sumOfEven = 0, sumOfOdd = 0;
    int nums;

    cout << "Enter a series of integers" << endl;
    cout << "When done, enter any character" << endl;
    for (cin >> nums; nums != 0; cin >> nums) {
        if (nums % 2 == 0) {
            sumOfEven = sumOfEven + nums;
        }
        else {
            sumOfOdd = sumOfOdd + nums;
        }
    }



    cout << "Sum of even numbers = " << sumOfEven << endl;
    cout << "Sum of odd numbers = " << sumOfOdd << endl;

    return 0;
}
