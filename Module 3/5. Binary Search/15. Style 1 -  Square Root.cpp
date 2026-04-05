// Square Root using eps
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

int main() {
    double x;
    cin >> x;
    double l = 0, r = max(1.0, x);
    while (abs(r - l) > eps) {
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
