#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// 1. INPUT / OUTPUT
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
OUTPUT "Enter a number"
INPUT number
OUTPUT "You entered:", number
*/

void io_example() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << "\n";
}



//////////////////////////////////////////////////////////////
// 2. VARIABLES
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE number
DECLARE text
DECLARE flag
DECLARE list AS ARRAY
*/

void variable_example() {
    int number;
    string text;
    bool flag;
    int list[10];
}



//////////////////////////////////////////////////////////////
// 3. IF / ELSE CONDITION
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
IF number > 0 THEN
    OUTPUT "Positive"
ELSE IF number = 0 THEN
    OUTPUT "Zero"
ELSE
    OUTPUT "Negative"
END IF
*/

void condition_example(int number) {
    if (number > 0) cout << "Positive\n";
    else if (number == 0) cout << "Zero\n";
    else cout << "Negative\n";
}



//////////////////////////////////////////////////////////////
// 4. SWITCH / CASE
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
SWITCH day
    CASE 1: OUTPUT "Sunday"
    CASE 2: OUTPUT "Monday"
    CASE 3: OUTPUT "Tuesday"
    DEFAULT: OUTPUT "Invalid day"
END SWITCH
*/

void switch_example(int day) {
    switch (day) {
        case 1: cout << "Sunday\n"; break;
        case 2: cout << "Monday\n"; break;
        case 3: cout << "Tuesday\n"; break;
        default: cout << "Invalid day\n";
    }
}



//////////////////////////////////////////////////////////////
// 5. LOOPS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE FOR LOOP:
--------------------
FOR i FROM 0 TO n-1
    OUTPUT i
END FOR
*/

void loop_for(int n) {
    for (int i = 0; i < n; i++) cout << i << " ";
    cout << "\n";
}

/*
PSEUDOCODE WHILE LOOP:
----------------------
WHILE count < 10
    OUTPUT count
    INCREMENT count
END WHILE
*/

void loop_while() {
    int count = 0;
    while (count < 10) {
        cout << count << " ";
        count++;
    }
    cout << "\n";
}

/*
PSEUDOCODE DO-WHILE:
--------------------
DO
    OUTPUT value
    INCREMENT value
WHILE value < 5
*/

void loop_do_while() {
    int value = 0;
    do {
        cout << value << " ";
        value++;
    } while (value < 5);
    cout << "\n";
}



//////////////////////////////////////////////////////////////
// 6. ARRAYS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE arr AS ARRAY OF SIZE n
FOR i FROM 0 TO n-1
    INPUT arr[i]
END FOR
*/

void array_example(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
}



//////////////////////////////////////////////////////////////
// 7. 2D ARRAYS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE matrix WITH rows AND columns
FOR r FROM 0 TO rows-1
    FOR c FROM 0 TO columns-1
        INPUT matrix[r][c]
END FOR
*/

void matrix_example(int rows, int cols) {
    vector<vector<int>> m(rows, vector<int>(cols));
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cin >> m[r][c];
}



//////////////////////////////////////////////////////////////
// 8. STRINGS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE name AS TEXT
INPUT name
OUTPUT LENGTH(name)
*/

void string_example() {
    string name;
    cin >> name;
    cout << name.length();
}



//////////////////////////////////////////////////////////////
// 9. FUNCTIONS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
FUNCTION Add(a, b)
    RETURN a + b
END FUNCTION
*/

int Add(int a, int b) {
    return a + b;
}



//////////////////////////////////////////////////////////////
// 10. RECURSION
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
FUNCTION Factorial(n)
    IF n = 0 THEN RETURN 1
    ELSE RETURN n * Factorial(n-1)
END FUNCTION
*/

int Factorial(int n) {
    if (n == 0) return 1;
    return n * Factorial(n - 1);
}



//////////////////////////////////////////////////////////////
// 11. POINTERS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE reference TO number
SET reference TO ADDRESS OF number
OUTPUT VALUE AT reference
*/

void pointer_example() {
    int number = 10;
    int* ref = &number;
    cout << *ref;
}



//////////////////////////////////////////////////////////////
// 12. STRUCTURES
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DEFINE STRUCT Student
    name, age, marks
END STRUCT
*/

struct Student {
    string name;
    int age;
    int marks;
};



//////////////////////////////////////////////////////////////
// 13. CLASSES & OBJECTS
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DEFINE CLASS Animal
    ATTRIBUTE name
    METHOD Speak()
        OUTPUT name + " makes a sound"
END CLASS
*/

class Animal {
public:
    string name;
    void Speak() {
        cout << name << " makes a sound\n";
    }
};



//////////////////////////////////////////////////////////////
// 14. INHERITANCE
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
CLASS Dog EXTENDS Animal
    METHOD Speak()
        OUTPUT "Dog barks"
END CLASS
*/

class Dog : public Animal {
public:
    void Speak() {
        cout << "Dog barks\n";
    }
};



//////////////////////////////////////////////////////////////
// 15. VECTOR (Dynamic Array)
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE list AS DYNAMIC ARRAY
APPEND values
FOR each item IN list
    OUTPUT item
*/

void vector_example() {
    vector<int> list;
    list.push_back(5);
    list.push_back(10);

    for (int x : list) cout << x << " ";
}



//////////////////////////////////////////////////////////////
// 16. MAP / DICTIONARY
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
DECLARE dictionary AS KEY-VALUE STORE
SET values
OUTPUT dictionary["name"]
*/

void map_example() {
    unordered_map<string, int> mp;
    mp["age"] = 18;
    cout << mp["age"];
}



//////////////////////////////////////////////////////////////
// 17. FILE HANDLING
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
OPEN file IN READ MODE
WHILE file HAS MORE DATA
    READ line
    OUTPUT line
END WHILE
CLOSE file
*/

void file_example() {
    ifstream file("input.txt");
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}



//////////////////////////////////////////////////////////////
// 18. EXCEPTION HANDLING
//////////////////////////////////////////////////////////////

/*
PSEUDOCODE:
-----------
TRY
    OPEN file
CATCH ERROR
    OUTPUT "Error!"
END TRY
*/

void exception_example() {
    try {
        ifstream file("unknown.txt");
        if (!file.is_open()) throw runtime_error("Error opening file");
    } 
    catch (exception &e) {
        cout << "Error!\n";
    }
}



//////////////////////////////////////////////////////////////
// MAIN FUNCTION
//////////////////////////////////////////////////////////////

int main() {
    io_example();
    return 0;
}
