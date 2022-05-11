#include <bits/stdc++.h>

using namespace std;




int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i<cases; ++i) {
        stack<int> map;
        string m;
        cin >> m;
        int water = 0;
        for(int i = 0; i<m.size(); ++i) {
            char c = m[i];
            if(c == '/') {
                if(!map.empty()) {
                    int l = map.top();
                    map.pop();
                    water += (i-l);
                }
            } else if(c == '\\') {
                map.push(i);
            }
        }
        cout << water << "\n";
    }

}
