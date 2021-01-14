#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int RandomIndex(vector<string> TheList, int Number) {
    // Makes seed random
    // Number is used so that all slots have different seeds
    srand(time(0) + Number);
    // % keeps it periodic within the size of the array
    return (rand() % TheList.size());
} 


int main() {
    // Define initial variables
    vector<string> items = {"apple", "banana", "pear"};
    string Slot1;
    string Slot2;
    string Slot3;
    string again = "yes";
    string SpinWheel;

    while (again == "yes") {
        cout << "Type 'yes' to spin the wheel! \n";
        cin >> SpinWheel;
        Slot1 = items[RandomIndex(items, 1)];
        Slot2 = items[RandomIndex(items, 2)];
        Slot3 = items[RandomIndex(items, 3)];
        cout << Slot1 << " " << Slot2 << " " << Slot3 << endl;

        if (Slot1 == Slot2 && Slot1 == Slot3) {
            cout << "Well done, you got all three the same!" << endl;
        } else if (Slot1 == Slot2 || Slot1 == Slot3 || Slot2 == Slot3) {
            cout << "That's good, you got two of the same!" << endl;
        } else {
            cout << "You got none of the same :( -- Try again!" << endl;
        }

        cout << "Would you like to play again? \n(yes/no)" << endl;
        cin >> again;

    }
    return 0;
}
