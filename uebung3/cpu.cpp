#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, m;
    cin >> c >> m;

    vector<vector<int>> pr(m + 1);
    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < c + 1; ++j) {
            if (i == 0 || j == 0) {
                pr[i].push_back(0);
            } else {
                int p;
                cin >> p;
                pr[i].push_back(p);
            }
        }
    }

    vector<vector<int>> val(m + 1);
    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < c + 1; ++j) {
            val[i].push_back(0);
        }
    }


    for (int i = 1; i < val.size(); ++i) {
        for (int j = 1; j < val[i].size(); ++j) {
            int maxV = 0;
            val[i][j] = pr[i - 1][j - 1];
            for (int x = 0; x <= j; ++x) {
                maxV = max(pr[i][j - x] + val[i - 1][x], maxV);
            }
            val[i][j] = maxV;
        }
    }
    cout << val[m][c] << "\n";
}
