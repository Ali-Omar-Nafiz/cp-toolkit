vector<int> v = {5, 1, 3, 9, 2};

sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});

for (int x : v) cout << x << " ";
// Output: 9 5 3 2 1
