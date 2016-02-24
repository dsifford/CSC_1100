// Exercise 1
// Derek P Sifford
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    int age;
    char delim;
    string name;

    cout << "Enter your age" << endl;;
    cin >> age;

    cout << "Enter a delimiter" << endl;
    cin.ignore(8,'\n');
    cin.get(delim);

    cout << "Enter your name" << endl;
    cin.ignore(8, '\n');
    getline(cin, name);

    cout << "Name: " << name << endl;
    cout << "Delim: " << delim << endl;
    cout << "Age: " << age << endl;

    return 0;
}
