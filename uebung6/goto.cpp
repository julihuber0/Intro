#include <bits/stdc++.h>

using namespace std;

set<int> bfs(vector<vector<int>> list, vector<int> master) {
    int INF = INT32_MAX;
    queue<int> q;
    vector<int> dist(list.size(), INF);
    set<int> n;
    for(int i = 0; i<master.size(); ++i) {
        q.push(master[i]);
        n.insert(master[i]);
        dist[master[i]] = 0;
    }

    //n.insert(s);
    //dist[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int w : list[v]) {
            if (dist[w] == INF) {
                n.insert(w);
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }
    }
    return n;
}

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i<cases; ++i) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<vector<int>> list(n);
        vector<int> master;
        set<int> nodes;
        for(int j = 0; j<m; ++j) {
            int x, y;
            cin >> x >> y;
            list[x-1].push_back(y-1);
        }
        for(int j = 0; j<l; ++j) {
            int m;
            cin >> m;
            master.push_back(m-1);
        }
        nodes = bfs(list, master);
        cout << nodes.size() << "\n";
    }
}
