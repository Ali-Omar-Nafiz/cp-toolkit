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

    Student arr[5];

    for(int i=0;i<5;i++)
        cin>>arr[i].name>>arr[i].age>>arr[i].roll>>arr[i].cgpa;

    for(int i=0;i<5;i++)
        cout<<arr[i].name<<" "
            <<arr[i].age<<" "
            <<arr[i].roll<<" "
            <<arr[i].cgpa<<endl;

    return 0;
}
