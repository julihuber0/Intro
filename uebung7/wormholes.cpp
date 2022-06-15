#include <bits/stdc++.h>

using namespace std;

typedef pair<int64_t, int64_t> pi;
int INF = INT32_MAX;

bool circle;

void visit(int64_t v, vector<bool> &visited, vector<vector<pi>> &adj_list, vector<int64_t> &age, int64_t a) {
    visited[v] = true;
    age[v] = a;
    for (pi w: adj_list[v]) {
        if (!visited[w.first]) {
            visit(w.first, visited, adj_list, age, a + w.second);
        } else if (age[w.first] > a + w.second) {
            circle = true;
        }
    }
}

vector<int64_t> dijkstra(int64_t s, vector<vector<pi>> adj_list, vector<int> &visited, vector<int> &deg) {
    vector<int64_t> d(adj_list.size(), INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        pi p = pq.top();
        pq.pop();
        if(p.first == d[p.second]) {
            for(pi y:adj_list[p.second]) {
                if(d[y.first]>d[p.second]+y.second) {
                    if(visited[y.first]>deg[y.first]+3) {
                        circle = true;
                        return d;
                    }
                    d[y.first] = d[p.second]+y.second;
                    pq.push(make_pair(d[y.first], y.first));
                    visited[y.first] += 1;
                }
            }
        }
    }
    return d;
}

int main() {
    int64_t cases;
    cin >> cases;
    for (int64_t i = 0; i < cases; ++i) {
        int64_t n, m;
        cin >> n >> m;
        vector<vector<pi>> adj_list(n);
        vector<int64_t> age(n);
        vector<int> deg(n, 0);
        if (m == 0) {
            cout << "not possible" << endl;
        } else {
            for (int64_t j = 0; j < m; ++j) {
                int64_t x, y, w;
                cin >> x >> y >> w;
                adj_list[x].push_back(make_pair(y, w));
                deg[y] +=1;
            }
            circle = false;
            vector<int> visited(n, 0);
            dijkstra(0, adj_list, visited, deg);
            if(circle) {
                cout << "possible" << endl;
            } else {
                cout << "not possible" << endl;
            }

        }
    }
}
