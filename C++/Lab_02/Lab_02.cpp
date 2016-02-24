// Lab 3 - I/O
// Derek P Sifford
#include <iostream>
using namespace std;

int main() {

    int a;

    cout << "Input an integer value..." << endl;
    cin >> a;

    cout << "Result:\nThe value of a is: " << a << endl;
    cout << "............................" << endl;
    cout << "The value of ++a is: " << ++a << endl;
    cout << "Now the value of a is: " << a << endl;


    cout << "\nThe value of a++ is: " << a++ << endl;
    cout << "Now the value of a is: " << a << endl;

    cout << "\nThe value of --a is: " << --a << endl;
    cout << "Now the value of a is: " << a << endl;

    cout << "\nThe value of a-- is: " << a-- << endl;
    cout << "Now the value of a is: " << a << endl;

    return 0;
}
