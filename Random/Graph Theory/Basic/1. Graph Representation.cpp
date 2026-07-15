#include <bits/stdc++.h>

using namespace std;

int main() {
    vector < vector < int > > adjList = {           // for weighted graph replace int with pair < int, int >
        {0, 0, 0},  // ignoring index 0
        {2, 3, 4},
        {1, 3, 4},
        {1, 2, 4},            // Adjacency List
        {1, 2, 3}
    };
    vector < vector < int > > adjMatrix = {
        {0, 0, 0, 0},  // ignoring index 0
        {0, 1, 1, 1},
        {1, 0, 1, 1},        // Adjacency Matrix
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    vector < pair < int, int > > edges = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 1},
        {2, 3},
        {2, 4},
        {3, 1},             // Edge List
        {3, 2},
        {3, 4},
        {4, 1},
        {4, 2},
        {4, 3}
    };
    return 0;
}
