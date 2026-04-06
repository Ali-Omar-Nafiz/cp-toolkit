// Square Root selecting total steps (Better approach)
#include <bits/stdc++.h>

using namespace std;

int main() {
    double x;
    cin >> x;
    double l = 0, r = max(1.0, x);
    for (int step = 1; step < 50; step++) {
        double mid = (r + l) / 2.0;
        if (mid * mid < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    double ans = (l + r) / 2.0;

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
