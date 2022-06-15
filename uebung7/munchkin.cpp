#include <bits/stdc++.h>

using namespace std;

int INF = INT32_MAX;
typedef pair<int64_t, int64_t> pi;
vector<vector<pi>> adj_list;

vector<int> dijkstra(int s) {
    vector<int> d(adj_list.size(), INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        pi p = pq.top();
        pq.pop();
        if(p.first == d[p.second]) {
            for(pi y:adj_list[p.second]) {
                if(d[y.first]>d[p.second]+y.second) {
                    d[y.first] = d[p.second]+y.second;
                    pq.push(make_pair(d[y.first], y.first));
                }
            }
        }
    }
    return d;
}

int main() {
    int classes;
    cin >> classes;
    vector<pi> cl;
    for(int i = 0; i< classes; ++i) {
        int d, c;
        cin >> d >> c;
        cl.push_back(make_pair(d, c));
    }
    int edges;
    cin >> edges;
    adj_list.resize(classes);
    for(int i = 0; i<edges; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        c1 -= 1;
        c2 -= 1;
        int64_t diff = (cl[c1].first-cl[c2].first)*(cl[c1].first-cl[c2].first)+(cl[c1].second-cl[c2].second)*(cl[c1].second-cl[c2].second);
        adj_list[c1].push_back(make_pair(c2, diff));
        adj_list[c2].push_back(make_pair(c1, diff));
    }
    int q;
    cin >> q;
    for(int i = 0; i<q; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        c1 -=1;
        c2 -=1;
        vector<int> d = dijkstra(c1);
        if(d[c2]<INF) {
            cout << d[c2] << endl;
        } else {
            cout << "BRIBE DM WITH FOOD" << endl;
        }
    }
}
