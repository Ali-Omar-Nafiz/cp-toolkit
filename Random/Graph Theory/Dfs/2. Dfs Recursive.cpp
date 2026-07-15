#include <bits/stdc++.h>

using namespace std;

vector < bool > visited(11, false);
vector < int > order;   // This is preorder

void dfs(vector < vector < int > > &adjList, int u) {
    visited[u] = true;
    order.push_back(u);
    for (auto v: adjList[u]) {
        if (!visited[v]) {
            dfs(adjList, v);
        }
    }
}

int main() {
    vector < vector < int > > adjList = {
        {},             // 0 (unused)
        {2, 3},         // 1
        {1, 4, 5},      // 2
        {1, 6, 7},      // 3
        {2, 8},         // 4
        {2, 6},         // 5
        {3, 5, 9},      // 6
        {3, 9},         // 7
        {4, 10},        // 8
        {6, 7, 10},     // 9
        {8, 9}          // 10
    };
    dfs(adjList, 1);    // source vertex = 1
    for (auto x: order) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
