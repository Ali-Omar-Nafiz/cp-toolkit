#include <bits/stdc++.h>

using namespace std;

vector < bool > visited(11, false);
vector < int > Postorder;   // This is postorder

void dfs(vector < vector < int > > &adjList, int u) {
    visited[u] = true;
    for (auto v: adjList[u]) {
        if (!visited[v]) {
            dfs(adjList, v);
        }
    }
    Postorder.push_back(u);
}

int main() {
    vector<vector<int>> adjList = {    // Directed Acyclic Graph
        {},          // 0 (unused)
        {2, 3},      // 1
        {4, 5},      // 2
        {5, 6},      // 3
        {7},         // 4
        {7, 8},      // 5
        {8},         // 6
        {9},         // 7
        {9, 10},     // 8
        {10},        // 9
        {}           // 10
    };
    dfs(adjList, 1);    // source vertex = 1
    reverse(Postorder.begin(), Postorder.end());   // Reverse Post Order to get Topological Order
    for (auto x: Postorder) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
