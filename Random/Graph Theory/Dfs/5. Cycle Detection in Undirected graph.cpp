#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(11, false);

bool dfs(vector<vector<int>> &adjList, int u, int parent) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            if (dfs(adjList, v, u))
                return true;
        }
        else if (v != parent) {
            return true;    // Cycle detected
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adjList = {
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
    if (dfs(adjList, 1, -1))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
}
