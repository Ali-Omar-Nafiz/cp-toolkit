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
    vector<vector<int>> adjList = {
        {},
        {2},        // 1
        {1, 3},     // 2
        {2},        // 3

        {5},        // 4
        {4},        // 5

        {7},        // 6
        {6},        // 7

        {},         // 8

        {10},       // 9
        {9}         // 10
    };
    
    vector < int > connected_components;
    for (int i = 1; i <= 10; i++) {
        if (!visited[i]) {
            connected_components.push_back(i);
            dfs(adjList, i);
        }
    }
    for (auto x: connected_components) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
