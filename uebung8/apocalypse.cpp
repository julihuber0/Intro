#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
int INF = INT32_MAX;

bool bfs(vector<vector<pi>> list, int s, int t, vector<pi> &parent) {
    int n = list.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (pi w: list[v]) {
            if (!visited[w.first] && w.second > 0) {
                if (w.first == t) {
                    parent[w.first] = make_pair(v, w.second);
                    return true;
                }
                q.push(w.first);
                parent[w.first] = make_pair(v, w.second);
                visited[w.first] = true;
            }
        }
    }
    return false;
}

int maxFlow(vector<vector<pi>> &resList, int s, int t) {
    vector<pi> parent(resList.size());
    int max = 0;
    while (bfs(resList, s, t, parent)) {
        int path = INF;
        for (int v = t; v != s; v = parent[v].first) {
            path = min(path, parent[v].second);
        }
        for (int v = t; v != s; v = parent[v].first) {
            int u = parent[v].first;
            for (int i = 0; i < resList[u].size(); ++i) {
                if (resList[u][i].first == v) {
                    resList[u][i].second -= path;
                }
            }
            for (int i = 0; i < resList[v].size(); ++i) {
                if (resList[v][i].first == u) {
                    resList[v][i].second += path;
                }
            }
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
        vector<vector<pi>> rl(n+1);
        vector<int> bunkers;
        for(int j = 0; j<b; ++j) {
            int bk;
            cin >> bk;
            rl[bk].push_back(make_pair(n, INF));
            rl[n].push_back(make_pair(bk, 0));
        }
        for(int j = 0; j<m; ++j) {
            int x, y, w;
            cin >> x >> y >> w;
            rl[x].push_back(make_pair(y, w));
            rl[y].push_back(make_pair(x, 0));
        }
        int me = maxFlow(rl, 0, n);
        cout << me << "\n";
    }
}
