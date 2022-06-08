#include <bits/stdc++.h>

using namespace std;

bool circle;

void visit(int v, vector<bool> &visited, vector<vector<int>> list) {
    visited[v] = true;
    for (int w: list[v]) {
        if (!visited[w]) {
            visit(w, visited, list);
        }
    }
}


int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int n, h;
        cin >> n >> h;
        vector<vector<int>> list(n);
        vector<int> listR(n);
        for (int j = 0; j < h; ++j) {
            int x, y;
            cin >> x >> y;
            list[x - 1].push_back(y - 1);
            listR[y - 1] += 1;
        }
        queue<int> src;
        vector<int> sort;
        vector<int> nb;
        bool wrong = false;
        for (int j = 0; j < listR.size(); ++j) {
            if (listR[j] == 0) {
                src.push(j);
                sort.push_back(j);
            }
        }
        while (!src.empty()) {
            if(src.size()>1) {
                wrong = true;
            }
            int v = src.front();
            src.pop();
            for(int j = 0; j<list[v].size(); ++j) {
                listR[list[v][j]] -=1;
                if(listR[list[v][j]]== 0) {
                    src.push(list[v][j]);
                    sort.push_back(list[v][j]);
                }
            }

        }

        bool amb = false;
        for (int j = 0; j < listR.size(); ++j) {
            if (listR[j] > 0) {
                amb = true;
            }
        }
        if (wrong && !amb) {
            cout << "missing hints" << "\n";
        } else if (amb) {
            cout << "recheck hints" << "\n";
        } else {
            for (int j = 0; j < sort.size(); ++j) {
                cout << sort[j] + 1 << " ";
            }
            cout << "\n";
        }

    }
}
