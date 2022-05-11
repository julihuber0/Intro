#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i< cases; ++i) {
        int barbers;
        cin >> barbers;
        int place;
        cin >> place;

        vector<int> min;
        for(int j = 0; j<barbers; ++j) {
            int m;
            cin >> m;
            min.push_back(m);
        }
        vector<int> map;
        for(int j = 0; j<place; ++j) {
            map.push_back(-1);
        }

        int passed = 0;
        int curCust = 0;
        while(true) {
            for(int j = 0; j< barbers; j++) {
                if(passed%min[j]==0) {
                    map[curCust] = j+1;
                    curCust += 1;
                }
            }
            passed += 1;
            if(map[place-1] != -1) {
                cout << map[place-1] << "\n";
                break;
            }
        }
    }
}
