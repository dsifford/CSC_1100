// Project 1, Problem 2 - GPA cluster and average
// Derek P Sifford
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void openFiles(ifstream& in, ofstream& out) {

    // Receive the ponters to the fstream vars and open
    // the files for I/O
    in.open("project01_Part02Data.txt");
    out.open("output.txt");

    // Format the output for the output file
    out << fixed << showpoint << setprecision(2);
}

void initialize(double& var) {
    // Completely pointless function that initializes
    // the variable of type double it receives to 0
    var = 0;
}

double sumGrades(char gender, ifstream& file) {

    // Instantiate helper variables
    double GPA, GPAsum = 0;
    char testGender;

    // While the file is available for reading, read the
    // gender character to testGender and the GPA to GPA
    // If testGender doesn't match the gender we're looking
    // for, then move on. Otherwise, add the GPA to GPAsum
    while (file >> testGender >> GPA) {
        if (testGender != gender) {
            continue;
        }
        GPAsum += GPA;
    }
    // Reset the ifstream back to the top of the file
    file.clear();
    file.seekg(0, ios::beg);

    // Return the sum
    return GPAsum;
}

double averageGrade(double sum, char gender, ifstream& file) {

    // Instantiate helper variables
    double avg, count = 0;
    char testGender;

    // While the file is available for reading, take in the
    // gender from each line to 'testGender'. If testGender
    // matches the gender we care about, increment the counter.
    // Finally, ignore the rest of the line.
    while (file >> testGender) {
        if (testGender == gender) {
            count++;
        }
        file.ignore(50, '\n');
    }

    // Reset the readable file back to its initial state so we
    // can read it again later
    file.clear();
    file.seekg(0, ios::beg);

    // Compute and return the average
    avg = sum / count;
    return avg;

}

void printResults(ofstream& file, double avgMale, double avgFemale) {
    // Print the results to the output file
    file << "The average grade for males is " << avgMale << endl;
    file << "The average grade for females is " << avgFemale << endl;
}

int main() {

    ifstream infile;
    ofstream outfile;
    double countFemale, countMale, sumFemaleGPA, sumMaleGPA,
        avgMaleGPA, avgFemaleGPA;
    openFiles(infile, outfile);

    initialize(countFemale);
    initialize(countMale);
    initialize(sumFemaleGPA);
    initialize(sumMaleGPA);

    sumMaleGPA = sumGrades('m', infile);
    sumFemaleGPA = sumGrades('f', infile);

    avgMaleGPA = averageGrade(sumMaleGPA, 'm', infile);
    avgFemaleGPA = averageGrade(sumFemaleGPA, 'f', infile);

    printResults(outfile, avgMaleGPA, avgFemaleGPA);

    return 0;
}
