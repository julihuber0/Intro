#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
int INF = INT32_MAX;

bool bfs(vector<vector<int>> &list, vector<vector<int>> &mat, int s, int t, vector<int> &parent) {
    int n = t + 1;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w: list[v]) {
            if (!visited[w] && mat[v][w] > 0) {
                if (w == t) {
                    parent[w] = v;
                    return true;
                }
                q.push(w);
                parent[w] = v;
                visited[w] = true;
            }
        }
    }
    return false;
}

int maxFlow(vector<vector<int>> &resList, vector<vector<int>> &resMat, int s, int t) {
    vector<int> parent(t + 1);
    int max = 0;
    while (bfs(resList, resMat, s, t, parent)) {
        int path = INF;
        for (int v = t; v != s; v = parent[v]) {
            path = min(path, resMat[parent[v]][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            resMat[u][v] -= path;
            resMat[v][u] += path;
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
        vector<vector<int>> rm(n+1);
        for(int j = 0; j<n+1; ++j) {
            rm[j].resize(n+1, 0);
        }
        vector<int> bunkers;
        for (int j = 0; j < b; ++j) {
            int bk;
            cin >> bk;
            rl[bk].push_back(n);
            rl[n].push_back(bk);
            rm[bk][n] = INF;
            rm[n][bk] = 0;
        }
        for (int j = 0; j < m; ++j) {
            int x, y, w;
            cin >> x >> y >> w;
            rl[x].push_back(y);
            rl[y].push_back(x);
            rm[x][y] += w;
            //rm[y][x] = 0;
        }
        int me = maxFlow(rl, rm, 0, n);
        cout << me << endl;
    }
}

