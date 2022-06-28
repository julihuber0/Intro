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

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(pi w : list[v]) {
            if (!visited[w.first] && w.second>0) {
                if(w.first == t){
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
    while(bfs(resList, s, t, parent)) {
        int path = INF;
        for(int v = t; v != s; v = parent[v].first) {
            path = min(path, parent[v].second);
        }
        for(int v = t; v != s; v = parent[v].first) {
            int u = parent[v].first;
            for(int i = 0; i<resList[u].size(); ++i) {
                if(resList[u][i].first == v) {
                    resList[u][i].second -= path;
                }
            }
            for(int i = 0; i<resList[v].size(); ++i) {
                if(resList[v][i].first == u) {
                    resList[v][i].second += path;
                }
            }
        }
        max += path;
    }
    return max;
}

int main() {
   vector<vector<pi>> rl(6);
   rl[0].push_back(make_pair(1,5));
   rl[1].push_back(make_pair(0, 0));
   rl[0].push_back(make_pair(2, 4));
   rl[2].push_back(make_pair(0, 0));
    rl[1].push_back(make_pair(3, 6));
    rl[3].push_back(make_pair(1, 0));
    rl[2].push_back(make_pair(1, 3));
    rl[1].push_back(make_pair(2, 0));
    rl[2].push_back(make_pair(4, 2));
    rl[4].push_back(make_pair(2, 0));
    rl[3].push_back(make_pair(5, 5));
    rl[5].push_back(make_pair(3, 0));
    rl[4].push_back(make_pair(3, 8));
    rl[3].push_back(make_pair(4, 0));
    rl[4].push_back(make_pair(5, 2));
    rl[5].push_back(make_pair(4, 0));
    int n = maxFlow(rl, 0, 5);
    cout << n << "\n";
}
