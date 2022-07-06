#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int t = 0; t<cases; ++t) {
        int k;
        cin >> k;
        vector<int> jugs;
        for(int i = 0; i<k; ++i) {
            int j;
            cin >> j;
            jugs.push_back(j);
        }
        int r = 0;
        for(int i = 0; i<k; ++i) {
            int c;
            cin >> c;
            r = r^(c%(jugs[i]+1));
        }
        if(r!=0) {
            cout << "Win" << endl;
        } else {
            cout << "Lose" <<endl;
        }
    }
}
