#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Example 1: Basic Struct Usage
// ==========================================
namespace BasicStruct {

    struct Student {
        string name;
        int age, roll;
        double cgpa;
    };

    void run() {
        Student X;

        cin >> X.name >> X.age >> X.roll >> X.cgpa;

        cout << X.name << ' ' << X.age << ' '
             << X.roll << ' ' << X.cgpa << endl;

        // modify object
        X.age++;
        X.cgpa += 0.1;

        cout << X.name << ' ' << X.age << ' '
             << X.roll << ' ' << X.cgpa << endl;
    }
}

// ==========================================
// Example 2: Array of Structs
// ==========================================
namespace StructArray {

    struct Student {
        string name;
        int age, roll;
        double cgpa;
    };

    void run() {

        Student arr[5];

        for(int i=0;i<5;i++)
            cin>>arr[i].name>>arr[i].age>>arr[i].roll>>arr[i].cgpa;

        for(int i=0;i<5;i++)
            cout<<arr[i].name<<" "
                <<arr[i].age<<" "
                <<arr[i].roll<<" "
                <<arr[i].cgpa<<endl;
    }
}

// ==========================================
// Example 3: Struct with Member Functions
// ==========================================
namespace StructMethods {

    struct Student {

        string name;
        int age, roll;
        double cgpa;

        void input(char c) {
            cin>>name>>age>>roll>>cgpa;
            name += c;
        }

        void showinfo() {
            cout<<name<<" "<<age<<" "
                <<roll<<" "<<cgpa<<endl;
        }
    };

    void run() {

        vector<Student> arr(5);

        for(int i=0;i<5;i++)
            arr[i].input('@');

        for(auto &x : arr)
            x.showinfo();
    }
}

// ==========================================
// Example 4: Sorting Using Comparator
// ==========================================
namespace CustomSortComparator {

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

    void run() {

        vector<Team> v;

        for(int i=0;i<6;i++) {
            Team x;
            x.input();
            v.push_back(x);
        }

        sort(v.begin(),v.end(),cmp);

        for(auto &x:v)
            x.output();
    }
}

// ==========================================
// Example 5: Operator Overloading
// ==========================================
namespace OperatorOverloading {

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

        /*
        =====================================================
        OPERATOR OVERLOADING EXPLANATION

        operator< defines ordering between TWO Team objects.

        this   -> current object
        other  -> object being compared

        STL containers like:
            sort()
            set
            map
            priority_queue

        automatically use operator<.

        Contest ranking rule:
        1) Higher solved is better
        2) Lower penalty is better
        3) Smaller name is better

        We encode ALL ranking logic here.
        =====================================================
        */

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

    void run() {

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
    }
}

// ==========================================
// Example 6: Range Merge + Query
// ==========================================
namespace RangeQueryProblem {

    struct range {

        int l,r;

        bool operator<(const range& other) const {
            return l<other.l;
        }

        bool combine(const range& other) {

            if(r+1<other.l || other.r+1<l)
                return false;

            l=min(l,other.l);
            r=max(r,other.r);
            return true;
        }

        void input() {
            cin>>l>>r;
        }
    };

    void run() {

        int n;
        cin>>n;

        vector<range> v(n);
        for(auto &x:v) x.input();

        sort(v.begin(),v.end());

        vector<range> merged;
        merged.push_back(v[0]);

        for(int i=1;i<n;i++) {
            if(!merged.back().combine(v[i]))
                merged.push_back(v[i]);
        }

        int q;
        cin>>q;

        while(q--) {

            int L,R;
            cin>>L>>R;

            range tmp{L,R};

            auto it=upper_bound(merged.begin(),merged.end(),tmp);

            if(it==merged.begin()) {
                cout<<"NO\n";
                continue;
            }

            --it;

            if(it->l<=L && it->r>=R)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}

// ==========================================
// MAIN
// ==========================================
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Uncomment what you want to test

    // BasicStruct::run();
    // StructArray::run();
    // StructMethods::run();
    // CustomSortComparator::run();
    // OperatorOverloading::run();
    RangeQueryProblem::run();

    return 0;
}
