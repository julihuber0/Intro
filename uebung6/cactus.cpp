#include <bits/stdc++.h>

using namespace std;


void visit(int64_t v, vector<bool> &visited, vector<vector<int64_t>> list, vector<int64_t> &d, int64_t dist, int64_t &vol) {
    visited[v] = true;
    d[v] = dist;
    for (int64_t w: list[v]) {
        if (!visited[w]) {
            visit(w, visited, list, d, dist+1, vol);
        } else if(d[w]<dist-1){
            vol = vol + ((dist+1)-d[w])*((dist+1)-d[w]);
        }
    }
}

int main() {
    int64_t cases;
    cin >> cases;

    for(int64_t i = 0; i<cases; ++i) {
        int64_t n, m;
        cin >> n >> m;
        vector<vector<int64_t>> list(n);
        vector<int64_t> dist(n);
        int64_t vol = 0;
        for(int j = 0; j < m; ++j) {
            int64_t x, y;
            cin >> x >> y;
            list[x].push_back(y);
            list[y].push_back(x);
        }
        vector<bool> visited(n, false);
        vector<bool> branch(n, false);
        visit(0, visited, list, dist, 0, vol);
        cout << vol << "\n";
    }
}
