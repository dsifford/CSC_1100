// Exercise 3
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {
    int seconds, mins, hours;

    cout << "Enter elapsed time in seconds" << endl;
    cin >> seconds;

    mins = seconds / 60;
    hours = mins / 60;

    cout << "Time in Hours, Mins, Seconds:" << endl;
    cout << "Hours: " << int(hours) << " Mins: " << int(mins%60) << " Seconds: " << int(seconds%60) << endl;


}
