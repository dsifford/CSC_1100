// Project 1, Extra Credit, Problem 1
// Derek P Sifford
#include <iostream>
#include <iomanip>
using namespace std;

void printInfo() {
    char x;
    printf(
        "===== FITNESS CENTER PRICING =====\n"
        "Membership: $10/month\n"
        "Personal Training: $20/session\n\n"
        "Membership Discounts:\n"
        "\t1) Senior Citizens: 30%% discount of monthly rate\n"
        "\t2) Pay year or more in full: 15%% discount of monthly rate\n"
        "Training Discounts:\n"
        "\t1) Buy 5 or more sessions and receive \n\ta 20%% discount on each session\n\n"
    );
    cout << "Press Enter to continue..." << endl;
    cin.get(x);
}

void collectData(double& membershipPrice, double& trainingPrice, int& payMonths, int& trainingSessions) {
    char isSenior, wantsTraining;
    double membershipDiscount = 0;
    bool badInput = true;

    cout << "Are you a senior citizen? (y/n)" << endl;
    while (badInput) {
        cin.get(isSenior);
        if (isSenior == 'y') {
            membershipDiscount += 0.3;
            badInput = false;
            continue;
        }
        if (isSenior == 'n') {
            badInput = false;
            continue;
        }
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        cin.ignore(1);

    }
    badInput = true;

    cout << "Do you want to purchase training? (y/n)" << endl;
    while (badInput) {
        cin.ignore(1);
        cin.get(wantsTraining);
        if (wantsTraining == 'y') {
            cout << "How many training sessions do you want?" << endl;
            cin >> trainingSessions;
            if (trainingSessions > 4) {
                trainingPrice = 16;
            }
            badInput = false;
            continue;
        }
        if (wantsTraining == 'n') {
            badInput = false;
            continue;
        }
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;

    }
    badInput = true;

    cout << "How many membership months are you purchasing today? (Enter a number)" << endl;
    while (badInput) {
        cin >> payMonths;
        if (payMonths > 11) {
            membershipDiscount += 0.15;
            continue;
        }
        if (payMonths < 1) {
            cout << "Please enter a valid number" << endl;
            cin.ignore(1);
            continue;
        }
        badInput = false;
    }

    // Adjust for discounts
    membershipPrice = membershipPrice - (membershipDiscount * membershipPrice);

}

double calculateCost(double membershipPrice, double trainingPrice, int payMonths, int trainingSessions) {
    return (membershipPrice * payMonths) + (trainingPrice * trainingSessions);
}

int main() {

    double cost, trainingPrice = 20, membershipPrice = 10;
    int payMonths = 0, trainingSessions = 0;

    printInfo();
    collectData(membershipPrice, trainingPrice, payMonths, trainingSessions);
    cost = calculateCost(membershipPrice, trainingPrice, payMonths, trainingSessions);

    cout << fixed << showpoint << setprecision(2);
    cout << "\n\n========== TOTAL AMOUNT DUE ==========\n";
    cout << "$" << cost << endl;

    return 0;
}
