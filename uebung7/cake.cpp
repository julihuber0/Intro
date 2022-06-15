#include <bits/stdc++.h>

using namespace std;

typedef pair<int64_t, int64_t> pi;

int find(int64_t x, vector<int64_t> &parent) {
    if(parent[x] == -1) {
        return x;
    }
    parent[x] = find(parent[x], parent);
    return parent[x];
}

bool makeUnion(int64_t a, int64_t b, vector<int64_t> &parent, vector<int64_t> &rank) {
    int64_t x = find(a, parent);
    int64_t y = find(b, parent);
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

bool isSame(int64_t x, int64_t y, vector<int64_t> &parent) {
    return find(x, parent) == find(y, parent);
}

struct wEdge{
    int64_t x;
    int64_t y;
    int64_t w;
};

bool kleiner(const wEdge &w1, const wEdge &w2) {
    if(w1.w>w2.w) {
        return true;
    } else {
        return false;
    }
}

vector<vector<pi>> mst(vector<wEdge> &edges, int64_t n) {
    vector<int64_t> parent(n, -1);
    vector<int64_t> rank(n, 0);
    vector<vector<pi>> nList(n);
    int64_t mst_weight = 0;
    for(wEdge w:edges) {
        if(!isSame(w.x, w.y, parent)) {
            makeUnion(w.x, w.y, parent, rank);
            mst_weight += w.w;
            nList[w.x].push_back(make_pair(w.y, w.w));
            nList[w.y].push_back(make_pair(w.x, w.w));
        }
    }
    return nList;
}

void visit(int64_t v, vector<bool> &visited, vector<vector<pi>> list, vector<pi> &src) {
    visited[v] = true;
    for (pi w: list[v]) {
        if (!visited[w.first]) {
            src[w.first].first = v;
            src[w.first].second = w.second;
            visit(w.first, visited, list, src);
        }
    }
}

int main() {
    int64_t q, n, m;
    cin >> q >> n >> m;
    vector<pi> orders;
    for (int64_t i = 0; i < q; ++i) {
        int64_t x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        orders.push_back(make_pair(x, y));
    }
    vector<vector<pi>> adj_list;
    vector<wEdge> edges;
    for(int64_t i = 0; i<m; ++i) {
        int64_t x, y, w;
        cin >> x >> y >> w;
        x -= 1;
        y -= 1;
        //adj_list[x].push_back(make_pair(y, w));
        //adj_list[y].push_back(make_pair(x, w));
        wEdge w1;
        w1.x = x;
        w1.y = y;
        w1.w = w;
        wEdge w2;
        w2.x = y;
        w2.y = x;
        w2.w = w;
        edges.push_back(w1);
        edges.push_back(w2);
    }
    sort(edges.begin(), edges.end(), kleiner);
    adj_list = mst(edges, n);
    for(int64_t i = 0; i<orders.size(); ++i) {
        vector<bool> visited(n, false);
        int f = INT32_MAX;
        vector<pi> src(n, make_pair(-1, INT32_MAX));
        visit(orders[i].first, visited, adj_list, src);
        int64_t minF = INT64_MAX;

        int cur = orders[i].second;
        while(src[cur].first>-1) {
            if(minF>src[cur].second) {
                minF = src[cur].second;
            }
            cur = src[cur].first;
        }
        if(minF < INT32_MAX) {
            cout << minF << endl;
        } else {
            cout << "0" << endl;
        }
        minF = INT32_MAX;
    }


}
