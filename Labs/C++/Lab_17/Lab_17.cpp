// Lab 17
// Derek P Sifford
#include <iostream>
using namespace std;


int main() {

    char input[15];

    cout << "Enter a string ending with *" << endl;

    int counter = 0;
    for (int i = 0; i < 15; i++) {
        cin >> input[i];
        if (int(input[i]) == 42) {
            counter += i - 1;
            break;
        }
    }

    char arr1[counter];
    char arr2[counter];

    for (int i = 0; i <= counter; i++) {
        arr1[i] = input[i];
    }

    for (int i = counter; i >= 0; i--) {
        arr2[counter - i] = input[i];
    }

    bool isPal = true;
    for (int i = 0; i <= counter; i++) {
        if (arr1[i] != arr2[i]) {
            isPal = false;
            break;
        }
    }

    if (isPal) {
        cout << "The string is a palandrome" << endl;
    } else {
        cout << "The string is not a palandrome" << endl;
    }


    cout << input << endl;



    return 0;
}
