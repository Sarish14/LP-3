//============================================================================
// Name        : LP3_Assignment-01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &fib) {
    cout << "Fibonacci Sequence is: ";
    for (int term : fib)
        cout << term << " ";
    cout << endl;
}

void nonrecur(int n) {
    if (n <= 0) {
        cout << "Enter the number of terms as a positive number" << endl;
        return;
    }

    vector<int> fib(n);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    display(fib);
}

int fibo(int n) {
    if (n <= 1)
        return n;

    return fibo(n - 1) + fibo(n - 2);
}

void recur(int n) {
    if (n <= 0) {
        cout << "Enter the number of terms as a positive number" << endl;
        return;
    }

    vector<int> fib(n);
    for (int i = 0; i < n; i++) {
        fib[i] = fibo(i);
    }

    display(fib);
}

int main() {
    int option;
    int n;
    string input;

    do {
        cout << " ---------------------- MENU ---------------------- " << endl;
        cout << " 1. Fibonacci Sequence Non-Recursive" << endl;
        cout << " 2. Fibonacci Sequence Recursive" << endl;
        cout << " 3. Exit" << endl;
        cout << "Enter the option : ";
        while (true) {
            if ((!(cin >> option)) || (option < 1 || option > 3))                         // !(cin >> option) if input is not an integer
            {
                cout << "Invalid option. Please enter a valid option (1-3): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }

        if (option != 3) {
            cout << "Enter the number of terms to be present in fibo numbers : ";
            while (true) {
                if (!(cin >> n) || n <= 0) {
                    cout << "Invalid input. Please enter a positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }
        }

        switch (option) {
            case 1:
                nonrecur(n);
                break;

            case 2:
                recur(n);
                break;

            case 3:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid Option" << endl;
                break;
        }
    } while (true);

    return 0;
}



/*
    Iterative Approach :
        Time Complexity :- O(N)
        Space Complexity :- O(1)
    Recursive Approach :
        Time Complexity :- O(2^N) --> Exponential Since on function makes recursive call to two more functions
        Space Complexity :- O(N) --> Max depth of recursion tree is N
*/
