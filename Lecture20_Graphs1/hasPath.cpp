#include <bits/stdc++.h>
using namespace std;

// using BFS
bool hasPath(int v, int** edges, int v1, int v2, bool* visited) {
    if (edges[v1][v2]) return true;

    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1] = true;

    while (!pendingVertices.empty()) {
        int currVertex = pendingVertices.front();
        if (currVertex == v2) return true;
        pendingVertices.pop();

        for (int i = 0; i < v; i++) {
            if (i == currVertex) continue;

            if (edges[currVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}



// using DFS
/* bool hasPath(int v, int** edges, int v1, int v2, bool* visited) {
    if (edges[v1][v2]) return true;

    visited[v1] = true;

    for (int i = 0; i < v; i++) {
        if (i == v1) continue;

        if (edges[v1][i] == 1 && !visited[i]) {
            bool ans = hasPath(v, edges, i, v2, visited);
            if (ans == true) return true;
        }
    }

    return false;
} */

bool hasPath(int v, int** edges, int v1, int v2) {
    if (v < 2) return false;
    bool* visited = new bool[v]{0};
    return hasPath(v, edges, v1, v2, visited);
}

int main() {
    int v, e;
    cin >> v >> e;

    int** edges = new int*[v];
    for (int i=0; i<v; i++) {
        edges[i] = new int[v]{0};
    }

    for (int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;
    
    cout << (hasPath(v, edges, v1, v2) ? "true" : "false");
    
    return 0;
}