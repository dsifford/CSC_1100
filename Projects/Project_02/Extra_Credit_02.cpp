// Project 2, Extra Credit 2
// Derek P Sifford
#include <iostream>
#include <string>
#include <iomanip>
#include <tuple>
#include <fstream>
using namespace std;

// Global variable holding the "quit" state of the program.
bool quit = false;

// Options for various program functions
namespace swimOpts {
    enum toggleOption { SCHEDULE, FREE };
    enum availability { INDIVIDUAL, GROUP };
    enum file { SAVE, LOAD };
}


int mainMenu(char[4][4], char[4][4]);
int printSchedule(char[4][4], string);
int toggleSlot(char[4][4], string, swimOpts::toggleOption);
int printIndGroupAvail(char[4][4], char[4][4], swimOpts::availability);
char inputPrompt();
int saveLoad(char[4][4], char[4][4], swimOpts::file);

int main() {

    char jeff[4][4];
    char anna[4][4];

    // Instantiate both character arrays. Defined before "mainMenu"
    // so it will persist for the life of the program.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            jeff[i][j] = '_';
            anna[i][j] = '_';
        }
    }

    while(!quit) {
        mainMenu(jeff, anna);
    }

    return 0;
}

/**
 * The main interface for this program.
 *
 * This function loops continuously through itself until the user inputs
 * 'q' (the quit selection). Depending on the user's input, the other functions
 * of this program are dispatched accordingly.
 *
 * @param {char[4][4]} jeff  Jeff's schedule array
 * @param {char[4][4]} anna  Anna's schedule array
 * @return {int}  Status code
 */
int mainMenu(char jeff[4][4], char anna[4][4]) {

    char selection = inputPrompt();
    swimOpts::toggleOption toggleOpt;
    swimOpts::availability availOpt;
    swimOpts::file fileOpt;
    int status;

    switch (selection) {
        case 'p':
            printSchedule(jeff, "Jeff");
            printSchedule(anna, "Anna");
            break;
        case 's':
        case 'f':
            int instructor;
            toggleOpt = (selection == 's' ? swimOpts::SCHEDULE : swimOpts::FREE );

            while (true) {
                cout << "Select instructor (1 - Jeff, 2 - Anna): ";
                cin >> instructor;
                if (instructor == 1) {
                    toggleSlot(jeff, "Jeff", toggleOpt);
                    break;
                }
                if (instructor == 2) {
                    toggleSlot(anna, "Anna", toggleOpt);
                    break;
                }
                cout << "Invalid Selection." << endl;
            }

            break;

        case 'i':
        case 'g':
            availOpt = (selection == 'i' ? swimOpts::INDIVIDUAL : swimOpts::GROUP);
            printIndGroupAvail(jeff, anna, availOpt);
            break;
        case 'S':
        case 'L':
            fileOpt = (selection == 'S' ? swimOpts::SAVE : swimOpts::LOAD);
            status = saveLoad(jeff, anna, fileOpt);
            if (status == 1) {
                cout << "The operation failed. Please try again." << endl;
                break;
            }
            cout << "Operation completed successfully." << endl;
            break;
        case 'q':
            quit = true;
    }

    return 0;
}



/**
 * Prints a formatted representation of an individual's current schedule
 * to std out.
 *
 * @param {char[4][4]} arr  2-dimensional array of the individual's schedule
 * @param {string} name  The instructor's name.
 * @return {int} Status code
 */
