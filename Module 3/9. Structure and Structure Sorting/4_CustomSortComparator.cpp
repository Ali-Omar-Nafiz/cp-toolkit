#include <bits/stdc++.h>
using namespace std;

struct Team {
    string name;
    int solved=0;
    int penalty=0;

    void input() {
        cin>>name>>solved>>penalty;
    }

    void output() {
        cout<<name<<" "<<solved<<" "<<penalty<<endl;
    }
};

// external comparator
bool cmp(Team a, Team b) {
    if(a.solved!=b.solved)
        return a.solved>b.solved;
    if(a.penalty!=b.penalty)
        return a.penalty<b.penalty;
    return a.name<b.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Team> v;

    for(int i=0;i<6;i++) {
        Team x;
        x.input();
        v.push_back(x);
    }

    sort(v.begin(),v.end(),cmp);

    for(auto &x:v)
        x.output();

    return 0;
}
