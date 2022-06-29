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

    for(int t = 0; t<cases; ++t) {
        int n, e, x, p;
        cin >> n >> e >> x >> p;
        vector<vector<int>> rList(2*n+2);
        vector<vector<int>> rMatrix(2*n+2, vector<int> (2*n+2, 0));
        for(int i = 0; i<n; ++i) {
            rList[i].push_back(i+n);
            //rList[i+n].push_back(i);
            rMatrix[i][i+n] = 1;
            //rMatrix[i+n][i] = 1;
        }
        for(int i = 0; i<e; ++i) {
            int st, tg;
            cin >> st >> tg;
            rList[st+n].push_back(tg);
            rList[tg+n].push_back(st);

            rMatrix[st+n][tg] = 1;
            rMatrix[tg+n][st] = 1;
        }
        for(int i = 0; i < x; ++i) {
            int ex;
            cin >> ex;
            rList[rList.size()-2].push_back(ex);
            rMatrix[rList.size()-2][ex] = 1;

        }
        for(int i = 0; i<p; ++i) {
            int pw;
            cin >> pw;
            rList[pw+n].push_back(rList.size()-1);
            rMatrix[pw+n][rList.size()-1] = 1;

        }
        int fl;
        fl = maxFlow(rList, rMatrix, rList.size()-2, rList.size()-1);
        cout << fl << endl;
    }
}
