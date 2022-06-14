#include <bits/stdc++.h>

using namespace std;

int INF = INT32_MAX;
typedef pair<int64_t, int64_t> pi;

vector<int> dijkstra(vector<vector<pi>> &list, int s) {
    vector<int> d(list.size(), INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        pi p = pq.top();
        pq.pop();
        if(p.first == d[p.second]) {
            for(pi y:list[p.second]) {
                if(d[y.first]>d[p.second]+y.second) {
                    d[y.first] = d[p.second]+y.second;
                    pq.push(make_pair(d[y.first], y.first));
                }
            }
        }
    }
    return d;
}

int main(){}
