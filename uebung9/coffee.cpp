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
        vector<int> coffee;
        for(int i = 0; i<k; ++i) {
            int c;
            cin >> c;
            coffee.push_back(c);
        }
    }
}
