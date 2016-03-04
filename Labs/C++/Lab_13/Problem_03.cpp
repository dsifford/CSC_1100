// Lab 13 - Problem 3
// Derek P Sifford
#include <iostream>
using namespace std;

void initArr(int arr[]) {
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
}

void initArr(int arr[], bool squared) {
    for (int i = 0; i < 5; i++) {
        arr[i] = i * i;
    }
}

void printArr(int arr[]) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}


int main() {

    int myArr[5];
    int mySqArr[5];

    initArr(myArr);
    initArr(mySqArr, true);

    cout << "Inital Array (Non-squared)" << endl;
    printArr(myArr);
    cout << "Squared Array" << endl;
    printArr(mySqArr);


    return 0;
}
