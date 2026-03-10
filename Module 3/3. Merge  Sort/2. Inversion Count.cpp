#include <bits/stdc++.h>
using namespace std;

/*
Inversion Count:
-----------
Defination:
input: l, r --> range to count inversion, v --> count from this vector.
output: total inversion
*/

int inversionCnt(int l, int r, vector < int > &v) {
    if ((r - l + 1) <= 1) {
        return 0;
    }
    int mid = (l + r) / 2;
    int cnt1 = inversionCnt(l, mid, v);
    int cnt2 = inversionCnt(mid + 1, r, v);
    int cnt = cnt1 + cnt2;
    int h1 = l, h2 = mid + 1;
    vector < int > nV((r - l + 1));
    for (int i = 0; i < nV.size(); i++) {
        if (h1 > mid) {
            nV[i] = v[h2];
            h2++;
        } else if (h2 > r) {
            nV[i] = v[h1];
            h1++;
        } else {
            if (v[h1] <= v[h2]) {
                nV[i] = v[h1];
                h1++;
            } else {
                nV[i] = v[h2];
                h2++;
                cnt += (mid - h1 + 1);
            }
        }
    }
    for (int i = 0; i < nV.size(); i++) {
        v[l + i] = nV[i];
    } 
    return cnt;
}

int inversionCnt2(int l, int r, vector < int > &v) {
    if ((r - l + 1) <= 1) {
        return 0;
    }
    int mid = (l + r) / 2;
    int cnt1 = inversionCnt2(l, mid, v);
    int cnt2 = inversionCnt2(mid + 1, r, v);
    int cnt = cnt1 + cnt2;
    sort(v.begin() + l, v.begin() + mid + 1);
    for (int i = mid + 1; i <= r; i++) {
        int idx = upper_bound(v.begin() + l, v.begin() + mid + 1, v[i]) - v.begin();
        cnt += (mid - idx + 1);
    }
    sort(v.begin() + l, v.begin() + r + 1);
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector < int > v, tmp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    tmp = v;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    ans = inversionCnt(0, n - 1, v);
    cout << ans << endl;
    ans = inversionCnt2(0, n - 1, tmp);
    cout << ans << endl;
    return 0;
}


