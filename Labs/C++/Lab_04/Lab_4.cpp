// Lab 4 - File I/O
// Derek P Sifford
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    ifstream inFile;
    ofstream outFile;

    const double PI = 3.1416;
    double length, width, radius, rate, area1, area2, perimeter, circumference, balance, balance2;
    string firstName, lastName;
    int age;

    inFile.open("inData.txt");
    inFile >> length >> width >> radius >> firstName >> lastName >> age >> balance >> rate;
    inFile.close();

    area1 = length * width;
    area2 = PI * radius * radius;
    circumference = 2 * PI * radius;
    perimeter = (length * 2) + (width * 2);
    balance2 = balance * (1 + 0.035 * 0.083333);

    outFile.open("outData.txt");
    outFile << "Rectangle:\n";
    outFile << "Length: = " << length << ", width = " << width << ", area = "
        << fixed << setprecision(2) <<
        area1 << ", perimeter = " << perimeter << "\n\nCircle:\n";

    outFile << "Radius: " << radius << ", area = " << area2 << ", circumference = " << circumference << "\n";

    outFile << "Name: " << firstName << " " << lastName << ", age: " << age << "\n" <<
        "Beginning balance = " << "$" << balance << ", interest rate = " << rate << "\n" <<
        "Balance at the end of the month = " << "$" << balance2;


    return 0;
}
