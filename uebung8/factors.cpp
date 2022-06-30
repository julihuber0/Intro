#include <bits/stdc++.h>

using namespace std;

int INF = INT32_MAX;
vector<vector<int>> matrix;

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

    for (int t = 0; t < cases; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int e;
            cin >> e;
            a[i] = e;
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            int e;
            cin >> e;
            b[i] = e;
        }
        vector<vector<int>> list(n + m + 2);
        matrix.clear();
        matrix.resize(n + m + 2, vector<int> (n+m+2, 0));
        int src = n + m;
        int target = n + m + 1;
        for (int i = 0; i < n; ++i) {
            list[src].push_back(i);
            list[i].push_back(src);
            matrix[src][i] = 1;
            for (int j = 0; j < m; ++j) {
                if (b[j] % a[i] == 0) {
                    list[i].push_back(n + j);
                    list[n + j].push_back(i);
                    matrix[i][n + j] = 1;
                }
            }

        }
        for (int i = 0; i < m; ++i) {
            list[n + i].push_back(target);
            list[target].push_back(n + i);
            matrix[n + i][target] = 1;
        }
        int max;
        max = maxFlow(list, matrix, src, target);
        cout << "Case " << t + 1 << ": " << max << "\n";
    }
}

