#include <bits/stdc++.h>
using namespace std;
# define endl "\n"

void print(int **edges, int n, int sv, bool* visited) {  // sv-> starting vertex
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        
        if (edges[sv][i] == 1) {
            if (visited[i]) continue;
            print(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv, bool* visited) {
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;

        for (int i = 0; i < n; i++) {
            if (currentVertex == i) continue;
            
            if (edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n;
    int e;
    cin >> n >> e;
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

    bool* visited = new bool[n]{0};

    cout << "DFS:" << endl;
    print(edges, n, 0, visited);

    for (int i = 0; i < n; i++) visited[i] = false;

    cout << "BFS:" << endl;
    printBFS(edges, n, 0, visited);

    delete [] visited;
    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
}