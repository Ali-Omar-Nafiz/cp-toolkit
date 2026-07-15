#include <bits/stdc++.h>

using namespace std;

vector < bool > visited(11, false);
vector < bool > recStack(11, false);

bool dfs(vector<vector<int>> &adjList, int u) {
    visited[u] = true;
    recStack[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            if (dfs(adjList, v))
                return true;
        }
        else if (recStack[v]) {
            return true;
        }
    }
    recStack[u] = false;
    return false;
}

int main() {
    vector<vector<int>> adjList = {    // Directed graph
        {},          // 0 (unused)
        {2, 3},      // 1 → 2, 3
        {4},         // 2 → 4
        {4, 5},      // 3 → 4, 5
        {6},         // 4 → 6
        {6},         // 5 → 6
        {7},         // 6 → 7
        {3, 8},      // 7 → 3, 8
        {9},         // 8 → 9
        {10},        // 9 → 10
        {}           // 10
    };
    if (dfs(adjList, 1)) {
        cout << "Cyclef Found in the directed Graph." << endl;
    }
    return 0;
}
