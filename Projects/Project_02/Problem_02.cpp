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

/**
 * Responsible for collecting the names and values of the workers from the input
 * file.
 *
 * The function simply opens a readable stream from the inputfile and parses the
 * data into two arrays, one containing the names of the workers, the other containing
 * the values. After the data is read, the file is closed and the function exits.
 *
 * @param {string[10]} names A string array of length 10 to store the names.
 * @param {double[10][3]} values A double 2D array to store values.
 * @return {void}
 */
void readData(string names[10], double values[10][3]) {

    ifstream data;
    data.open("Problem_2_Data.txt");

    for (int i = 0; i < 10; i++) {
        data >> names[i];
        data >> values[i][0];
        data >> values[i][1];
    }

    data.close();

}

/**
 * Responsible for populating the final row of the values array (each workers' pay)
 *
 * The function begins by instantiating 2 int variables (hours, OThours) and 2 double
 * variables (rate, pay). Each row of the values array is then iterated and the pay is
 * calculated using simple arithmetic. Once calculated, the value is stored in column 2
 * of the i'th row of the values array.
 *
 * @param {double[10][3]} values  The values array.
 * @return {void}
 */
void determinePay(double values[10][3]) {
    int hours, OThours;
    double rate, pay;

    for (int i = 0; i < 10; i++) {
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

/**
 * Simple helper function which calculates the average of all the pay in the dataset.
 *
 * @param {double[10][3]} values  The values array.
 * @return {double}  The calculated average.
 */
double getAverage(double values[10][3]) {

    double sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += values[i][2];
    }

    return sum / 10;
}

/**
 * Responsible for printing a tabular representation of the data to std out.
 *
 * @param {string[10]} names  The names array.
 * @param {double[10][3]} values  The values array.
 * @return {void}
 */
void outputRowData(string names[10], double values[10][3]) {


    cout << "Name\t" <<  "Hrs Worked\t" << "Pay Rate\t" << setw(8) << "Salary\t" << endl;

    cout << fixed << showpoint << setprecision(2);
    for (int i = 0; i < 10; i++) {
        cout<< names[i] << "\t"
            << setw(10) << right << values[i][0] << "\t"
            << setw(8) << values[i][1] << "\t"
            << setw(7) << right << values[i][2] << endl;
    }
    cout << endl;

}

/**
 * Responsible for printing the names of the workers whose salaries are greater
 * than or equal to the average salary
 *
 * @param {double[10][3]} values  The values array.
 * @param {string[10]} names  The names array.
 * @param {double} avg  The average salaray.
 * @return {void}
 */
void outputWorkaholics(double values[10][3], string names[10], double avg) {
    cout << "Employees whos salaries are greater than or equal to the average salary." << endl;

    for (int i = 0; i < 10; i++) {
        if (values[i][2] >= avg)
            cout << names[i] << " ";
    }
    cout << endl;
}
