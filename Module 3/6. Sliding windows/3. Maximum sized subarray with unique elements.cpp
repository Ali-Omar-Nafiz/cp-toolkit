// maximum sized subarray with unique element
// Variable size sliding window
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[]={1,3,1,4,3,2,4,2,5};
    int n=9;
    map<int,int>cnt;
    deque<int>q;
    int ans=0;
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        q.push_back(a[i]);
        while(cnt[a[i]]>1){
            cnt[q.front()]--;
            q.pop_front();
        }
        cout<<a[i]<<" "<<q.size()<<'\n';
        ans=max(ans,(int)q.size());
    }
    cout<<"ans "<<ans<<'\n';
}
