// Lab 14
// Derek P Sifford
#include <iostream>
using namespace std;

void change(int value, int &hundreds, int &fifties, int &twenties,
                int &tens, int &fives, int &ones) {

    if (value > 100) {
        hundreds = value / 100;
        value = value % 100;
    }

    if (value > 50) {
        fifties = value / 50;
        value = value % 50;
    }

    if (value > 20) {
        twenties = value / 20;
        value = value % 20;
    }

    if (value > 10) {
        tens = value / 10;
        value = value % 10;
    }

    if (value > 5) {
        fives = value / 5;
        value = value % 5;
    }

    if (value > 1) {
        ones = value / 1;
        value = value % 1;
    }

}


int main() {

    int value, hundreds = 0, fifties = 0, twenties = 0, tens = 0, fives = 0, ones = 0;

    cout << "Enter an integer value" << endl;
    cin >> value;

    change(value, hundreds, fifties, twenties, tens, fives, ones);

    printf(
        "Your change is:\n"
        "%d hundreds\n"
        "%d fifties\n"
        "%d twenties\n"
        "%d tens\n"
        "%d fives\n"
        "%d ones\n",
        hundreds, fifties, twenties, tens, fives, ones
    );
}
