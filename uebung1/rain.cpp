#include <bits/stdc++.h>

using namespace std;



struct Elem {
    char s;
    int x;
};
stack<Elem> elems;

int main() {
    int cases;
    cin >> cases;
    int depth;
    int rain = 0;

    for(int i = 0; i<cases; ++i) {
        string map;
        cin >> map;
        for(int j = 0; j<map.size(); ++j) {
            Elem e;
            e.s = map[j];
            e.x = j;
            if (map[j] == '/' && elems.empty()) {
                elems.push(e)
            }
            if(map[j] == '\\') {
                elems.push(e);
                depth += 1;
            }
            if(map[j] = '/') {

            }
        }
    }

}
