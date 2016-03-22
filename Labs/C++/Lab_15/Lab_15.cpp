// Lab 15
// Derek P Sifford
#include <iostream>
using namespace std;

void printArray(int[], int);
int secondSmallestItem(int[], int);

int main() {

    int arr[10]  = {14, 29, 44, 2, 400, 302, 39, 56, 18, 89};
    printArray(arr, 10);
    int secSmallest = secondSmallestItem(arr, 10);

    cout << "The second smallest item is " << secSmallest << endl;

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int secondSmallestItem(int arr[], int size) {
    int firstSmallest = arr[0], secondSmallest = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        }
    }

    return secondSmallest;

}
