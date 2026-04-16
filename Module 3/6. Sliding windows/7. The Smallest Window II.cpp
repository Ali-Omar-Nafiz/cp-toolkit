// Problem: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_B
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=8,k=3;
    int a[]={1,2,5,1,3,7,2,4};
    map<int,int>cnt;
    queue<int>q;
    int i=0;
    int ans=INT_MAX;
    while(i<=n){
        if(cnt.size()==k){
            ans=min(ans,(int)q.size());
            int tmp=q.front();
            q.pop();
            if(tmp<=k){
                cnt[tmp]--;
                if(cnt[tmp]==0){
                    cnt.erase(tmp);
                }
            }
        }
        else{
            if(i==n)break;
            q.push(a[i]);
            if(a[i]<=k){
                cnt[a[i]]++;
            }
            i++;
        }
    }
 
}
