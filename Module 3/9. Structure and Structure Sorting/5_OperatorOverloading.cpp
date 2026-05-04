#include <bits/stdc++.h>
using namespace std;

struct Team {
    string name;
    int solved=0;
    int penalty=0;

    void input() {
        cin>>name>>solved>>penalty;
    }

    void output() const {
        cout<<name<<" "<<solved<<" "<<penalty<<endl;
    }

    bool operator<(const Team& other) const {
        // more solved = higher rank
        if(solved != other.solved)
            return solved > other.solved;

        // lower penalty = higher rank
        if(penalty != other.penalty)
            return penalty < other.penalty;

        // lexicographically smaller name
        return name < other.name;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Team> v;
    set<Team> st; // automatically ordered

    for(int i=0;i<6;i++) {
        Team x;
        x.input();
        v.push_back(x);
        st.insert(x);
    }

    // no comparator needed!
    sort(v.begin(),v.end());

    cout<<"Sorted Vector\n";
    for(auto &x:v)
        x.output();

    cout<<"------\n";

    cout<<"Set Ordering\n";
    for(auto &x:st)
        x.output();

    return 0;
}
