// Project 2 - Problem 2
// Derek P Sifford
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void readData(string[10], double[10][3]);
void determinePay(double[10][3]);
double getAverage(double[10][3]);
void outputRowData(string[10], double[10][3]);
void outputWorkaholics(double[10][3], string[10], double);

int main() {

    string names[10];
    double values[10][3], average;

    readData(names, values);
    determinePay(values);
    average = getAverage(values);

    outputRowData(names, values);
    cout << "Average Salary: $" << average << "\n\n";
    outputWorkaholics(values, names, average);

    return 0;
}


void readData(string names[10], double values[10][3]) {

    ifstream data;
    data.open("Problem_2_Data.txt");

    for (int i = 0; i < 10; i++) {
        data >> names[i];
        data >> values[i][0];
        data >> values[i][1];
    }

}

void determinePay(double values[10][3]) {
    int hours, OThours;
    double rate, pay;

    for (size_t i = 0; i < 10; i++) {
        hours = values[i][0];
        rate = values[i][1];

        OThours = hours - 40;

        if (OThours > 0) {
            pay = (rate * 40) + (((rate * 0.5) + rate) * OThours);
        }
        else {
            pay = rate * hours;
        }

        values[i][2] = pay;

    }
}

double getAverage(double values[10][3]) {

    double sum = 0;

    for (size_t i = 0; i < 10; i++) {
        sum += values[i][2];
    }

    return sum / 10;
}

void outputRowData(string names[10], double values[10][3]) {


    cout << "Name\t" <<  "Hrs Worked\t" << "Pay Rate\t" << setw(8) << "Salary\t" << endl;

    cout << fixed << showpoint << setprecision(2);
    for (size_t i = 0; i < 10; i++) {
        cout<< names[i] << "\t"
            << setw(10) << right << values[i][0] << "\t"
            << setw(8) << values[i][1] << "\t"
            << setw(7) << right << values[i][2] << endl;
    }
    cout << endl;

}

void outputWorkaholics(double values[10][3], string names[10], double avg) {
    cout << "Employees whos salaries are greater than or equal to the average salary." << endl;

    for (size_t i = 0; i < 10; i++) {
        if (values[i][2] >= avg)
            cout << names[i] << " ";
    }
    cout << endl;
}
