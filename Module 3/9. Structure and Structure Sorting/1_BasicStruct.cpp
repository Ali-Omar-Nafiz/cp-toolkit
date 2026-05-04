#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int age, roll;
    double cgpa;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Student X;
    cin >> X.name >> X.age >> X.roll >> X.cgpa;

    cout << X.name << ' ' << X.age << ' '
         << X.roll << ' ' << X.cgpa << endl;

    // modify object
    X.age++;
    X.cgpa += 0.1;

    cout << X.name << ' ' << X.age << ' '
         << X.roll << ' ' << X.cgpa << endl;

    return 0;
}
