#include <iostream>
using namespace std;

//valid_input checker

int validchecker() {
    int number;
    while (true) {
        cin >> number;

        if (cin.fail()) {
            cout << "  [!] Invalid Input!! Enter Valid Number..";
            cin.clear();
            cin.ignore(1000, '\n');
        } 
        else {
            return number;
        }
    }
}
//reset session
void resetSession(bool & hasResult, float & result) {
    hasResult = false;
    result = 0;
    cout << "\n  [!] Session Terminated & Reset!!" << endl;
}

int main() {

    int input;
    float result = 0;
    bool hasResult = false;
    int FirstNumber, SecondNumber;

    while (true) {

        cout << "\n====================================\n";
        cout << "         BASIC CALCULATOR        \n";
        cout << "====================================\n";
        cout << "  [0]  Reset Session [ANYTIME]\n";
        cout << "  [1]  Addition [+]\n";
        cout << "  [2]  Subtraction [-]\n";
        cout << "  [3]  Multiplication [*]\n";
        cout << "  [4]  Division [/]\n";
        cout << "  [5]  Exit\n";
        cout << "====================================\n\n";

        // First menu validation
        do {
            cout << "  [!] Enter your choice (0-5): ";
            input = validchecker();

            if (input < 0 || input > 5) {
                cout << "  [!] Wrong Input!! Please choose between 0 and 5.\n";
            }

        } while (input < 0 || input > 5);


        if (input == 5) {
            cout << "  [#] Calculator closed. Bye!!" << endl;
            break;
        }

        if (input == 0) {
            resetSession(hasResult, result);
            continue;
        }


        // First Number Input
        if (hasResult) {
            cout << "Using Previous Result: " << result << endl;
            FirstNumber = result;
        }
        else {
            cout << "  [i] Enter First Number: ";
            FirstNumber = validchecker();
        }


        // Second Number Input
        cout << "  [ii] Enter Second Number: ";
        SecondNumber = validchecker();


        // Division by zero check
        if (input == 4 && SecondNumber == 0) {
            cout << "  [!] Error!! Division by zero." << endl;
            continue;
        }


        // Calculation
        switch (input) {

        case 1:
            result = FirstNumber + SecondNumber;
            break;

        case 2:
            result = FirstNumber - SecondNumber;
            break;

        case 3:
            result = FirstNumber * SecondNumber;
            break;

        case 4:
            result = (float)FirstNumber / SecondNumber;
            break;

        default:
            cout << "  [!] Invalid choice!\n";
            continue;
        }


        cout << "\n====================================\n";
        cout << "           CALCULATION DONE        \n";
        cout << "====================================\n";
        cout << "  [iii] Result: " << result << endl;

        hasResult = true;


        // Second menu validation
        int next;

        do {
            cout << "\nNext action:\n";
            cout << "1. Continue with result\n";
            cout << "2. New calculation (reset session)\n";
            cout << "3. Exit\n";
            cout << "  [!] Enter your choice (1-3): ";

            next = validchecker();

            if (next < 1 || next > 3) {
                cout << "  [!] Wrong Input!! Please choose between 1 and 3.\n";
            }

        } while (next < 1 || next > 3);


        if (next == 2) {
            resetSession(hasResult, result);
            continue;
        }
        else if (next == 3) {
            cout << "  [#] Calculator closed. Bye!!" << endl;
            break;
        }

    }

    return 0;
}
