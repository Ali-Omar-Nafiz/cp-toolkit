#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int age, roll;
    double cgpa;

    void input(char c) {
        cin>>name>>age>>roll>>cgpa;
        name += c;
    }

    void showinfo() {
        cout<<name<<" "<<age<<" "<<roll<<" "<<cgpa<<endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> arr(5);

    for(int i=0;i<5;i++)
        arr[i].input('@');

    for(auto &x : arr)
        x.showinfo();

    return 0;
}
