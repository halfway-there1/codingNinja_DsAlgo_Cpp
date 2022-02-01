#include <bits/stdc++.h>
using namespace std;
# define endl "\n"


void printBFS(int n, int **edges, int sv, bool* visited) {
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";

        for (int i = 0; i < n; i++) {
            if (currentVertex == i) continue;
            
            if (edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFSTraversal(int n, int **edges) {
    bool* visited = new bool[n]{0};
    for (int i = 0; i < n; i++) {
        if (!visited[i]) printBFS(n, edges, i, visited);
    }
}

int main() {
    int n;
    int e;
    cin >> n >> e;    // taking no of vertices and no of edges

    if (n == 0) return 0;

    // declaring the adjacency matrix (it's a square matrix)
    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n]{0};
    }
    // initializing the above declared adjacency matrix
    for (int i = 0; i < e; i++) {
        int f, s;  // edge from 'f' to 's' or vice-versa
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    BFSTraversal(n, edges);   // can handle both connected and disconnected graphs

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
}