// Lab 13 - Problem 3
// Derek P Sifford
#include <iostream>
using namespace std;

int arr1[5] = {0,1,2,3,4};
int arr2[5] = {4,3,2,1,0};

void arrayAdd(int arr1[], int arr2[]) {
    cout << "\nAdding arrays..." << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] + arr2[i] << endl;
    }
}

void arrayMulti(int arr[], int multiplyBy) {
    cout << "\nMutiplying array by " << multiplyBy << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] * multiplyBy << endl;
    }
}

int main() {

    cout << "Array 1\tArray 2" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << "\t" << arr2[i] << endl;
    }

    arrayAdd(arr1, arr2);
    arrayMulti(arr1, 5);

    return 0;
}
