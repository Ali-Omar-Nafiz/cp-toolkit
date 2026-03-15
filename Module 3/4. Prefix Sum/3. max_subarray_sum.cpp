// Maximum sub-array sum using prefix sum
 
#include<bits/stdc++.h>
using namespace std;
 
int ar[101], pre[101];
 
int main() {
    int n;
    cin >> n;
 
    for(int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }
 
    int ans = 0, mn = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, pre[i] - mn);
        mn = min(mn, pre[i]);
    }
 
    cout << ans << "\n";
}
