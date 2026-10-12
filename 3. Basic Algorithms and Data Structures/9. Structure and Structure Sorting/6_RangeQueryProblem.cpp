#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n)) return 0; // Failsafe for missing input

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

    return 0;
}
