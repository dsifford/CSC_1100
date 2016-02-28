// Lab 5: Problem 3
// Derek P Sifford
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream inFile;
    ofstream outFile;

    string fname1, lname1, fname2, lname2, fname3, lname3;
    double currSalary1, currSalary2, currSalary3, newSalary1, newSalary2,
        newSalary3, rate1, rate2, rate3;

    inFile.open("5.2Data.txt");
    inFile >> lname1 >> fname1 >> currSalary1 >> rate1 >> lname2 >> fname2 >>
        currSalary2 >> rate2 >> lname3 >> fname3 >> currSalary3 >> rate3;

    inFile.close();

    newSalary1 = (currSalary1 * (rate1 / 100)) + currSalary1;
    newSalary2 = (currSalary2 * (rate2 / 100)) + currSalary2;
    newSalary3 = (currSalary3 * (rate3 / 100)) + currSalary3;

    outFile.open("outFile.txt");

    outFile << fname1 << " " << lname1 << " " << newSalary1 << endl;
    outFile << fname2 << " " << lname2 << " " << newSalary2 << endl;
    outFile << fname3 << " " << lname3 << " " << newSalary3 << endl;


    return 0;
}
