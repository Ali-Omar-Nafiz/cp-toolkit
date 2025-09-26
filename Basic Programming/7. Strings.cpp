#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------------------
    // 1. C-style string (character array)
    // -------------------------------
    char str1[20] = "Hello"; // fixed size char array
    cout << "C-style string (char array): " << str1 << endl;

    // Taking input (no spaces)
    char name[20];
    cout << "Enter your name (no spaces): ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // -------------------------------
    // 2. C++ string class
    // -------------------------------
    string s1 = "Competitive";
    string s2 = "Programming";
    cout << "\nC++ string example: " << s1 << " " << s2 << endl;

    // Input (no spaces)
    string input1;
    cout << "Enter a word: ";
    cin >> input1;
    cout << "You entered: " << input1 << endl;

    // Input with spaces (use getline)
    string input2;
    cout << "Enter a full line: ";
    cin.ignore(); // to clear leftover newline
    getline(cin, input2);
    cout << "Full line: " << input2 << endl;

    // -------------------------------
    // 3. String operations
    // -------------------------------
    string a = "Hello", b = "World";
    string combined = a + " " + b; // concatenation
    cout << "\nCombined string: " << combined << endl;

    cout << "Length of combined string = " << combined.size() << endl;
    cout << "First char = " << combined[0] << ", Last char = " << combined.back() << endl;

    // Modifying characters
    combined[0] = 'h'; 
    cout << "After modification: " << combined << endl;

    // -------------------------------
    // 4. Useful string functions
    // -------------------------------
    string test = "banana";
    cout << "\nOriginal: " << test << endl;
    sort(test.begin(), test.end());
    cout << "Sorted: " << test << endl;

    reverse(test.begin(), test.end());
    cout << "Reversed: " << test << endl;

    cout << "Substring (0,3) = " << test.substr(0, 3) << endl;

    // -------------------------------
    // 5. Example problem: Count vowels
    // -------------------------------
    string line = "I love programming";
    int vowelCount = 0;
    for (char ch : line) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }
    cout << "\nLine: " << line << endl;
    cout << "Number of vowels = " << vowelCount << endl;

    return 0;
}
