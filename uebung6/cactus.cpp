#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> l;
vector<int> d;
int vol = 0;


void visit(int v, vector<bool> &visited, int dist) {
    visited[v] = true;
    d[v] = dist;
    for (int w: l[v]) {
        if (!visited[w]) {
            visit(w, visited, dist+1);
        } else if(d[w]<dist-1){
            vol = vol + ((dist+1)-d[w])*((dist+1)-d[w]);
        }
    }
}

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i<cases; ++i) {
        int n, m;
        cin >> n >> m;
        l.clear();
        l.resize(n);
        d.clear();
        d.resize(n);
        vol = 0;
        for(int j = 0; j < m; ++j) {
            int x, y;
            cin >> x >> y;
            l[x].push_back(y);
            l[y].push_back(x);
        }
        vector<bool> visited(n, false);
        visit(0, visited, 0);
        cout << vol << "\n";
    }
}
