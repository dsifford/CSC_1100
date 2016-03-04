// Lab 13 - Problem 1
// Derek P Sifford
#include <iostream>
using namespace std;

void printArray(int myArr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << myArr[i] << endl;
    }
}

int smallestIndex(int myArr[], int size) {
    int output = 0;
    for (int i = 0; i < size; i++) {
        if (myArr[i] < output) {
            output = myArr[i];
        }
    }
    return output;
}

int main() {

    int myArr[5] = {0,1,2,3,4};
    int smallest;

    printArray(myArr, 5);
    smallest = smallestIndex(myArr, 5);

    cout << "\nThe smallest index of the array is " << smallest << endl;

    return 0;
}
