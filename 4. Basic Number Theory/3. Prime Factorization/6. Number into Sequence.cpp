// https://codeforces.com/problemset/problem/1454/D
#include <bits/stdc++.h>
 
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define int long long

bitset < 1000001 > isNP;
vector < int > primes;

void sieve() {
    isNP[1] = 1, isNP[0] = 1;
    for (int i = 4; i <= 1000000; i += 2) {
        isNP[i] = 1;
    }
    for (int i = 3; i * i <= 1000000; i += 2) {
        if (!isNP[i]) {
            for (int j = i * i; j <= 1000000; j += (2 * i)) {
                isNP[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= 1000000; i += 2) {
        if (!isNP[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map < int, int > mp;
    for (auto i: primes) {
        if (i * i > n) {
            break;
        }
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        mp[n]++;
    }
    vector < pair < int, int > > v;
    for (auto x: mp) {
        v.push_back(x);
    }
    sort(v.begin(), v.end(), [](auto x, auto y) {
        return x.second > y.second;
    });
    vector < int > ans(v[0].second, v[0].first);
    for (int i = 1; i < v.size(); i++) {
        while (v[i].second--) {
            ans.back() *= v[i].first;
        }
    }
    cout << ans.size() << endl;
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    FAST_IO;
    sieve();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "#TestCase: " << i << endl << endl;
        solve();
    }
    return 0;
}
