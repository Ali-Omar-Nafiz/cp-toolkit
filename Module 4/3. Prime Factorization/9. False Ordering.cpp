// https://lightoj.com/problem/false-ordering
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

vector < int > divCnt(1001);
vector < int > sorted(1001);

void preCompute() {
    for (int i = 1; i < 1001; i++) {
        for (int j = i; j < 1001; j += i) {
            divCnt[j]++;
        }
    }
    for (int i = 1; i <= 1000; i++) {
        sorted[i] = i;
    }
    sort(sorted.begin(), sorted.end(), [](auto &x, auto &y) {
        if (divCnt[x] < divCnt[y]) {
            return true;
        } else if (divCnt[x] == divCnt[y]) {
            if (x > y) {
                return true;
            }
        }
        return false;
    });
}
 
void solve() {
    int n;
    cin >> n;
    cout << sorted[n] << endl;
}

signed main() {
    FAST_IO;
    preCompute();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
