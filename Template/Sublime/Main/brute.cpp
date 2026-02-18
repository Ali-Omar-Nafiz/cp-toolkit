#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
	return uniform_int_distribution<int>(l, r) (rng);
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << (x + y) << endl;
	return 0;
}