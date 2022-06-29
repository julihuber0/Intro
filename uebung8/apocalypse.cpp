#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
int INF = INT32_MAX;

bool bfs(vector<vector<int>> &resMatr, int s, int t, vector<int> &parent) {
    int n = t+1;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && resMatr[v][i] > 0) {
                if (i == t) {
                    parent[i] = v;
                    return true;
                }
                q.push(i);
                parent[i] = v;
                visited[i] = true;
            }
        }
    }
    return false;
}

int maxFlow(vector<vector<int>> &resMatr, int s, int t) {
    vector<int> parent(t+1, -1);
    int max = 0;
    while (bfs(resMatr, s, t, parent)) {
        int path = INF;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path = min(path, resMatr[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            resMatr[u][v] -= path;
            resMatr[v][u] += path;
        }
        max += path;
    }
    return max;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int n, b, m;
        cin >> n >> b >> m;
        vector<vector<int>> rl(n + 1);
        for (int j = 0; j < n + 1; ++j) {
            rl[j].resize(n + 1);
            for (int k = 0; k < n + 1; ++k) {
                rl[j][k] = -1;
            }
        }
        vector<int> bunkers;
        for (int j = 0; j < b; ++j) {
            int bk;
            cin >> bk;
            rl[bk][n] = INF;
            rl[n][bk] = 0;
        }
        for (int j = 0; j < m; ++j) {
            int x, y, w;
            cin >> x >> y >> w;
            rl[x][y] = w;
            rl[y][x] = 0;
        }
        int me = maxFlow(rl, 0, n);
        cout << me << endl;
    }
}
