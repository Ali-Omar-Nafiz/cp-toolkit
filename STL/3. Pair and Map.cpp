#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---------------------- PAIR ----------------------
    cout << "===== PAIR =====\n";
    // pair: a data type that stores two elements (can be of any type)
    pair<string, int> p;

    // Syntax 1: using initializer list
    p = {"Nafiz", 20};

    // Syntax 2: assigning manually
    // p.first = "Nafiz";
    // p.second = 20;

    cout << "Name: " << p.first << ", Age: " << p.second << "\n\n";

    // Vector of pairs example
    vector<pair<string, int>> v = {
        {"Alice", 23},
        {"Bob", 19},
        {"Charlie", 25},
        {"David", 21},
        {"Alice", 18}
    };

    cout << "Before sorting:\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // Default sorting (non-decreasing)
    // Sorts by .first first; if .first are equal, then by .second
    sort(v.begin(), v.end());

    cout << "\nAfter sort(v.begin(), v.end()):\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // Default sorting (non-increasing)
    // Using reverse iterators rbegin() and rend()
    sort(v.rbegin(), v.rend());

    cout << "\nAfter sort(v.rbegin(), v.rend()):\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";

    // ---------------------- MAP ----------------------
    cout << "\n===== MAP =====\n";
    // map: a key-value pair container
    // Works like an array but can use any type as key
    map<string, string> mp;

    // Two ways to insert values
    mp["Nafiz"] = "Good";  // like mp[index] = value;
    mp.insert({"Alice", "Excellent"});

    // Access value using key (like accessing array index)
    cout << "Nafiz: " << mp["Nafiz"] << "\n";
    cout << "Alice: " << mp["Alice"] << "\n";

    // mp.count(key) -> checks if key exists (returns 1 or 0)
    cout << "\nmp.count(\"Nafiz\") = " << mp.count("Nafiz") << "\n";
    cout << "mp.count(\"Unknown\") = " << mp.count("Unknown") << "\n";

    // mp.clear() -> removes all elements
    mp.clear();

    cout << "\nAfter mp.clear():\n";
    cout << "mp.size() = " << mp.size() << "\n";

    // Even after clear, accessing mp["anything"] gives a default value of that data type
    cout << "mp[\"Test\"] (default after clear) = '" << mp["Test"] << "'\n";
    // For int map, default would be 0
    map<string, int> score;
    cout << "score[\"Rahim\"] (default int) = " << score["Rahim"] << "\n";

    return 0;
}
