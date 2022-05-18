#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, m;
    cin >> c >> m;

    vector<vector<int>> pr(m);
    for(int i = 0; i<m; ++i) {
        for(int j = 0; j<c; ++j) {
            int p;
            cin >> p;
            pr[i].push_back(p);
        }
    }

    vector<vector<int>> val(m+1);
    for(int i = 0; i<m+1; ++i) {
        for(int j = 0; j<c+1; ++j) {
            val[i].push_back(0);
        }
    }


    for(int i = 1; i<val.size(); ++i) {
        for(int j = 1; j<val[i].size(); ++j) {
            int maxV = 0;
            val[i][j] = pr[i-1][j-1];
            for(int x = 0; x <=j-1; ++x) {
                int maxVv = max(val[i][j-x], val[i-1][x]);
                maxV = max(maxV, maxVv);
            }
            val[i][j] = maxV;
        }
    }
    cout << val[m][c] << "\n";
}
