#include <bits/stdc++.h>
using namespace std;

// using DFS
vector<int>* getPath(int v, int** edges, int v1, int v2, bool* visited) {
    if (v1 == v2) {
        vector<int>* path = new vector<int>;
        path->push_back(v1);
        return path;
    }

    visited[v1] = true;

    for (int i = 0; i < v; i++) {
        if (i == v1) continue;

        if (edges[v1][i] == 1 && !visited[i]) {
            vector<int>* ans = getPath(v, edges, i, v2, visited);
            if (ans != nullptr) {
                ans->push_back(v1);
                return ans;
            }
        }
    }

    return nullptr;
}

vector<int>* getPath(int v, int** edges, int v1, int v2) {
    bool* visited = new bool[v]{0};
    return getPath(v, edges, v1, v2, visited);
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

    vector<int>* path = getPath(v, edges, v1, v2);
    
    if (path == nullptr) return 0;

    for (auto x: *path) {
        cout << x << " ";
    }
}
