#include <bits/stdc++.h>
using namespace std;
# define endl "\n"

void DFS(int n, int** edges, bool* visited, vector<int> &v, int sv = 0) {
    visited[sv] = true;
    v.push_back(sv);

    for (int i = 0; i < n; i++) {
        if (i == sv) continue;

        if (edges[sv][i] && !visited[i]) DFS(n, edges, visited, v, i);
    }
}

vector<vector<int>> connectedComponents(int n,int** edges) {
    vector<vector<int>> components;
    bool* visited = new bool[n]{0};
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> v;
            DFS(n, edges, visited, v, i);
            sort(v.begin(), v.end());
            components.push_back(v);
        }
    }

    return components;    
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    if (n == 0) return 0;
    
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

    vector<vector<int>> components = connectedComponents(n, edges);
    for (auto component: components) {
        for (auto v: component) {
            cout << v << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
}