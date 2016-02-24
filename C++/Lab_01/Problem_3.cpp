// Lab 1, Problem 3
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;

int main() {

    int hours, mins, seconds, totalSeconds;

    cout << "Please enter the elapsed time in hours, minutes, and seconds\n" << endl;

    cout << "Enter hours\n";
    cin >> hours;

    cout << "Enter minutes\n";
    cin >> mins;

    cout << "Enter seconds\n";
    cin >> seconds;

    totalSeconds = (hours * 60 * 60) + (mins * 60) + seconds;

    cout << "The total time in seconds is " << totalSeconds;

    return 0;
}
