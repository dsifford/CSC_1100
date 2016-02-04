// Lab 5: Problem 2
// Derek P Sifford
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    double boxPrice, boxSales, sidelinePrice, sidelineSales, premiumPrice,
        premiumSales, generalPrice, generalSales, boxSold, sidelineSold,
        premiumSold, generalSold, totalSales, totalSold;

    ifstream inFile;
    ofstream outFile;

    inFile.open("inFile.txt");

    inFile >> boxPrice >> boxSold >> sidelinePrice >> sidelineSold >>
        premiumPrice >> premiumSold >> generalPrice >> generalSold;

    inFile.close();

    boxSales = boxSold * boxPrice;
    sidelineSales = sidelineSold * sidelinePrice;
    premiumSales = premiumSold * premiumPrice;
    generalSales = generalSold * generalPrice;

    outFile.open("outFile.txt");

    totalSold = boxSold + sidelineSold + premiumSold + generalSold;
    totalSales = boxSales + sidelineSales + premiumSales + generalSales;

    outFile << fixed << showpoint << setprecision(2);

    outFile << "Number of tickets sold: " << totalSold << endl;
    outFile << "Total revenue in sales: $" << totalSales << endl;

    outFile.close();



    return 0;
}
