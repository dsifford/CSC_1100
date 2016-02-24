// Lab 5: Problem 1
// Derek P Sifford
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    double mass, density, volume;

    ifstream inFile;
    ofstream outFile;
    inFile.open("inFile.txt");

    inFile >> mass >> density;
    inFile.close();

    outFile.open("outFile.txt");
    volume = mass / density;

    outFile << "Volume: " << showpoint << fixed << setprecision(2) << volume;
    outFile.close();

    return 0;
}
