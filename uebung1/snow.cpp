#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

set<int64_t> fl;
vector<int64_t> flakes;


int main() {
    int64_t cases;
    cin >> cases;

    priority_queue<int64_t> sizes;


    for(int64_t i = 0; i < cases; ++i) {
        int64_t c;
        cin >> c;
        if(c == 1) {
            sizes.push(1);
        }
        for(int64_t j = 0; j<c; ++j) {
            int64_t f;
            cin >> f;
            flakes.push_back(f);
        }
        int64_t left = 0;
        for(int j = 0; j<flakes.size(); ++j) {

            unsigned int size = fl.size();
            fl.insert(flakes[j]);
            unsigned int sn = fl.size();
            if(size == sn) {
                sizes.push(sn);
                bool found = false;
                while(!found) {
                    fl.erase(flakes[left]);
                    left += 1;
                    unsigned ts = fl.size();
                    fl.insert(flakes[j]);
                    if(ts < fl.size()) {
                        found = true;
                    }
                }

            }
            if(j == c-1) {
                sizes.push(j-left+1);
            }
        }

        cout << sizes.top() << "\n";
        sizes = priority_queue<int64_t>();
        flakes.clear();
        fl.clear();
    }


}
