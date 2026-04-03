// Problem: https://codeforces.com/contest/779/problem/D

#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main()
{
    string s,tar; cin>>s>>tar;
    int n = s.size();
    vector<int>vct(n); for(auto &i:vct) cin>>i;
    for(auto &i:vct) --i;
    int L = 0, R = n;
    int ans = 0;
    while(L<=R)
    {
        int mid = L + (R-L)/2;
        //mid porjonto letter remove korle still tar pawa possible kina
        vector<int>removed(n,0);
        for(int i=0; i<mid; ++i)
        {
            removed[vct[i]] = 1;
        }

        int idx = 0;

        for(int i=0; i<n; ++i)
        {
            if(removed[i] == 1) continue;
            else if(s[i]==tar[idx])
            {
                idx++;

                if(idx == (int)tar.size()) break;
            }
            else continue;
        }

        if(idx == (int)tar.size()) //still possible
        {
            ans = mid;
            L = mid+1;
        }
        else R = mid-1;

    }

    cout<<ans<<'\n';
}
