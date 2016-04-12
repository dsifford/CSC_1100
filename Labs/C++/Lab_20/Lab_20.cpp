// Lab 20
// Derek P Sifford
#include <iostream>
#include <string>
using namespace std;


int main() {

    struct fruitType {
        string name;
        string color;
        int calories;
        int sugar;
        int fiber;
        int carbs;
    };

    fruitType x;

    cout << "Input the fruit name: ";
    cin >> x.name;

    cout << "Input the fruit color: ";
    cin >> x.color;

    cout << "Input the fruit calories: ";
    cin >> x.calories;

    cout << "Input the fruit sugar: ";
    cin >> x.sugar;

    cout << "Input the fruit fiber: ";
    cin >> x.fiber;

    cout << "Input the fruit carbs: ";
    cin >> x.carbs;

    cout
        << "Here is the information about the fruit:\n"
        << "Name: " << x.name << endl
        << "Color: " << x.color << endl
        << "Calories: " << x.calories << endl
        << "Sugar: " << x.sugar << endl
        << "Fiber: " << x.fiber << endl
        << "Carbs: " << x.carbs << endl;

    return 0;
}
