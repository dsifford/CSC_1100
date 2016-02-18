// Lab 9 - Problem 2
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;

int main() {

    int num, counter = 0;

    cout << "Enter an integer" << endl;
    cin >> num;

    do {
        num = num / 10;
        counter++;
    }
    while(num > 0);

    cout << counter;

    return 0;
}