int printSchedule(char arr[4][4], string name) {

    string timeSlots[4] = {"11-12", "12-1", "1-2", "2-3"};

    cout << name << ":" << endl;
    cout << setw(8) << " \t" << "Mon\t" << "Tue\t" << "Wed\t" << "Thu" << endl;

    for (int i = 0; i < 4; i++) {
        cout << setw(5) << right << timeSlots[i] << "\t";
        for (int j = 0; j < 4; j++) {
            cout << " " << arr[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}



/**
 * Displays a prompt and receives input for dispatching the next action.
 *
 * @return {char}  A character representation of the user's choice
 */
 char inputPrompt() {
    char selection;
    bool badInput = true;

    cout
        << "Enter one of the following commands:\n"
        << " p - Print schedules\n"
        << " s - Schedule a slot\n"
        << " f - Free a slot\n"
        << " i - Show slots available for individual lessons\n"
        << " g - Show slots available for group lessons\n"
        << " S - Save schedules to a file\n"
        << " L - Load schedules from a file\n"
        << " q - Quit\n"
        << "Command: ";

    do {
        cin >> selection;
        switch (selection) {
            case 'p':
            case 's':
            case 'f':
            case 'i':
            case 'g':
            case 'q':
            case 'S':
            case 'L':
                badInput = false;
                break;
            default:
                cout
                    << "You've entered an invalid input, please try again.\n"
                    << "Command: ";
        }
    } while(badInput);

    return selection;
 }

/**
 * Handles scheduling or freeing a single timeslot for a given instructor.
 *
 * This function is similar to "printSchedule", but with a few important differences.
 * - When called, this instantiates an array of tuple<int,int> to hold the row and
 *   column number of available time slots. Additionally, a counter variable is
 *   created to increment at each cell of the 2D array. Also a marker variable is
 *   instantiated to either '_' or 'X' depending on which toggle option is needed.
 * - A for loop is called which loops through the schedule array and prints timeslots
 *   to std out. Depending on the 'option' param, this can go one of two ways...
 *   	- option = SCHEDULE:
 *   		If the timeslot is available (ie, not value 'X'), the current number
 *   	 	of the counter is used as the index of the tuple array and a tuple
 *   	 	is stored in the form of <row, column> for retrieval later. That same
 *   	 	number is shown on the schedule in the position of the timeslot for
 *   	 	the user to choose from.
 *   	- option = FREE:
 *   		If a timeslot is unavailable (ie, not value '_'), the current number
 *   		of the counter is used as the index of the tuple array and a tuple is
 *   		stored in the form of <row, column> for retrieval later. That same
 *   		number is shown on teh schedule in teh position of the timeslot for
 *   		the user to choose from.
 * - Finally, the user is shown a message stating to pick the time slot that they
 *   desire. An endless while loop is created which loops continuously until the user
 *   chooses a timeslot that is not invalid. When that is chosen, the valid timeslot
 *   that the user selected is changed from '_' to 'X' and the function exits.
 *
 * @param {char[4][4]} arr  2D array representing the instructor's schedule.
 * @param {string} name  The instructor's name.
 * @param  {swimOpts::toggleOption} option  Either SCHEDULE or FREE
 * @returns  int  Status code.
 */
int toggleSlot(char arr[4][4], string name, swimOpts::toggleOption option) {

    tuple<int, int> locations[16];
    char marker = option == swimOpts::SCHEDULE ? '_' : 'X';
    int counter = 0;

    string timeSlots[4] = {"11-12", "12-1", "1-2", "2-3"};

    cout << name << ":" << endl;
    cout << setw(8) << " \t" << "Mon\t" << "Tue\t" << "Wed\t" << "Thu" << endl;

    for (int i = 0; i < 4; i++) {
        cout << setw(5) << right << timeSlots[i] << "\t";
        for (int j = 0; j < 4; j++) {

            if (arr[i][j] == marker) {
                locations[counter] = make_tuple(i, j);
                cout << "(" << counter << ")\t";
            }
            else {
                locations[counter] = make_tuple(-1, -1);
                cout << " " << arr[i][j] << " \t";
            }
            counter++;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Choose and enter a number from a timeslot above: ";

    while (true) {
        cin >> counter;
        if (counter < 0 || 15 < counter) {
            cout << "Invalid selection. Please try again." << endl;
            continue;
        };

        int row = get<0>(locations[counter]);
        int col = get<1>(locations[counter]);

        if (row != -1 && col != -1) {
            arr[row][col] = (option == swimOpts::SCHEDULE ? 'X' : '_');
            break;
        }

        cout << "Invalid selection. Please try again." << endl;
    }

    return 0;
}

/**
 * Responsible for printing group or individual availability to std out.
 *
 * This function is very similar to "toggleSlot". It receives both Jeff's and Anna's
 * availabilities as well as swimOpts::availability enum (shape = {INDIVIDUAL, GROUP}).
 * The function loops over Jeff and Anna's schedules simultaneously and, depending on the
 * option param, a character is printed to that slot in std out. The (very small) difference
 * in this param is that if the user wishes to see "INDIVIDUAL" availability, the slot is
 * considered available if Jeff OR Anna has a free slot at that index. Conversely,
 * if the user wishes to see "GROUP" availability, the slot is considered available
 * only if Jeff AND Anna are both available.
 *
 * @param {char[4][4]} jeff  2D array of Jeff's schedule.
 * @param {char[4][4]} anna  2D array of Anna's schedule.
 * @param {swimOpts::availability} option  Either GROUP or INDIVIDUAL.
 * @return {int}  Status code.
 */
int printIndGroupAvail(char jeff[4][4], char anna[4][4], swimOpts::availability option) {

    string timeSlots[4] = {"11-12", "12-1", "1-2", "2-3"};

    cout << setw(8) << " \t" << "Mon\t" << "Tue\t" << "Wed\t" << "Thu" << endl;

    for (int i = 0; i < 4; i++) {
        cout << setw(5) << right << timeSlots[i] << "\t";
        for (int j = 0; j < 4; j++) {

            switch (option) {
                case swimOpts::INDIVIDUAL:
                    if (jeff[i][j] == '_' || anna[i][j] == '_')
                        cout << " " << 'I' << " \t";
                    else
                        cout << " " << '_' << " \t";
                    break;
                case swimOpts::GROUP:
                    if (jeff[i][j] == '_' && anna[i][j] == '_')
                        cout << " " << 'G' << " \t";
                    else
                        cout << " " << '_' << " \t";
                    break;
            }

        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

/**
 * Responsible for saving or loading schedule data from a file.
 *
 * This function first prompts the user to input the filename they are either
 * looking for, or would like to create.
 *
 * Based on the swimOpts::file param, which is an enum whose shape is { SAVE, LOAD },
 * this function works in one of two ways.
 * - option = SAVE:
 * 		An ofstream variable is created with the filename the user specified.
 * 		After instantiating the ofstream object, it is checked to see if it exists
 * 		(ie, that it did not fail). Then both arrays are simply looped through and
 * 		passed over to the file and the file is closed.
 * - option = LOAD
 * 		An ifstream variable is created with the filename specified. After
 * 		instantiating the ifstream object, it is checked to see if it exists
 * 		(ie, that it did not fail to load). Then the file is walked through and
 * 		copied over to the "jeff" and "anna" arrays and the file is closed.
 *
 * @param {char[4][4]} jeff  2D array of Jeff's schedule.
 * @param {char[4][4]} anna  2d array of Anna's schedule.
 * @param {swimOpts::file} option  enum containing either SAVE or LOAD.
 * @return {int}  Status code.
 */
int saveLoad(char jeff[4][4], char anna[4][4], swimOpts::file option) {

    string filename;

    cout << "Enter the filename with extension" << endl;
    cin >> filename;

    if (option == swimOpts::SAVE) {
        ofstream output;
        output.open(filename);

        if (!output.is_open()) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                output << jeff[i][j] << " ";
            }
            output << endl;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                output << anna[i][j] << " ";
            }
            output << endl;
        }

        output.close();

        return 0;
    }

    ifstream input;
    input.open(filename);

    if (!input.is_open()) {
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            input >> jeff[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            input >> anna[i][j];
        }
    }

    input.close();

    return 0;

}
