#include <bits/stdc++.h>
using namespace std;
# define endl "\n"

void DFS(int n, int** edges, bool* visited, int sv = 0) {
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (i == sv) continue;

        if (edges[sv][i] && !visited[i]) DFS(n, edges, visited, i);
    }
}

bool isConnected(int n,int** edges) {
    bool* visited = new bool[n]{0};
    DFS(n, edges, visited);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    if (n == 0) {
        cout << "true";
        return 0;
    }
    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n]{0};
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << ((isConnected(n, edges)) ? "true" : "false");

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
}