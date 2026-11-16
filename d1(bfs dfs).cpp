#include <iostream>
#include <queue>
using namespace std;

int g[10][10], vis[10], n;

void DFS(int v) {
    vis[v] = 1;
    cout << v << " ";
    for (int i = 0; i < n; i++)
        if (g[v][i] && !vis[i]) DFS(i);
}

void BFS(int start) {
    fill(vis, vis + n, 0);
    queue<int> q;
    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (g[v][i] && !vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int e, u, v, start;
    cout << "Enter number of vertices: "; cin >> n;
    cout << "Enter number of edges: "; cin >> e;

    while (e--) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g[u][v] = 1;
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << g[i][j] << " ";
        cout << endl;
    }

    cout << "\nEnter starting vertex: "; cin >> start;

    cout << "DFS: "; DFS(start);
    cout << "\nBFS: "; BFS(start);
    cout << endl;
}