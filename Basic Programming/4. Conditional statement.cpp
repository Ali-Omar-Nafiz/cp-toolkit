#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------------------
    // Relational Operators
    // -------------------------------
    int a = 10, b = 20;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a == b ? " << (a == b) << endl; // false (0)
    cout << "a != b ? " << (a != b) << endl; // true (1)
    cout << "a > b ? " << (a > b) << endl;
    cout << "a < b ? " << (a < b) << endl;
    cout << "a >= b ? " << (a >= b) << endl;
    cout << "a <= b ? " << (a <= b) << endl;

    // -------------------------------
    // If-Else Basics
    // -------------------------------
    int age;
    cout << "\nEnter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << "You are an adult.\n";
    } else {
        cout << "You are not an adult.\n";
    }

    // -------------------------------
    // Else-if chain
    // -------------------------------
    int marks;
    cout << "\nEnter your marks (0-100): ";
    cin >> marks;

    if (marks >= 80) {
        cout << "Grade: A\n";
    } else if (marks >= 60) {
        cout << "Grade: B\n";
    } else if (marks >= 40) {
        cout << "Grade: C\n";
    } else {
        cout << "Grade: F\n";
    }

    // -------------------------------
    // Combining conditions (&& and ||)
    // -------------------------------
    int temp;
    cout << "\nEnter temperature: ";
    cin >> temp;

    if (temp >= 20 && temp <= 30) {
        cout << "The weather is pleasant.\n";
    } else if (temp < 20 || temp > 30) {
        cout << "The weather is not pleasant.\n";
    }

    // -------------------------------
    // NOT operator
    // -------------------------------
    bool isRaining;
    cout << "\nIs it raining? (1 for yes, 0 for no): ";
    cin >> isRaining;

    if (!isRaining) {
        cout << "You don't need an umbrella.\n";
    } else {
        cout << "Take an umbrella with you.\n";
    }

    return 0;
}
