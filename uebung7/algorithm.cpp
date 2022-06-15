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

int find(int x, vector<int> &parent) {
    if(parent[x] == -1) {
        return x;
    }
    parent[x] = find(parent[x], parent);
    return parent[x];
}

bool makeUnion(int a, int b, vector<int> &parent, vector<int> &rank) {
    int x = find(a, parent);
    int y = find(b, parent);
    if(x!=y) {
        if(rank[x] > rank[y]) {
            parent[y] = x;
        } else if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y] = rank[y] + 1;
        }
    }
    return true;
}

bool isSame(int x, int y, vector<int> &parent) {
    return find(x, parent) == find(y, parent);
}

struct wEdge{
    int x;
    int y;
    int w;
};

bool kleiner(const wEdge &w1, const wEdge &w2) {
    if(w1.w<w2.w) {
        return true;
    } else {
        return false;
    }
}

bool mst(vector<wEdge> &edges, int n) {
    vector<int> parent(n, -1);
    vector<int> rank(n, 0);
    int mst_weight = 0;
    for(wEdge w:edges) {
        if(!isSame(w.x, w.y, parent)) {
            makeUnion(w.x, w.y, parent, rank);
            mst_weight += w.w;
        }
    }
}

int main(){
    vector<int> parent(4, -1);
    vector<int> rank(4, 0);
    makeUnion(0, 1, parent, rank);
    makeUnion(1, 2, parent, rank);
    bool qu = isSame(0, 2, parent);
    if(qu) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    qu = isSame(1, 3, parent);
    if(qu) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}
