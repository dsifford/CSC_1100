// Extra Credit 2 - 12/24 Hour time conversion
// Derek P Sifford
#include <iostream>
#include <iomanip>
using namespace std;

void displayChoices();
char getChoice();
void getTime(int&, int&, int&, bool);
void convertTo24(int&, int&);
void convertTo12(int&, int&);
void showResult(int, int, int, bool);

int main() {

    int hours, minutes, amPM;

    displayChoices();
    char choice = getChoice();
    switch (choice) {
        case 'A':
        case 'a':
            getTime(hours, minutes, amPM, false);
            convertTo12(hours, amPM);
            showResult(hours, minutes, amPM, true);
            break;
        case 'B':
        case 'b':
            getTime(hours, minutes, amPM, true);
            convertTo24(hours, amPM);
            showResult(hours, minutes, amPM, false);
            break;
    }

    return 0;
}

void displayChoices() {
    printf(
        "12/24-Hour Time Conversion\n"
        "--------------------------\n"
        "Options:\n"
        "A) Convert 24 hour format to 12 hour format\n"
        "B) Convert 12 hour format to 24 hour format\n"
    );
}

char getChoice() {
    char choice;
    bool wrongChoice = true;

    cout << "Please choose A or B" << endl;
    while (wrongChoice) {
        cin >> choice;
        switch (choice) {
            case 'A':
            case 'a':
            case 'B':
            case 'b':
                wrongChoice = false;
                break;
            default:
                cout << "Please enter a valid choice" << endl;
        }
    }
    return choice;
}

void getTime(int& hours, int& mins, int& amPM, bool is12Hr) {
    if (is12Hr) {
        do {
            cout << "Enter Hours" << endl;
            cin >> hours;
        } while (hours < 0 || 12 < hours);
        do {
            cout << "Enter Minutes" << endl;
            cin >> mins;
        } while (mins < 0 || 59 < mins);
        do {
            cout << "Is the time am or pm? Enter 1 for am, 2 for pm" << endl;
            cin >> amPM;
        } while (amPM < 1 || 2 < amPM);
        return;
    }

    do {
        cout << "Enter Hours" << endl;
        cin >> hours;
    } while (hours < 0 || 23 < hours);
    do {
        cout << "Enter Minutes" << endl;
        cin >> mins;
    } while (mins < 0 || 59 < mins);

}

void convertTo24(int& hours, int& amPM) {
    if (amPM == 1) { return; }
    hours += 12;
}

void convertTo12(int& hours, int& amPM) {
    if (hours < 13) {
        amPM = 1;
        return;
    }

    hours -= 12;
    amPM = 2;
}

void showResult(int hours, int minutes, int amPM, bool is12Hr) {
    cout << setfill('0') << setw(2);
    if (is12Hr) {
        cout << "The time in 12-hour format is: " <<
            hours << ":" << minutes << " " << ((amPM == 1) ? "am" : "pm") << endl;
        return;
    }

    cout << "The time in 24-hour format is: " <<
        hours << ":" << minutes << " hours" << endl;
}
