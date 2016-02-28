// Lab 1, Problem 1
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    double studyHours;

    cout << "Write your name" << endl;
    cin >> name;

    cout << "How many hours do you need to study?" << endl;
    cin >> studyHours;

    cout << "Hello, " << name << "! on Saturday, you need to study "
         << studyHours << " hours for the exam." << endl;

    return 0;
}
